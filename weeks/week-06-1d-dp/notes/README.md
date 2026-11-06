# Week 6 notes

One note per solved problem: the state, the transition, the base cases, the
order a table is filled in, complexity, and the one idea that unlocked it.
Written to be re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [⭐ LC 53 Maximum Subarray, five versions](lc0053_maximum_subarray.md) | 36 | hint (recursion) | The best subarray ending at `i` starts fresh or extends the one ending at `i − 1`; Kadane keeps that table in one variable. Divide and conquer: left, right, or crossing `mid`. |
| [LC 152 Maximum Product Subarray](lc0152_maximum_product_subarray.md) | 37 | clean | Between zeros only the sign matters, so the best run is a prefix or a suffix: one pass from each end. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
