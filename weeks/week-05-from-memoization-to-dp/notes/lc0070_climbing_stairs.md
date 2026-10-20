# ⭐ LC 70: Climbing Stairs

- **Solution:** [`solutions/lc0070_climbing_stairs.cpp`](../solutions/lc0070_climbing_stairs.cpp)
- **Day:** 30 (Tue)
- **Solved without help?** yes

## State: what the call returns

`func(idx, n)` returns **the number of ways to get from stair `idx` to the
top** (stair `n`). The answer is `func(0, n)`.

Only `idx` changes between calls; `n` is the same everywhere. So one number
describes a subproblem, and a one-dimensional `memo[idx]` is enough.

## Recurrence

```cpp
return memo[idx] = func(idx + 1, n) + func(idx + 2, n);
```

From stair `idx` the first move is either 1 step or 2. Every way to the top
starts with exactly one of those, so the counts **add**. That makes it
Fibonacci: `climbStairs(n)` is `fib(n + 1)`.

## Base cases

```cpp
if (idx == n) return 1;   // standing on the top: one way (do nothing)
if (idx > n)  return 0;   // stepped past the top: not a way
```

Both are checked **before** `memo[idx]` is read. So `idx = n + 1` (as high as
46 for n = 45) never touches the array, and `memo[46]` is big enough.

## Complexity

With the cache: each `idx` from 0 to n−1 is computed once, so **O(n)** time,
O(n) space for the memo and the stack. Without it, the call tree is the same
one as Fibonacci's, exponential.

## Bottom-up, for Thursday

This version counts **forward from the bottom**: ways *from* `idx`. The table
version is usually written the other way round: `ways[i]`, the ways to
**reach** stair `i`, with `ways[i] = ways[i - 1] + ways[i - 2]`. Both are
correct. Which entries you need first decides the order the table is filled
in.

## Tested

n = 1 … 45 (LeetCode's range), each on a fresh `Solution`: n ≤ 30 against
plain recursion with no cache, and the rest against the Fibonacci numbers.
n = 45 gives 1,836,311,903, which still fits in an `int`.

## Key insight

The first step is 1 or 2, and every way starts with exactly one of them, so ways(i) = ways(i + 1) + ways(i + 2): Fibonacci again.
