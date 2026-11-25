# Week 7 notes

One note per solved problem: the state, the transition, the base cases, the
order a table is filled in, complexity, and the one idea that unlocked it.
Written to be re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [⭐ LC 62 Unique Paths, three ways](lc0062_unique_paths.md) | 43 | clean | A cell adds the two cells it can come from; the table only reads the row above and the cell to the left, so one row is enough. |
| [⭐ LC 63 Unique Paths II, three ways](lc0063_unique_paths_ii.md) | 44 | clean (overflow hint) | An obstacle is a cell with 0 paths. Counting from the start, cells cut off from the end can overflow, so cap the sum at `INT_MAX`. |
| [⭐ LC 64 Minimum Path Sum, in one row](lc0064_minimum_path_sum.md) | 45 | clean | LC 62's one row with `min` in place of `+`; the first row and column have one way in, so they're running sums. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
