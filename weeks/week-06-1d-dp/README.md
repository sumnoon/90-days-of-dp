# Week 6: 1D DP (Sequences and Decisions)

**Dates:** Oct 26 – Nov 22 (stretched by two breaks: see the [catch-up schedule](#catch-up-schedule-mon-nov-9--sun-nov-22))  
**Full guide:** [PLAN.md](../../PLAN.md)

## Schedule

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | LC 53. Rewrite Kadane's algorithm as dp[i] = max(nums[i], dp[i−1] + nums[i]). |
| Tue | 1–1.5 h | LC 152 (track both max and min). |
| Wed | 1–1.5 h | LC 322. Write the recursion first, then the table. |
| Thu | 1–1.5 h | LC 139. |
| Fri | 1–1.5 h | LC 91. |
| **Sat** (weekend) | 3–4 h | LIS day: read the USACO Guide LIS module. Solve LC 300 in O(n²) and then O(n log n). Then LC 673 and LC 1048. |
| **Sun** (weekend) | 2–3 h | Do the **checkpoint**. Solve LC 983 and CSES Minimizing Coins. LC 354 is an optional stretch. |

## Catch-up schedule (Mon Nov 9 – Sun Nov 22)

Done so far: LC 53, LC 152 and the LC 22 and LC 77 redos. This replaces the
earlier catch-up, which was interrupted. Weeknights are one main item plus at
most a short warm-up, and there are buffer slots in both weeks. Commits keep
each problem's **plan day**, shown in the last column.

| Date | Time | Main work | Warm-up | Plan day |
|---|---|---|---|---|
| Mon Nov 9 | 1–1.5 h | LC 91 (a `'0'` can't be decoded on its own) | LC 46 redo 2 | 40 |
| Tue Nov 10 | 1–1.5 h | freeCodeCamp tabulation, [3:10:53](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=11453s)–[4:20:50](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=15650s) at 1.25× (about 55 min) | LC 47 redo 2 | 35 |
| Wed Nov 11 | 1–1.5 h | LC 322: recursion first, then the table | — | 38 |
| Thu Nov 12 | 1–1.5 h | freeCodeCamp, [4:20:50](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=15650s)–[5:07:44](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=18464s) at 1.25× (about 40 min), then LC 139 | — | 35, 39 |
| Fri Nov 13 | 1–1.5 h | AtCoder DP A and B | Hanoi lower bound redo 2 | 34 |
| **Sat Nov 14** | 3–4 h | AtCoder DP C. USACO Guide LIS module. LC 300 in O(n²), then O(n log n) | — | 34, 41 |
| **Sun Nov 15** | 2–3 h | Dice Combinations O(1) redo 1, LC 53 plain recursion redo 1, then **buffer** for anything that slipped | — | — |
| Mon Nov 16 | 1–1.5 h | LC 673 | — | 41 |
| Tue Nov 17 | 1–1.5 h | LC 1048 | — | 41 |
| Wed Nov 18 | 1–1.5 h | LC 983 | — | 42 |
| Thu Nov 19 | 1–1.5 h | CSES Minimizing Coins | — | 42 |
| Fri Nov 20 | — | **Buffer**, or a night off if nothing slipped | — | — |
| **Sat Nov 21** | 3–4 h | Anything left, then LC 354 (stretch) | — | 42 |
| **Sun Nov 22** | 2–3 h | **Checkpoint**, then preview Week 7 by skimming its README | — | 42 |

- Each video half comes right before the problem it sets up: bestSum before
  LC 322, and canConstruct before LC 139.
- Week 7 starts Mon Nov 23 (Day 43). Week 12 is Dec 28 – Jan 3 and the mastery
  test Jan 4–10.

## Video: the tabulation half

[freeCodeCamp DP video](https://www.youtube.com/watch?v=oBt53YbR9Kk), [3:10:53](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=11453s)–[5:07:44](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=18464s): the same problems as the
memoization half, now filled in as tables. Watch it on Week 5's Sunday as the
preview. canSum / howSum / bestSum are the same idea as Coin Change (LC 322,
Wednesday).

| Time | Chapter |
|---|---|
| [3:10:53](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=11453s) | fib tabulation |
| [3:22:17](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=12137s) | gridTraveler tabulation |
| [3:34:32](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=12872s) | tabulation recipe |
| [3:37:59](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=13079s) | canSum tabulation |
| [3:53:01](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=13981s) | howSum tabulation |
| [4:07:21](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=14841s) | bestSum tabulation |
| [4:20:50](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=15650s) | canConstruct tabulation |
| [4:38:06](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=16686s) | countConstruct tabulation |
| [4:50:23](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=17423s) | allConstruct tabulation |
| [5:07:44](https://www.youtube.com/watch?v=oBt53YbR9Kk&t=18464s) | closing thoughts |

## Problems

⭐ = core, don't skip

- [x] ⭐ LC 53 Maximum Subarray ([notes](notes/lc0053_maximum_subarray.md))
- [x] LC 152 Maximum Product Subarray ([notes](notes/lc0152_maximum_product_subarray.md))
- [ ] ⭐ LC 322 Coin Change
- [ ] ⭐ LC 139 Word Break
- [ ] ⭐ LC 91 Decode Ways
- [ ] ⭐ LC 300 Longest Increasing Subsequence
- [ ] LC 673 Number of Longest Increasing Subsequence
- [ ] LC 1048 Longest String Chain
- [ ] LC 983 Minimum Cost For Tickets
- [ ] LC 354 Russian Doll Envelopes (stretch)

## Checkpoint

- [ ] For each problem, write the state definition in one sentence before you write any code.

## Notes

<!-- For each problem: state, transition, base case, key insight. -->

One note per solved problem, indexed in [notes/README.md](notes/README.md).
