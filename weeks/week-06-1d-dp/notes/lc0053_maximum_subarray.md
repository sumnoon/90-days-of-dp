# ⭐ LC 53: Maximum Subarray, four versions

- **Solution:** [`solutions/lc0053_maximum_subarray.cpp`](../solutions/lc0053_maximum_subarray.cpp)
- **Day:** 36 (Week 6 Mon), solved on Wed 28 Oct
- **Solved without help?** Kadane, the table and the memoized version, yes.
  The plain recursion needed a hint (a trace of `[5, -10, 1]`), so it's on the
  [redo list](../../../redo-list.md).

Find the largest sum of a non-empty run of neighbouring numbers.

## State

`dp[i]` = **the largest sum of a subarray that ends exactly at index `i`**.

The answer is *not* `dp[n − 1]`: the best subarray can end anywhere. It's the
largest `dp[i]` over every `i`.

## Transition

```cpp
dp[i] = max(nums[i], dp[i - 1] + nums[i]);
```

A subarray ending at `i` either **starts fresh at `i`**, or **extends the best
one ending at `i − 1`**. Extending only helps when `dp[i − 1] > 0`; otherwise
the old run is dead weight and you start over.

## Base case

`dp[0] = nums[0]`: the only subarray ending at index 0 is `[nums[0]]`.

## Four versions

- **`calcRecurse`:** returns `dp[idx]` and records the overall best in
  `global_max` on the way back up. Each call makes **one** call, so it's
  already O(n) without a cache: there are no overlapping subproblems when only
  one recursion is started.
- **`calcMemo`:** the same `dp[idx]`, cached in `memo` with `visited`. The
  cache matters when the caller asks for *every* `idx` (as it must, to take
  the max): without it, each of the n calls would walk the chain down to 0
  again, O(n²).
- **`calcTab`:** fill `dp[0]`, `dp[1]`, … in order and keep the max as you go.
  This is the form the plan asks for.
- **`maxSubArray` (submitted), Kadane:** `calcTab` with the table squeezed into
  one variable. `sum` is `dp[i − 1]` clamped at 0: resetting `sum` to 0 when it
  goes negative is the same choice as `max(nums[i], dp[i − 1] + nums[i])`.
  `ans` is updated *before* the reset, so an all-negative array still returns
  its largest number, not 0.

## The bug in the first `calcRecurse`

It returned `max(global_max, best)` instead of `best`. The caller then added
`nums[idx]` to the overall best so far, which may end well before `idx − 1`,
gluing two pieces with a gap between them. On `[5, -10, 1]`:

- `calcRecurse(1)` worked out `best = −5`, but returned 5 (the global best);
- `calcRecurse(2)` computed `1 + 5 = 6`, skipping the −10. The answer is 5.

It failed 1,025 of 2,000 random arrays. The fix keeps the two meanings apart:
**return** the best *ending here*, **record** the best *anywhere* in
`global_max`. Writing the state in one sentence first, this week's checkpoint,
catches exactly this mix-up.

## Small notes on the code

- `global_max` isn't initialised in the class, so the caller has to set it to
  `INT_MIN` before calling `calcRecurse`; the test does.
- `calcRecurse` is one call deep per index. On Windows' default 1 MB stack at
  `-O0` it ran at n = 20,000 and crashed at 50,000; LeetCode allows 100,000.
  `calcTab` and `maxSubArray` have no such limit.
- `int memo[100010]` makes each `Solution` 400 KB, too big to create as a local
  variable on Windows. The test allocates it with `make_unique`.
- `maxSubArray` compares `int i` with `nums.size()` (`-Wall`).

## Complexity

O(n) time for all four. O(n) space for the recursion, memo and table; O(1)
for Kadane.

## Tested

- LeetCode's three examples
- small cases: `[-1]`, `[-3, -1, -2]` (all negative), `[5, -10, 1]` and
  `[0, 0]`
- 2,000 random arrays of 1–12 numbers from −10 to 10
- LeetCode's limits: 100,000 copies of −10,000 (Kadane and the table)

All four versions were checked against a brute force that tries every
subarray.

## Key insight

Define the state as the best subarray *ending at* `i`: then it either starts fresh or extends `dp[i − 1]`, and the answer is the max over all `i`. Kadane is that table kept in one variable.
