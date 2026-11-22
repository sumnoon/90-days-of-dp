# AtCoder DP C: Vacation

- **Solution:** [`solutions/atcoder_dp_c.cpp`](../solutions/atcoder_dp_c.cpp)
- **Problem:** https://atcoder.jp/contests/dp/tasks/dp_c
- **Day:** 34 (Week 5 Sat), solved on Mon 23 Nov
- **Solved without help?** yes

Each of N days, pick one of three activities, each with its own points that
day. You can't do the same activity two days in a row. Maximise the total.

## State

`calc(idx, type)` returns **the most points from days `idx..` when yesterday's
activity was `type`**.

The day alone isn't enough. Which choices are allowed today depends on
yesterday, so yesterday's activity has to be part of the state. This is the
first problem here with **two numbers in the state**, a step towards Week 7's
grids.

## Transition

```cpp
for (int i = 0; i < 3; ++i) {
    if (i == type) continue;
    ans = max(ans, act[idx][i] + calc(idx + 1, i, n));
}
```

Try each activity except yesterday's, add today's points, and move to tomorrow
with today's activity as the new "yesterday".

## Base case

`idx == n`: no days left, so 0.

## Starting

Day 0 has no yesterday. `main` takes the best of `calc(0, 0)`, `calc(0, 1)` and
`calc(0, 2)`: each pretends yesterday was one activity, which rules out only
that one. Together the three calls allow every activity on day 0.

## Complexity

N × 3 states, 2 choices each: **O(N)** time and space.

## Small notes on the code

- The recursion goes one call deeper per day, up to 100,000 calls. That's fine
  on AtCoder, but the local tests used `-Wl,--stack,268435456`.
- The largest total is 100,000 × 10,000 = 10⁹, which fits in an `int`. The
  tests used `-ftrapv`, which aborts on any signed overflow.
- The table version keeps three numbers per day, the best total ending with
  each activity, and only the previous day's three are needed.

## Tested

- AtCoder's three examples
- 300 random cases of 1–8 days with points 1–10, checked against a brute force
  that tries every schedule
- AtCoder's limits: 100,000 days of all 10,000 (the largest answer, 10⁹) and
  100,000 random days, checked against a separate table

## Key insight

When today's choices depend on yesterday's, put yesterday's choice in the state: `calc(day, last activity)`, trying every activity except that one.
