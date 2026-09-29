# ⭐ LC 226: Invert Binary Tree

- **Solution:** [`solutions/lc0226_invert_binary_tree.cpp`](../solutions/lc0226_invert_binary_tree.cpp)
- **Day:** 9 (Tue)
- **Solved without help?** yes

## What the call returns

`invertTree(root)` mirrors the subtree under `root` **in place** and returns
its root: the same node it was given, now with its whole subtree flipped.

**Returns** the root of the mirrored subtree. **Passes down** nothing but the
pointer.

## Recursive case

```cpp
TreeNode *l = root->left;
TreeNode *r = root->right;

root->left = invertTree(r);
root->right = invertTree(l);
```

Leap of faith: `invertTree(r)` hands back the right subtree, already
mirrored. In a mirror image it belongs on the **left**, so that's where it
goes, and the same for the other side. Mirror both halves and swap them, and
the whole tree is mirrored.

**Why `l` is saved first:** `root->left = invertTree(r)` overwrites
`root->left`. Without the copy, the next line would read the *new* left child
(the mirrored right subtree) and invert it back. The result would be two
pointers to the same subtree, and the original left subtree lost.

## Base case

```cpp
if (root == nullptr) return nullptr;
```

The mirror image of an empty tree is empty.

## Complexity

Time: **O(n)**, each node once.
Space: **O(h)** stack.

## Order doesn't matter here

Your version recurses first and assigns after, so it's a **postorder** walk.
Swapping first and then recursing into each child (**preorder**) works just as
well: each node's two pointers are swapped exactly once either way. Inorder
would break it, because after the swap the "right" call would go into the
subtree the "left" call has already inverted.

## Tested

LeetCode's two examples, an empty tree, one node, a left child becoming a
right child, and a left chain becoming a right chain. Also: inverting the
9-node LC 144 tree **twice** gives the original back.

## See it

- **Swap the halves, walk in lockstep:** https://sumnoon.github.io/90-days-of-dp/mirror/ —
  watch each subtree slide to its mirrored side as its call returns. Step to
  just after `root->left = invertTree(r)` to see the old left half held only
  by the saved `l`. ([source](../../../docs/mirror/index.html))

## Key insight

Mirror each half, then swap the halves; save one pointer before overwriting it.
