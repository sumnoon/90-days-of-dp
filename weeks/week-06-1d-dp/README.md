# Week 6: 1D DP (Sequences and Decisions)

**Dates:** Oct 26 – Nov 15 (stretched by a break: see the [catch-up schedule](#catch-up-schedule-thu-nov-5--sun-nov-15))  
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

## Catch-up schedule (Thu Nov 5 – Sun Nov 15)

LC 53 was done on Wed Oct 28, and nothing was solved Oct 29 – Nov 4. The rest
of Week 6 is spread over the next eleven days, along with the Week 5 leftovers
and the redos that are due. Weeknights stay at one problem plus a short
warm-up. Commits keep each problem's **plan day**, shown in the last column.

| Date | Time | Main work | Warm-up | Plan day |
|---|---|---|---|---|
| Thu Nov 5 | 1–1.5 h | LC 152 (track both max and min) | LC 77 redo 2 | 37 |
| Fri Nov 6 | 1–1.5 h | LC 91 (a `'0'` can't be decoded on its own) | LC 46 redo 2 | 40 |
| **Sat Nov 7** | 3–4 h | The [tabulation half](#video-the-tabulation-half) of the freeCodeCamp video at 1.25× (about 1.5 h), then LC 322: recursion first, then the table | — | 35, 38 |
| **Sun Nov 8** | 2–3 h | LC 139, then AtCoder DP A, B and C (the Week 5 leftovers) | — | 39, 34 |
| Mon Nov 9 | 1–1.5 h | Read the USACO Guide LIS module, then LC 300 in O(n²) | Hanoi lower bound redo 2 | 41 |
| Tue Nov 10 | 1–1.5 h | LC 300 in O(n log n) | LC 47 redo 2 | 41 |
| Wed Nov 11 | 1–1.5 h | LC 673 | Dice Combinations O(1) redo 1 | 41 |
| Thu Nov 12 | 1–1.5 h | LC 1048 | LC 53 plain recursion redo 1 | 41 |
| Fri Nov 13 | 1–1.5 h | LC 983 | — | 42 |
| **Sat Nov 14** | 3–4 h | CSES Minimizing Coins. Then **buffer**: finish anything that slipped this week. LC 354 only if nothing did. | — | 42 |
| **Sun Nov 15** | 2–3 h | **Checkpoint**, then preview Week 7 by skimming its README | — | 42 |

- The video comes right before LC 322 and LC 139 because its bestSum and
  canConstruct are those two problems in another form.
- LC 96 moved to Week 10 (choosing the root splits it into two intervals), and
  the optional MIT 6.006 lecture is dropped.
- Week 7 starts Mon Nov 16 (Day 43), and every later week moves two weeks:
  Week 12 is Dec 21–27 and the mastery test Dec 28 – Jan 3. If the holidays
  get in the way, the test week is the slack.

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
- [ ] LC 152 Maximum Product Subarray
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
