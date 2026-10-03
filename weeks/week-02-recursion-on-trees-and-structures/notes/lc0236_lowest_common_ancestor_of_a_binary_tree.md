# ⭐ LC 236: Lowest Common Ancestor of a Binary Tree

- **Solution:** [`solutions/lc0236_lowest_common_ancestor_of_a_binary_tree.cpp`](../solutions/lc0236_lowest_common_ancestor_of_a_binary_tree.cpp)
- **Day:** 13 (Sat)
- **Solved without help?** yes
- **Video, after solving:** Striver's Tree series L27 · NeetCode LC 236

## What the call returns

`lowestCommonAncestor(root, p, q)` reports what this subtree found:

| Subtree contains | Returns |
|---|---|
| neither p nor q | `nullptr` |
| one of them | that node |
| both | their LCA |

**Returns** a node pointer, meaning one of those three things. **Passes down**
`p` and `q` unchanged: they're what to look for, not state.

## Recursive case

```cpp
TreeNode* l = lowestCommonAncestor(root->left, p, q);
TreeNode* r = lowestCommonAncestor(root->right, p, q);

if (l != nullptr && r != nullptr) return root;
return (l != nullptr) ? l : r;
```

- **Both sides found something:** p is on one side and q on the other, so
  this is the lowest node above both. Return `root`.
- **Only one side found something:** pass it up unchanged. It's either the
  one node found so far, or an LCA already settled deeper down.
- **Neither:** `r` is `nullptr`, so `nullptr` goes up.

Once an LCA is found, every node above it sees one non-null side and passes
it straight up to the root.

## Base cases

```cpp
if (root == nullptr || root == p || root == q) return root;
```

- Empty subtree: nothing found.
- `root` is p or q: return it **without searching below**. If the other node
  is underneath, this node *is* the LCA (a node counts as its own ancestor,
  LeetCode example 2: LCA(5, 4) = 5), and nobody above will see the other
  node on a different side, so this node goes all the way up. If the other
  node is elsewhere, the ancestor where the two sides meet returns itself.

This relies on LC 236's guarantee that **both p and q are in the tree**.
Without it, a node returned as "one of them" could be mistaken for the LCA.

## Complexity

Time: **O(n)**, each node at most once.
Space: **O(h)** stack.

## Tested

LeetCode's three examples, four more pairs on example 1's tree (both deep
under one node, one an ancestor of the other, opposite sides at different
depths), and 2,279 random (p, q) pairs on 500 random trees, each checked
against a reference that builds both root-to-node paths and takes the last
node they share.

## Key insight

Each subtree reports what it found; the first node that hears back from both sides is the answer.
