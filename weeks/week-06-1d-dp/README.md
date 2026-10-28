# Week 6: 1D DP (Sequences and Decisions)

**Dates:** Oct 26 – Nov 1  
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
