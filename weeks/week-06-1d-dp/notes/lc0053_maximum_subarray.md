# ⭐ LC 53: Maximum Subarray, five versions

- **Solution:** [`solutions/lc0053_maximum_subarray.cpp`](../solutions/lc0053_maximum_subarray.cpp)
- **Day:** 36 (Week 6 Mon), solved on Wed 28 Oct
- **Solved without help?** Kadane, the table, the memoized version and
  divide and conquer, yes.
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

## Five versions

Each one is a single call that takes `nums` and returns the answer, so it can
be run or submitted on its own:

| Call | Version |
|---|---|
| `recurse(nums)` | plain recursion: sets `global_max`, calls `calcRecurse(n − 1)` |
| `memoized(nums)` | sizes `memo` and `visited`, takes the max of `calcMemo(i)` over every `i` |
| `calcTab(nums)` | the table, sizing `memo` itself |
| `kadane(nums)` | Kadane |
| `maxSubArray(nums)` | divide and conquer (submitted) |

`memo` is a `vector` sized per call instead of `int memo[100010]`, so a
`Solution` is small enough to create anywhere, and one object can run every
version on any array.

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
- **`kadane`:** `calcTab` with the table squeezed into
  one variable. `sum` is `dp[i − 1]` clamped at 0: resetting `sum` to 0 when it
  goes negative is the same choice as `max(nums[i], dp[i − 1] + nums[i])`.
  `ans` is updated *before* the reset, so an all-negative array still returns
  its largest number, not 0.
- **`maxSubArray` (submitted), divide and conquer:** see below.

## Divide and conquer

```cpp
return max({cross_max, leftVal, rightVal});
```

Split at `mid`. The best subarray lies entirely in the left half, entirely in
the right half, or **crosses `mid`**. The first two are recursive calls. A
crossing subarray is a piece ending at `mid` plus a piece starting at
`mid + 1`, and the two pieces can be chosen separately:

- walk left from `mid`, keeping the best running sum: `leftPrefixVal`;
- walk right from `mid + 1` the same way: `rightPrefixVal`.

Both start at `INT_MIN` and take at least one number, so each side is
non-empty, as a crossing subarray needs.

It's not a DP: the halves don't share subproblems, so there's nothing to
cache. Each level of the recursion scans every number once, and there are
log n levels: **O(n log n)**, against Kadane's O(n). On LeetCode's 100,000
numbers that's about 10 ms. The recursion is only about 17 calls deep, so
unlike `recurse` it has no stack problem. It's the Week 4 merge-sort shape, and
the same split is what a segment tree stores for range-maximum-subarray
queries.

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

- `recurse` resets `global_max` to `INT_MIN` before each run; without that a
  second call would start from the previous array's answer.
- `calcRecurse` is one call deep per index. On Windows' default 1 MB stack at
  `-O0` it ran at n = 20,000 and crashed at 50,000; LeetCode allows 100,000.
  `memoized` has the same limit. `calcTab`, `kadane` and `maxSubArray` don't.

## Complexity

O(n) time for the four DP versions, O(n log n) for divide and conquer. O(n)
space for the recursion, memo and table; O(1) for Kadane; O(log n) stack for
divide and conquer.

## Tested

- LeetCode's three examples
- small cases: `[-1]`, `[-3, -1, -2]` (all negative), `[5, -10, 1]` and
  `[0, 0]`
- 2,000 random arrays of 1–12 numbers from −10 to 10
- LeetCode's limits: 100,000 copies of −10,000, and 100,000 random numbers
  (the table, Kadane and divide and conquer)

All five versions were checked against a brute force that tries every
subarray.

## Key insight

Define the state as the best subarray *ending at* `i`: then it either starts fresh or extends `dp[i − 1]`, and the answer is the max over all `i`. Kadane is that table kept in one variable. Divide and conquer gets the same answer in O(n log n) by splitting at the middle and handling the crossing case.
