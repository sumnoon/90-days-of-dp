# Week 5 notes

One note per solved problem: the state, the recurrence, the base cases, the
order a table is filled in, complexity, and the one idea that unlocked it.
Written to be re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [⭐ LC 70 Climbing Stairs](lc0070_climbing_stairs.md) | 30 | clean | The first step is 1 or 2, so ways(i) = ways(i + 1) + ways(i + 2): Fibonacci again. |
| [⭐ LC 198 House Robber, four versions](lc0198_house_robber.md) | 32 | clean | Rob this house and jump two, or skip it and move one; the table only needs its last two entries. |
| [LC 740 Delete and Earn](lc0740_delete_and_earn.md) | 33 | clean | Take a value and you take all its copies and lose its neighbours: add up each value's points and run House Robber over the values. |
| [⭐ LC 746 Min Cost Climbing Stairs](lc0746_min_cost_climbing_stairs.md) | 31 | clean | LC 70 with `min` in place of `+`: pay for this step, then take the cheaper next move. |
| [LC 509 Fibonacci, three ways](lc0509_fibonacci_number_three_ways.md) | 29 | clean | Same recurrence three ways: recompute (331M calls at n = 40), remember (79), or fill in order (39 steps). |
| [LC 1137 N-th Tribonacci Number](lc1137_nth_tribonacci_number.md) | 33 | clean | Fibonacci with a third term; uncached, n = 37 makes 4 billion calls, cached it's 37 values. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
