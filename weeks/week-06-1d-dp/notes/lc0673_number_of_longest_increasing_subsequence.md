# LC 673: Number of Longest Increasing Subsequence

- **Solution:** [`solutions/lc0673_number_of_longest_increasing_subsequence.cpp`](../solutions/lc0673_number_of_longest_increasing_subsequence.cpp)
- **Day:** 41 (Week 6 Sat), solved on Tue 17 Nov
- **Solved without help?** yes

Count how many strictly increasing subsequences have the greatest length.

## State

Two numbers for each index:

- `memo[i]` = **the length of the longest increasing subsequence ending at
  `i`**, as in [LC 300](lc0300_longest_increasing_subsequence.md);
- `count[i]` = **how many increasing subsequences of that length end at
  `i`**.

## Transition

For each earlier `j` with `nums[j] < nums[i]`, putting `nums[i]` after a
longest subsequence ending at `j` gives `count[j]` subsequences of length
`memo[j] + 1`:

- **longer** than the best so far for `i`: it's the new best, so `memo[i]`
  takes the new length and `count[i]` **resets** to `count[j]`;
- **the same length**: these are more ways to reach the best, so
  `count[i] += count[j]`;
- **shorter**: ignore it.

That reset is the step to watch. Counts from a shorter length must not carry
over once a longer one turns up.

## Base case

`nums[i]` on its own: length 1, one way. So both arrays start at 1.

## Answer

The longest length `ans` is the largest `memo[i]`. Then add up `count[i]` for
**every** `i` that reaches it. The longest subsequences can end at different
indices, and each is counted exactly once, by its last index.

## Complexity

Two nested loops: **O(n²)** time, O(n) space. LC 300's binary-search trick
doesn't carry over directly, because it keeps only one tail per length and
loses the counts.

## Small notes on the code

- `memo[i] = memo[i];` in the equal case does nothing and can go.
- The first loop runs to `i <= n`, setting one slot more than it uses.
- `int` is enough: LeetCode guarantees the answer fits, and the test used
  `-ftrapv`, which aborts on any signed overflow.

## Tested

- LeetCode's two examples
- `[1]`, `[1, 2]`, `[2, 1]`, `[3, 1, 2]`, `[1, 1, 2, 2]` and
  `[1, 2, 4, 3, 5, 4, 7, 2]`
- 2,000 random arrays of 1–16 numbers from −4 to 4, so lots of repeats and
  ties
- LeetCode's limit: 2,000 numbers made of 30 pairs `(2k, 2k − 1)` (2³⁰ longest
  subsequences) followed by decreasing numbers

All checked against a brute force that tries every subsequence.

## Key insight

Carry a count next to LC 300's "longest ending at `i`": a longer way in resets it, an equal one adds to it, and the answer sums the counts at every `i` that reaches the overall longest length.
