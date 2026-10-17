# ⭐ LC 131: Palindrome Partitioning

- **Solution:** [`solutions/lc0131_palindrome_partitioning.cpp`](../solutions/lc0131_palindrome_partitioning.cpp)
- **Day:** 25 (Thu)
- **Solved without help?** yes
- **Video, after solving:** Striver's recursion playlist L17 (palindrome partitioning)

## What the call does

`backtrack(idx, s, cur)` records every way to cut `s[idx..]` into
palindromes, each appended to the pieces already in `cur`.

**Returns** nothing. **Passes down** where the next piece starts, and `cur`
by reference.

## Recursive case

```cpp
for (int i = idx; i < s.length(); ++i) {
    if (checkPalindrome(s, idx, i)) {
        cur.push_back(s.substr(idx, i - idx + 1));
        backtrack(i + 1, s, cur);
        cur.pop_back();
    }
}
```

The Week 3 template with the choice made of a **cut**: the next piece is
`s[idx..i]` for some `i`, and it's only a valid choice if that piece is a
palindrome. Then the rest, from `i + 1`, is the same problem again. Same shape
as LC 93, which chose 1–3 digits per part; here a piece can be any length,
and validity is "reads the same backwards" instead of "is 0–255".

## Base case

```cpp
if (idx == s.length()) { ans.push_back(cur); return; }
```

The whole string has been cut into palindromes. Every single letter is a
palindrome, so **every branch can always continue** and every leaf records:
no dead ends, nothing to prune. The work is all in the palindrome checks.

## The palindrome check

```cpp
while (l < r) if (s[l++] != s[r--]) return false;
return true;
```

The Week 1 two-pointer check, now as a loop. `s` is taken **by value**, so
each check copies the whole string; `const string&` would avoid it. With
`s.length() <= 16` it doesn't matter here.

## Overlapping work: a preview of DP

The same question, "is `s[l..r]` a palindrome?", is asked again and again
in different branches. For `"aaaa"`, `s[2..3]` is checked once under `[a, a]`
and again under `[aa]`. That's the overlapping-subproblems pattern from
Fibonacci: a table `isPal[l][r]`, filled once, would answer each in O(1).
Week 5 starts exactly there, and LC 132 (Palindrome Partitioning II, Week 10)
needs it.

## Complexity

The output dominates: up to **2ⁿ⁻¹** partitions (every gap cut or not), each
copied in O(n). Measured worst case at LeetCode's limit: 16 × `'a'` gives
**32,768** partitions in **27 ms**.
Space: **O(n)** for the stack and `cur`, plus the output.

## Small notes on the code

- `checkPalindrome(string s, …)` copies `s` on every call.
- `idx == s.length()` and `i < s.length()` compare `int` with an unsigned
  size (`-Wall`).
- `ans` is a member that's never cleared.

## Tested

LeetCode's two examples, `"ab"`, `"aaa"`, `"racecar"`, `"abba"`, `"abcba"`,
16 × `'a'`, and 300 random strings over `"ab"` / `"abc"` of up to 16 letters:
every result matches a brute force that tries all 2ⁿ⁻¹ cuttings and keeps the
all-palindrome ones.

## Key insight

Each level chooses where the next cut goes; a cut is only valid if the piece before it is a palindrome.
