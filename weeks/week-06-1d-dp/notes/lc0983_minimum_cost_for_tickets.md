# LC 983: Minimum Cost For Tickets

- **Solution:** [`solutions/lc0983_minimum_cost_for_tickets.cpp`](../solutions/lc0983_minimum_cost_for_tickets.cpp)
- **Day:** 42 (Week 6 Sun), solved on Fri 20 Nov
- **Solved without help?** yes

You travel on the given days of a year. Tickets cover 1, 7 or 30 consecutive
days and cost `costs[0]`, `costs[1]` and `costs[2]`. Find the cheapest way to
cover every travel day.

## State

`calc(idx)` returns **the cheapest way to cover travel days `days[idx..]`**.
The answer is `calc(0)`.

The state is an index into `days`, not a calendar day: only travel days need
a decision, so non-travel days are skipped for free.

## Transition

On travel day `days[idx]` you must buy something. Split on **which ticket**:

- **1-day:** covers only this day, so continue at `idx + 1`;
- **7-day:** covers `days[idx]` up to `days[idx] + 6`, so continue at the
  first `j` with `days[j] >= days[idx] + 7`;
- **30-day:** the same with 30, continuing at `k`.

Take the cheapest of the three. The `while` loops find `j` and `k` by walking
forward from `idx`.

## Base case

`idx >= n`: no travel days left, so 0.

## Complexity

n states. Each walks forward at most 30 entries, because the days are
distinct and a 30-day window holds at most 30 of them: **O(30 · n)** time,
O(n) space.

## Small notes on the code

- `memo.resize(n, -1)` only fills **new** slots with −1. Reusing one
  `Solution` for a second call keeps the old answers in the slots that were
  already there, and those are wrong for new input. `memo.assign(n, -1)`
  resets every slot. LeetCode makes a new object per test, and so does the
  test here.
- `calc`'s `n` could come from `days.size()`. Passing it in is fine.
- A table can fill backwards from `idx = n − 1`, since each entry only reads
  later ones. The test's reference uses a related table over all 365
  calendar days instead.

## Tested

- LeetCode's two examples
- one day with the 1-day ticket the dearest (`[5, 2, 3]`), day 365 alone,
  days 1 and 365, and `[1, 2, 3]` with cheap 1-day tickets
- 3,000 random cases: 1–365 distinct days, and costs 1–1000 in any order (not
  always rising), so sometimes a longer ticket is cheaper than a shorter one

All checked against a backwards table over calendar days 1–365.

## Key insight

Index the state by travel day, not calendar day: each travel day needs exactly one decision, which ticket starts there, and that ticket decides the next travel day still uncovered.
