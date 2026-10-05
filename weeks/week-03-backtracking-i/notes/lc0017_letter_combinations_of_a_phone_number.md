# LC 17: Letter Combinations of a Phone Number

- **Solution:** [`solutions/lc0017_letter_combinations_of_a_phone_number.cpp`](../solutions/lc0017_letter_combinations_of_a_phone_number.cpp)
- **Day:** 17 (Wed)
- **Solved without help?** yes, after working out the three framing questions first (depth, pruning, what each level loops over)

## What the call does

`backtrack(idx, cur, digits)` appends every string that starts with `cur`
and continues with one letter for each of `digits[idx]`, `digits[idx + 1]`, …

**Returns** nothing. **Passes down** `idx`, which digit this level decides,
and `cur`, the letters chosen so far.

## Recursive case

```cpp
for (auto c : mapper[digits[idx] - '2']) {
    cur.push_back(c);
    backtrack(idx + 1, cur, digits);
    cur.pop_back();
}
```

Each level is one digit; its children are that digit's letters. `'2'` is the
first key with letters, so `digits[idx] - '2'` turns the digit into an index
into `mapper`, where `7` and `9` have four letters each.

## Base case

```cpp
if (cur.size() == digits.size()) { ans.push_back(cur); return; }
```

The tree is exactly `digits.size()` levels deep: one letter per digit, then
record and stop.

**Empty input:** with `digits = ""` that condition is already true at the
first call, which would record `""` and return `[""]`. LeetCode wants `[]`,
so `letterCombinations` returns early for the empty string. That check is
needed, not just defensive.

## Nothing to prune

Every digit has at least three letters, so every branch reaches full length
and every leaf is an answer. The number of answers is the product of the
letter counts: 3 × 3 = 9 for `"23"`, 4 × 4 = 16 for `"79"`. Compare LC 77,
where most of the unpruned tree was waste.

## Small notes on the code

- `cur` and `digits` are taken **by value**, so every call gets its own copy
  of both. It's still correct: whatever a child does to its copy never comes
  back. The `pop_back` is still needed, though: this call's own `cur` is
  reused for the next letter of its loop. Measured: with the pop removed,
  `"23"` records `ad`, then the next call gets `"ade"`. That is longer than
  the input, so `cur.size() == digits.size()` never fires again, the code reads
  past the end of `digits`, and it crashes. The cost of passing by value is two
  string copies per call.
  Taking `string& cur` and `const string& digits` removes them, and makes it
  the same shared-state pattern as LC 77.
- `ans` is a member that's never cleared, as in LC 77 and LC 78.

## Complexity

Time: **O(n · 4ⁿ)** in the worst case, where n = `digits.size()`: up to 4ⁿ
strings of length n. With n ≤ 4, at most 256 strings.
Space: **O(n)** stack, plus the output (and, with by-value strings, a copy of
`cur` and `digits` in every frame).

## Tested

`"23"`, `""`, `"2"`, `"79"`, `"7"`, `"234"`, `"9999"` (the longest allowed)
and `"2345"`: each matches a reference that builds the answers one digit at
a time, in the same order, with no duplicates.

## Key insight

One level per digit, one branch per letter: the depth is the input length, and every leaf is an answer.
