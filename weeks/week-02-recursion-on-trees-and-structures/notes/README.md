# Week 2 notes

One note per solved problem: what the call returns, what it passes down, the
base case, complexity, and the one idea that unlocked it. Written to be
re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [Tree traversals (LC 144, 94, 145)](tree_traversals.md) | 8 | clean | Pre, in and post order are the same three lines; only where the visit sits moves. |
| [⭐ LC 104 Maximum Depth](lc0104_maximum_depth_of_binary_tree.md) | 8 | clean | Trust both children to report their depth; this node adds one. The answer comes **up**, not down. |
| [⭐ LC 226 Invert Binary Tree](lc0226_invert_binary_tree.md) | 9 | clean | Mirror each half, then swap the halves; save one pointer before overwriting it. |
| [LC 100 Same Tree](lc0100_same_tree.md) | 9 | clean | Walk both trees together; `p == q` catches both-empty, and the first difference decides it. |

## Visualizations

| Page | What it shows |
|---|---|
| [Down the tree, back up it](https://sumnoon.github.io/90-days-of-dp/trees/) | Pre, in and post order on one tree with `ans` passed down; LC 104 with depths returned up. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
