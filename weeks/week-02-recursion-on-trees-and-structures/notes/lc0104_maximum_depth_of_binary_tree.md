# ⭐ LC 104: Maximum Depth of Binary Tree

- **Solution:** [`solutions/lc0104_maximum_depth_of_binary_tree.cpp`](../solutions/lc0104_maximum_depth_of_binary_tree.cpp)
- **Day:** 8 (Mon)
- **Solved without help?** yes
- **Video, after solving:** Striver's Tree series L14

## What the call returns

`helper(root)` returns the number of nodes on the longest path from `root`
down to a leaf. It passes **nothing** down; the answer comes back up.

## Recursive case

```cpp
int l = helper(root->left);
int r = helper(root->right);
return 1 + max(l, r);
```

Leap of faith: suppose both calls already return the right depths for the
two subtrees. The deepest path from this node goes through whichever subtree
is deeper, plus this node itself, so `1 + max(l, r)`.

It's a **postorder** traversal: this node's work waits until both children
have answered.

## Base case

```cpp
if (root == nullptr) return 0;
```

An empty tree has depth 0. That's the identity value again, like Hanoi's
`n == 0`: it makes a leaf the general case (`1 + max(0, 0) = 1`), with no
special code for leaves.

## Complexity

Time: **O(n)**, each node once.
Space: **O(h)** stack. Tested on a 10,000-node chain, LeetCode's largest input:
10,000 frames deep, and it runs fine.

## Returning up vs passing down

| | Traversals (LC 144 / 94 / 145) | LC 104 |
|---|---|---|
| Passes down | `ans`, by reference | nothing |
| Returns up | nothing | the depth |
| Style | top-down | **bottom-up** |

This is Week 2's split. LC 543 on Saturday uses both at once: it **returns** a
height, like this one, but the answer it's asked for is a *different* value,
kept on the side.

## Small notes on the code

- `maxDepth` already has the right signature, so `helper` isn't needed: the
  three lines can go straight into `maxDepth`, which calls itself.

## See it

- **Down the tree, back up it:** https://sumnoon.github.io/90-days-of-dp/trees/ —
  pick *max depth* to watch each empty subtree return 0 and every node report
  `1 + max(l, r)` to its parent, with `l` and `r` on the call stack.
  ([source](../../../docs/trees/index.html))

## Key insight

Trust both children to report their depth; this node adds one.
