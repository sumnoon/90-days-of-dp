# AtCoder DP B: Frog 2

- **Solution:** [`solutions/atcoder_dp_b.cpp`](../solutions/atcoder_dp_b.cpp)
- **Problem:** https://atcoder.jp/contests/dp/tasks/dp_b
- **Day:** 34 (Week 5 Sat), solved on Mon 23 Nov
- **Solved without help?** yes

[Frog 1](atcoder_dp_a.md), but the frog can jump up to K stones ahead
(K ≤ 100), still paying `|h[i] − h[j]|` per jump.

## State

`calc(idx)` returns **the cheapest cost from stone `idx` to the last stone**.

## Transition

```cpp
for (int i = idx + 1; i < min(idx + k + 1, n); ++i)
    ans = min(ans, abs(h[idx] - h[i]) + calc(i, k, n));
```

Split on the first jump, which now lands on any of the next K stones. Frog 1's
two choices become a loop. `min(idx + k + 1, n)` stops the loop at the last
stone.

## Base case

`idx == n − 1`: on the last stone, so 0.

## Complexity

N states, up to K choices each: **O(N · K)**, at most 100,000 × 100 = 10⁷
steps (0.2 s measured). O(N) space.

## Small notes on the code

- The arrays are `[100010]` this time, sized from AtCoder's limits.
- As in Frog 1, the recursion can be 100,000 calls deep, fine on AtCoder but
  not on Windows' default stack. The local tests were built with
  `-Wl,--stack,268435456`.
- The largest answer is at most about 10⁴ × 10⁵ = 10⁹, which fits in an
  `int`. The tests used `-ftrapv`, which aborts on any signed overflow.

## Tested

- AtCoder's four examples
- 300 random cases of 2–40 stones, with K from 1 to 100
- AtCoder's limits: N = 100,000 with K = 100 and with K = 1, and N = 2 with
  K = 100

All checked against a separate table.

## Key insight

Frog 1 with a loop: the first jump lands on any of the next K stones, so each state tries K choices, O(N · K) in all.
