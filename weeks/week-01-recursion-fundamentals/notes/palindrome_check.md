# Recursive palindrome check

- **Solution:** [`solutions/day1_palindrome_check.cpp`](../solutions/day1_palindrome_check.cpp)
- **Day:** 1 (Mon)
- **Solved without help?** hint (base case took three attempts)

## What the call returns

`check_palindrom(s, l, r)` — true if the slice `s[l..r]` reads the same
both ways.

## Recursive case

```cpp
if (s[l] == s[r]) return check_palindrom(s, l + 1, r - 1);
else              return false;
```

Compare the two ends. A mismatch answers the question immediately. A match
means the answer for the whole slice is the answer for the middle slice, so
hand that to the recursion and trust it.

## Base case

```cpp
if (r <= l) return true;
```

One condition covers three situations:

| Situation | How it stops | Example |
|---|---|---|
| Odd length | pointers meet, `l == r` | `"aba"` → `(1,1)` |
| Even length | pointers cross, `r < l` | `"abba"` → `(2,1)` |
| Empty string | starts already crossed | `""` → `(0,-1)` |

The pointers only *reach* a crossed state by matching at every step along
the way, so `true` is the only correct answer there.

## Complexity

Time: O(n) — one pair per call, n/2 pairs.
Space: O(n) for the call stack. An iterative two-pointer loop is O(1).

## Key insight

**Pass indices, don't build substrings.** `check_palindrom(s.substr(l+1, ...))`
copies the string at every level and turns an O(n) algorithm into O(n²).
Taking `const string& s` plus two ints means every frame looks at the same
one string.

## Mistakes I made

1. **`r < l` returned `false`.** Every odd-length palindrome passed and every
   even-length one failed, because odd lengths stop at `l == r` and never
   reach the crossed case. `"aa"`, `"abba"` and `""` were the tells.
2. **`r < l` returned `s[l-1] == s[r+1]`.** This re-checked a pair the
   previous call had already compared, so it was always true when reached —
   and on `""` it read `s[-1]` and crashed under `-D_GLIBCXX_ASSERTIONS`.

Both times the fix was to ask *what does reaching this state tell me?*
rather than *what should I compare here?*

## Related

Same two-pointer shape as [LC 344](lc0344_reverse_string.md), which swaps the
ends instead of comparing them.
