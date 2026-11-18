# LC 1048: Longest String Chain

- **Solution:** [`solutions/lc1048_longest_string_chain.cpp`](../solutions/lc1048_longest_string_chain.cpp)
- **Day:** 41 (Week 6 Sat), solved on Thu 19 Nov
- **Solved without help?** yes

A word is a **predecessor** of another if adding exactly one letter anywhere
turns it into the other (`"ba"` → `"bda"`). Find the longest chain of words,
each a predecessor of the next.

## State

`memo[word]` = **the length of the longest chain that ends at `word`**: LC
300's "ending at `i`", with words in place of indices.

## Transition

Instead of checking every earlier word, as LC 300 does, look only at the words
that could come right before this one. Deleting each letter in turn gives all
`word.length()` candidates:

```cpp
string brokenWord = word.substr(0, i) + word.substr(i + 1);
if (memo.find(brokenWord) != memo.end())
    memo[word] = max(memo[word], memo[brokenWord] + 1);
```

A candidate counts only if it's in the list, which the hash map answers in one
lookup.

## Order

Sorting by **length** guarantees that every predecessor, one letter shorter,
has its value before the word that needs it, just as LC 300 fills index
`j < i` first. Words of the same length can't be each other's predecessors, so
their order doesn't matter.

## Base case

Every word alone is a chain of 1, so `memo[word] = 1` before its candidates
are checked.

## Answer

The longest chain can end at any word, so the answer is the largest value in
`memo`.

## Complexity

Sorting is O(n log n). Then each of the n words builds and looks up L
candidates of length L: **O(n log n + n · L²)**. Checking every pair, as LC
300 would, is O(n² · L). With n = 1,000 words of up to L = 16 letters, the
deletion version does far less work.

## Small notes on the code

- `for (const string word : words)` copies every word; `const string& word`
  doesn't (`-Wrange-loop-construct`).
- `for (auto value : memo)` copies each key too; `const auto& value` avoids
  that.
- `memo[word] = 1` would reset a repeated word, but it's computed again from
  the same predecessors, so the result doesn't change.

## Tested

- LeetCode's three examples
- `["a"]`, `["a", "a", "aa"]` (a repeated word) and `["ab", "a", "abc", "b"]`
- 2,000 random lists of 1–30 words over `a`, `b` and `c`, 1–6 letters long
- LeetCode's limit: 1,000 words of up to 16 letters, including a chain of 16

All checked against an LC 300-style table that tests every pair of words
directly.

## Key insight

It's LIS over words sorted by length, but instead of trying every earlier word, delete each letter to list the only possible predecessors and look them up in a hash map.
