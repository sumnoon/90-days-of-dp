# Week 3 notes

One note per solved problem: what the call records, what it passes down,
where the choice is undone, complexity, and the one idea that unlocked it.
Written to be re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [⭐ LC 78 Subsets](lc0078_subsets.md) | 15 | clean | Choose, explore, un-choose: the shared `cur` must look the same after a call as it did before. |
| [⭐ LC 77 Combinations](lc0077_combinations.md) | 16 | clean | LC 78's for-loop tree, keeping one layer; return as soon as `cur` is full. Open: prune branches that can't reach `k`. |

## Visualizations

| Page | What it shows |
|---|---|
| [Choose, explore, un-choose](https://sumnoon.github.io/90-days-of-dp/subsets/) | LC 78 as a decision tree, include/exclude and for-loop, with `cur` pushed and popped. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
