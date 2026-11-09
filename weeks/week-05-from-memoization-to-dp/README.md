# Week 5: From Memoization to DP

**Dates:** Oct 19 – Oct 25  
**Full guide:** [PLAN.md](../../PLAN.md)

## Schedule

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | LC 509 three ways (recursion, memoized, table). Time each one for n=40. |
| Tue | 1–1.5 h | LC 70. |
| Wed | 1–1.5 h | LC 746. |
| Thu | 1–1.5 h | LC 198 in four versions: recursion, memoized, table, O(1) space. |
| Fri | 1–1.5 h | LC 1137 and LC 740 (turns into House Robber). |
| **Sat** (weekend) | 3–4 h | Watch the MIT 6.006 SRTBOT lecture. Solve LC 213 and LC 96, then AtCoder A, B, and C. |
| **Sun** (weekend) | 2–3 h | Do the **checkpoint** and CSES Dice Combinations. Preview Week 6 with the tabulation half of the [freeCodeCamp DP video](https://www.youtube.com/watch?v=oBt53YbR9Kk), [3:10:53](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=11453s)–[5:07:44](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=18464s). |

## Video: the memoization half

[freeCodeCamp: *Dynamic Programming – Learn to Solve Algorithmic Problems*](https://www.youtube.com/watch?v=oBt53YbR9Kk)
(Alvin Zablan). The code is JavaScript; write the problems in C++.

The first hour, up to canSum, is the Week 5 preview (fib, gridTraveler and the
memoization recipe). The rest of this half, about 2 hours, is for this week.
The tabulation half starts at [3:10:53](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=11453s) and is Sunday's preview of Week 6.

| Time | Chapter |
|---|---|
| [0:00:00](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=0s) | course introduction |
| [0:03:30](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=210s) | fib memoization |
| [0:38:39](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=2319s) | gridTraveler memoization |
| [1:04:52](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=3892s) | memoization recipe |
| [1:09:56](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=4196s) | canSum memoization |
| [1:29:29](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=5369s) | howSum memoization |
| [1:52:06](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=6726s) | bestSum memoization |
| [2:12:45](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=7965s) | canConstruct memoization |
| [2:38:36](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=9516s) | countConstruct memoization |
| [2:47:30](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=10050s) | allConstruct memoization |

## Problems

⭐ = core, don't skip

- [x] ⭐ LC 70 Climbing Stairs — [notes](notes/lc0070_climbing_stairs.md)
- [x] ⭐ LC 746 Min Cost Climbing Stairs — [notes](notes/lc0746_min_cost_climbing_stairs.md)
- [x] ⭐ LC 198 House Robber — [notes](notes/lc0198_house_robber.md)
- [x] ⭐ LC 213 House Robber II — [notes](notes/lc0213_house_robber_ii.md)
- [x] LC 740 Delete and Earn — [notes](notes/lc0740_delete_and_earn.md)
- [x] LC 1137 N-th Tribonacci Number — [notes](notes/lc1137_nth_tribonacci_number.md)
- [ ] LC 96 Unique Binary Search Trees
- [x] CSES: Dice Combinations — [notes](notes/cses_dice_combinations.md)

## Checkpoint

- [x] Write all 4 versions of House Robber from memory.
  Passed Wed Oct 28 (Sunday's checkpoint, three days late): [checkpoint solve](redos/lc0198_house_robber_checkpoint.cpp). Written fresh, with a different table from Thursday's (`memo[i]` = best of houses 0..i). The memoized version first called the plain recursion inside it (40 houses: 2.4 s); fixed after a hint, and 100 houses now take 0 ms.

## Notes

One note per problem in [`notes/`](notes/): the state, the recurrence, the base
cases, the order a table is filled in, complexity, and the idea that unlocked
it. Start at the [notes index](notes/README.md).

Also this week:

- [LC 509 Fibonacci, three ways](notes/lc0509_fibonacci_number_three_ways.md) — Monday: recursion, memoized, table, timed at n = 40
