# Week 2: Recursion on Trees and Structures

**Dates:** Sep 28 – Oct 4  
**Full guide:** [PLAN.md](../../PLAN.md)

## Schedule

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | Write preorder, inorder, and postorder traversals recursively. Solve LC 104. |
| Tue | 1–1.5 h | LC 226 and LC 100. |
| Wed | 1–1.5 h | LC 112 (pass the remaining sum down). |
| Thu | 1–1.5 h | LC 98 (pass (low, high) bounds down). |
| Fri | 1–1.5 h | LC 24. |
| **Sat** (weekend) | 3–4 h | Harder problems: LC 543 (return height, update a global answer) and LC 236 (what does each subtree report back?). Watch the NeetCode solutions after you attempt them. |
| **Sun** (weekend) | 2–3 h | Re-solve LC 543 from memory, then do the **checkpoint**. Preview Week 3 by reading the start of Erickson Ch 2. |

## Videos

[Striver's Tree series](https://www.youtube.com/playlist?list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk) — lecture numbers as in the video titles.

| When | Lectures |
|---|---|
| Before Mon | **L1** introduction, **L2** representation in C++, **L4** traversals (BFS / DFS), **L5** preorder, **L6** inorder, **L7** postorder. Skip L3 (Java) and L8–L13 (level-order and iterative). |
| After LC 104 | **L14** maximum depth |
| After LC 100 | **L18** identical trees |
| After LC 98 | **L46** validate a BST |
| After LC 543 | **L16** diameter, then **L17** maximum path sum |
| After LC 236 | **L27** lowest common ancestor |

Also: NeetCode's solutions for LC 543 and LC 236, after attempting them.

## Problems

⭐ = core, don't skip

- [x] ⭐ LC 104 Maximum Depth of Binary Tree — [notes](notes/lc0104_maximum_depth_of_binary_tree.md)
- [x] ⭐ LC 226 Invert Binary Tree — [notes](notes/lc0226_invert_binary_tree.md)
- [x] LC 100 Same Tree — [notes](notes/lc0100_same_tree.md)
- [x] LC 112 Path Sum — [notes](notes/lc0112_path_sum.md)
- [ ] ⭐ LC 543 Diameter of Binary Tree
- [ ] ⭐ LC 236 Lowest Common Ancestor of a Binary Tree
- [x] LC 98 Validate Binary Search Tree — [notes](notes/lc0098_validate_binary_search_tree.md)
- [x] LC 24 Swap Nodes in Pairs — [notes](notes/lc0024_swap_nodes_in_pairs.md)

## Checkpoint

- [ ] For every problem, explain in one sentence what the function returns and what it passes down.

## Notes

One note per problem in [`notes/`](notes/): what the call returns, what it
passes down, the base case, complexity, and the idea that unlocked it.
Start at the [notes index](notes/README.md).

Not from the problem list, but solved this week:

- [Tree traversals: preorder, inorder, postorder (LC 144, 94, 145)](notes/tree_traversals.md)
