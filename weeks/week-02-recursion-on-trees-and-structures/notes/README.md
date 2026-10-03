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
| [LC 112 Path Sum](lc0112_path_sum.md) | 10 | clean | Pass down what's still needed; a leaf checks whether it's exactly its own value. |
| [LC 98 Validate BST](lc0098_validate_binary_search_tree.md) | 11 | clean | Pass the allowed range down; each step narrows it by one side. `nullptr` bounds dodge the `INT_MIN`/`INT_MAX` trap. |
| [LC 24 Swap Nodes in Pairs](lc0024_swap_nodes_in_pairs.md) | 12 | clean | Trust the call to swap everything after this pair; rewire the pair and return its second node. |
| [⭐ LC 543 Diameter](lc0543_diameter_of_binary_tree.md) | 13 | clean | Return the height upward; record the diameter on the side. They are different numbers. |
| [⭐ LC 236 Lowest Common Ancestor](lc0236_lowest_common_ancestor_of_a_binary_tree.md) | 13 | clean | Each subtree reports what it found; the first node that hears back from both sides is the answer. |

## Visualizations

| Page | What it shows |
|---|---|
| [Down the tree, back up it](https://sumnoon.github.io/90-days-of-dp/trees/) | Pre, in and post order on one tree with `ans` passed down; LC 104 with depths returned up; LC 112 with the remaining target passed down; LC 98 with the allowed range narrowing. |
| [Swap the halves, walk in lockstep](https://sumnoon.github.io/90-days-of-dp/mirror/) | LC 226 subtrees swapping sides as calls return; LC 100 walking two trees in lockstep. |
| [Swap a pair, trust the rest](https://sumnoon.github.io/90-days-of-dp/lc24/) | LC 24: nothing changes going down; each frame rewires two links coming back up, then the nodes slide into their new order. |
| [What each subtree reports back](https://sumnoon.github.io/90-days-of-dp/report/) | LC 543 returning heights while the diameter is kept on the side; LC 236 with each subtree's report. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
