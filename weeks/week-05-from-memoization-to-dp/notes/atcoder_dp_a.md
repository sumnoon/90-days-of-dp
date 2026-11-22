# AtCoder DP A: Frog 1

- **Solution:** [`solutions/atcoder_dp_a.cpp`](../solutions/atcoder_dp_a.cpp)
- **Problem:** https://atcoder.jp/contests/dp/tasks/dp_a
- **Day:** 34 (Week 5 Sat), solved on Mon 23 Nov
- **Solved without help?** The DP, yes. The arrays were sized for 10,000
  stones instead of AtCoder's 100,000; that was fixed after a hint, so it's on
  the [redo list](../../../redo-list.md).

A frog starts on stone 1 and jumps to stone `i + 1` or `i + 2`. A jump costs
`|h[i] − h[j]|`. Find the cheapest way to reach stone N.

## State

`calc(idx)` returns **the cheapest cost from stone `idx` to the last stone**.
The answer is `calc(0)`.

## Transition

```cpp
ans = min(abs(h[idx] - h[idx + 1]) + calc(idx + 1, n),
          abs(h[idx + 2] - h[idx]) + calc(idx + 2, n));
```

Split on the **first jump**: one stone or two, each only if that stone
exists. It's [LC 746](lc0746_min_cost_climbing_stairs.md) with the step cost
depending on the two stones instead of being fixed.

## Base case

`idx == n − 1`: already on the last stone, so 0. The `idx > n` check never
fires, because both jumps are guarded by `< n`.

## Complexity

N states, two choices each: **O(N)** time and space.

## The array size

`h` and `memo` were first declared `[10010]`, but AtCoder allows
N = 100,000. Reading heights past the end of `h` wrote into `memo`, and runs
with N above about 10,000 never finished. Once both arrays were `[100010]`,
every size matched. In between, one save also dropped the
`memset(memo, -1, ...)` line, which made every answer 0, since global arrays
start at 0 and 0 looks like "already computed". **Size arrays from the
problem's limits**, not from the examples.

## Small notes on the code

- The recursion is one call deeper per stone, so up to 100,000 calls deep.
  That's fine on AtCoder, which runs on Linux with a large stack. On Windows
  it overflows the default 1 MB stack, so the local tests were built with
  `-Wl,--stack,268435456`. A table, `dp[i]` from `dp[i − 1]` and `dp[i − 2]`,
  avoids the question.

## Tested

- AtCoder's three examples
- 300 random cases of 2–50 stones with heights 1–10,000
- AtCoder's limit: 12,000, 50,000 and 100,000 random stones, and 100,000 stones
  alternating 1 and 10,000 (answer 9,999)

All checked against a separate table.

## Key insight

LC 746 with costs between stones: the first jump is one stone or two. And size arrays from the stated limits, not the examples.
