# LC 354: Russian Doll Envelopes (stretch)

- **Solution:** [`solutions/lc0354_russian_doll_envelopes.cpp`](../solutions/lc0354_russian_doll_envelopes.cpp)
- **Day:** 42 (Week 6 Sun), solved on Mon 23 Nov
- **Solved without help?** yes

An envelope fits inside another only if it's strictly smaller in **both**
width and height. Find the most envelopes you can nest one inside the next.

## The idea: sort away one dimension, then LIS on the other

After sorting by width, any nesting chain appears in that order, so what's left
is a strictly increasing subsequence of **heights**: [LC 300](lc0300_longest_increasing_subsequence.md),
solved with the O(n log n) smallest-tail list.

## The tie-break that makes it work

```cpp
if (a[0] == b[0]) return a[1] > b[1];   // equal widths: taller first
return a[0] < b[0];                      // otherwise: narrower first
```

Two envelopes with the **same width** can't nest. Sorted with heights rising,
`[1, 3]` then `[1, 4]` would look like an increasing pair of heights, and the
LIS would count both. Sorting equal widths by height **falling** puts the
taller one first, so no increasing pair can come from a single width. The LIS
then picks at most one envelope per width, which is exactly the rule.

## State

`memo[k]` = **the smallest height that can end a nesting chain of `k + 1`
envelopes**, among the envelopes seen so far. It's LC 300's list, with heights
in place of values.

## Complexity

Sorting plus one binary search per envelope: **O(n log n)** time, O(n) space.
An O(n²) LIS would be 10¹⁰ steps at LeetCode's 100,000 envelopes, far too
slow, so the binary-search version is needed here. 100,000 envelopes took 14 ms.

## Small notes on the code

- `lower_bound` (first `>=`) keeps the heights **strictly** increasing, as in
  LC 300, so equal heights can't both be taken either.
- The comparator takes `const vector<int>&`, so sorting copies nothing.
- `i < envelopes.size()` compares `int` with `size_t` (`-Wall`).

## Tested

- LeetCode's two examples
- `[[1, 1]]`, all equal widths (`[[1, 2], [1, 3], [1, 4]]` gives 1), and two
  mixed cases with repeated widths
- 3,000 random cases of 1–30 envelopes with sides 1–8, so lots of equal widths
  and heights
- LeetCode's limit: 100,000 envelopes `[i, i]`, shuffled, which all nest

The small cases were checked against an O(n²) table that compares both sides
directly.

## Key insight

Sort by width, with equal widths taller first, and the problem becomes LIS on the heights; the tie-break stops two envelopes of the same width from both being counted.
