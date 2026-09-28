# Tree traversals: preorder, inorder, postorder

- **Solutions:**
  [`lc0144_binary_tree_preorder_traversal.cpp`](../solutions/lc0144_binary_tree_preorder_traversal.cpp) (LC 144),
  [`lc0094_binary_tree_inorder_traversal.cpp`](../solutions/lc0094_binary_tree_inorder_traversal.cpp) (LC 94),
  [`lc0145_binary_tree_postorder_traversal.cpp`](../solutions/lc0145_binary_tree_postorder_traversal.cpp) (LC 145)
- **Day:** 8 (Mon)
- **Solved without help?** yes
- **Videos:** Striver's Tree series L1, L2, L4–L7

## What the call does

`helper(root, ans)` appends every value in the subtree under `root` to `ans`,
in the chosen order. It **returns nothing**; the answer is built up in `ans`.

## Recursive case

The three traversals are the same three lines. Only the position of the
visit moves:

```cpp
// preorder: node, left, right
ans.push_back(root->val);
helper(root->left, ans);
helper(root->right, ans);

// inorder: left, node, right
helper(root->left, ans);
ans.push_back(root->val);
helper(root->right, ans);

// postorder: left, right, node
helper(root->left, ans);
helper(root->right, ans);
ans.push_back(root->val);
```

This is Day 1's print 1..N vs N..1 again, with **two** recursive calls
instead of one: work before the calls, between them, or after them.

For the tree `1(2(3), 4)`:

| Order | Output |
|---|---|
| pre | 1 2 3 4 |
| in | 3 2 1 4 |
| post | 3 2 4 1 |

## Base case

```cpp
if (root == nullptr) return;
```

An empty subtree adds nothing. Leaves need no special case: a leaf is a node
whose two calls both return at once.

## Complexity

Time: **O(n)**, each node is visited once.
Space: **O(h)** stack, where h is the tree's height. That's O(log n) for a
balanced tree but O(n) for a chain like `{1, 2, null, 3, null, 4}`. The
output vector is O(n) on top.

## Passing state down

`ans` is passed **by reference** and shared by every call; each call adds to
the same vector. Pass it by value and each call would fill its own copy,
which is thrown away when it returns: the result would be empty.

This is the **top-down** half of Week 2: information goes *down* as a
parameter, and nothing comes back up. LC 104 is the other half: the answer
is *returned* up.

## Small notes on the code

- A first version of the `Node` struct had `Node(int val) { val = val; }`:
  the parameter hides the member, so `val = val` assigns the parameter to
  itself and every node printed garbage. `-Wshadow` warns about it. Fix with
  an initializer list `: val(val)`, with `this->val = val`, or with a different
  parameter name.

## See it

- **Down the tree, back up it:** https://sumnoon.github.io/90-days-of-dp/trees/ —
  step through all three orders on the same tree, with `ans` filling as it is
  passed down and every empty-subtree call drawn in.
  ([source](../../../docs/trees/index.html))

## Key insight

One moved line changes the order; the recursion itself doesn't change.
