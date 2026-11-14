# ⭐ LC 139: Word Break, memoized and table

- **Solution:** [`solutions/lc0139_word_break.cpp`](../solutions/lc0139_word_break.cpp)
- **Day:** 39 (Week 6 Thu), solved on Sun 15 Nov
- **Solved without help?** The memoized version, yes. The table read one slot
  past the end of `memo`; it was fixed after a hint, so it's on the
  [redo list](../../../redo-list.md).

Can `s` be split into words from `wordDict`, each word usable any number of
times?

## State

`calc(idx)` returns **whether `s[0..idx]` can be split into dictionary
words**. The answer is `calc(n − 1)`.

## Transition

Split on the **last word**. If some word ends exactly at `idx` and what comes
before it can be split, then so can `s[0..idx]`:

```cpp
if (s.substr(idx - wSize + 1, wSize) == word && calc(idx - wSize, s, wordDict))
```

Any one word that works is enough, so it returns `true` as soon as one does.
Compare LC 322, which takes a `min` over every choice: here the choices are
combined with **or**.

## Base case

`idx < 0`: nothing left before the first word, which is an empty prefix, and
that always splits. So return `true`.

## Table

`memo[i]` = **whether the first `i` characters can be split**: the same
question, counted by length instead of by last index, so `memo[0] = true` is
the empty prefix and the answer is `memo[n]`.

```cpp
if (i >= wSize && memo[i - wSize] && s.substr(i - wSize, wSize) == word)
```

`memo[i - wSize]` is filled before `memo[i]`, so filling left to right works.

**The bug, fixed after a hint:** `memo` was created with `s.length()` slots,
but the indices run 0 to `n`, so it needs `n + 1`. Writing and returning
`memo[n]` was one past the end. With bounds checking on it aborted on the
first test. Without bounds checking it can pass by luck, because
`vector<bool>` packs values into bits. A table counted by **length** needs
one slot more than the string.

## Two versions, one class

| Call | Version |
|---|---|
| `wordBreakMemo(s, wordDict)` | memoized; sizes `memo` itself |
| `wordBreak(s, wordDict)` | the table (submitted) |

## Complexity

n positions × d words, and each check copies up to w characters with
`substr`: **O(n · d · w)**. At LeetCode's limits that's 300 × 1,000 × 20.

## Small notes on the code

- `calc` takes `string s` by value, so every call copies the string.
  `const string& s` avoids that.
- `for (string word : wordDict)` copies each word; `const string& word`
  doesn't.
- `s.compare(start, len, word) == 0` checks a word without building a
  substring.
- The table's local `memo` hides the class member `memo` (`-Wshadow`). That's
  harmless, but a different name would be clearer.
- `if (memo[idx] != -1) return memo[idx];` returns an `int` as a `bool`, which
  works because only 0 and 1 are stored.

## Tested

- LeetCode's three examples
- `"a"` with `["a"]` and with `["b"]`, `"aaaaaaa"` with `["aaaa", "aaa"]`,
  `"cars"` with `["car", "ca", "rs"]`
- 3,000 random cases: strings of `a`/`b` up to 20 long, 1–5 words of length
  1–4
- LeetCode's limit: 299 `a`s and a `b`, and 300 `a`s, with the words `a` to
  `aaaaaaaaaa`

Both versions were checked against a separate forward fill of reachable split
points.

## Key insight

Split on the last word: `s[0..idx]` works if some word ends at `idx` and the part before it works. Counted by length, the table needs `n + 1` slots, with `memo[0] = true` for the empty prefix.
