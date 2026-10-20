# LC 509: Fibonacci Number, three ways

- **Solution:** [`solutions/lc0509_fibonacci_number_three_ways.cpp`](../solutions/lc0509_fibonacci_number_three_ways.cpp)
- **Day:** 29 (Mon), Week 5's first task
- **Solved without help?** yes
- **Week 1 version:** [`week-01 …/lc0509_fibonacci_number.cpp`](../../week-01-recursion-fundamentals/solutions/lc0509_fibonacci_number.cpp), plain recursion only

Week 1 showed the problem: plain recursion recomputes the same values over
and over. Week 5 starts by fixing it, two ways.

## 1. Plain recursion

```cpp
int recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return recursive(n - 1) + recursive(n - 2);
}
```

Correct, and exponential: every call makes two more.

## 2. Memoized: top-down DP

```cpp
int memorization(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];                       // solved before
    return dp[n] = memorization(n - 1) + memorization(n - 2);   // remember it
}
```

The same recursion with a cache, exactly the change made to LC 241 for the
Month 1 checkpoint. `-1` marks "not computed yet" (`fib` fills the table with
`memset(dp, -1, …)`, which works because every byte of `-1` is `0xFF`). Each
`fib(i)` is now computed once; every later request is a lookup.

## 3. Table: bottom-up DP

```cpp
int tabulation(int n) {
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
```

No recursion at all: fill the answers **in the order they're needed**,
smallest first, so `dp[i - 1]` and `dp[i - 2]` are always ready when `dp[i]`
is computed. Same recurrence, same base cases, run as a loop.

## Measured at n = 40 (the plan's task)

| Version | Calls / steps | Time (`-O0`) | Time (`-O2`) |
|---|---|---|---|
| plain recursion | **331,160,281** calls | 574 ms | 137 ms |
| memoized | 79 calls | 0.3 µs | 0.6 µs |
| table | 39 loop steps | 0.1 µs | 0.2 µs |

About a **million times** faster, from one line of caching. (Timed on a
scratch copy: see below.)

## Small notes on the code

- **`int dp[31]` is too small for n = 40.** LeetCode stops at 30, so the
  submitted version is fine, but the plan's timing at n = 40 would write past
  the end of the table in both the memoized and table versions. The timing
  above used a copy with `dp[41]`.
- `fib` only calls `tabulation`; the other two are there to compare.
- The method is spelled `memorization`; the technique is **memoization**
  (from "memo", no r).
- The table version only ever reads the last two entries, so two variables
  would do instead of an array: that's Thursday's "O(1) space" version of
  House Robber.

## Tested

n = 0 … 30 for all three versions (plain recursion up to 27, to keep the run
short), each against the known sequence, plus the n = 40 timing.

## Key insight

Same recurrence, three ways to run it: recompute everything, remember what you've computed, or compute in an order where everything you need is already there.
