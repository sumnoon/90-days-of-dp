# LC 98: Validate Binary Search Tree

- **Solution:** [`solutions/lc0098_validate_binary_search_tree.cpp`](../solutions/lc0098_validate_binary_search_tree.cpp)
- **Day:** 11 (Thu)
- **Solved without help?** yes
- **Video, after solving:** Striver's Tree series L46

## What the call returns

`validate(root, lo, hi)` returns whether every value in the subtree under
`root` is strictly between `lo->val` and `hi->val`, and the subtree is itself
a BST. A `nullptr` bound means "no limit on this side".

**Returns** a bool. **Passes down** the range this subtree must fit in, as two
node pointers.

## Recursive case

```cpp
return validate(root->left, lo, root) && validate(root->right, root, hi);
```

Going left, this node becomes the new **upper** bound; the lower bound is
inherited. Going right, this node becomes the new **lower** bound; the upper
bound is inherited. So the range only ever narrows, and each node is checked
against **every** ancestor it has to respect, not only its parent.

## Base cases

```cpp
if (root == nullptr) return true;
if ((lo != nullptr && lo->val >= root->val) || (hi != nullptr && hi->val <= root->val)) return false;
```

- An empty subtree breaks no rule.
- `>=` and `<=` make the bounds **strict**: a duplicate value fails, which is
  what LC 98 asks for (`[1,1]` is not a BST).

## The trap it avoids

Checking each node only against its own children isn't enough:

```
    5
   / \
  4   6
     / \
    3   7
```

Every parent-child pair is in order (3 < 6 < 7), but 3 sits in 5's **right**
subtree and 3 < 5. With the range passed down, 3 is checked against
(lo = 5, hi = 6) and fails on the lower bound.

## Why node pointers, not `INT_MIN` / `INT_MAX`

Node values can be anything in the `int` range, including `INT_MIN` and
`INT_MAX` themselves. A sentinel bound like `validate(root, INT_MIN, INT_MAX)`
with strict checks would reject a tree that is just `[INT_MIN]`, since
`INT_MIN > INT_MIN` is false. The usual workaround is `long long` bounds
with `LLONG_MIN` / `LLONG_MAX`. Using `nullptr` for "no bound" avoids the
question entirely: no value can collide with it.

## Complexity

Time: **O(n)**, each node once, and `&&` stops at the first violation.
Space: **O(h)** stack.

## Tested

LeetCode's two examples, the 5-4-6-3-7 trap, a full valid BST, duplicates
(`[1,1]`, `[2,2,2]`), a lone node, the empty tree, `[INT_MIN]`, `[INT_MAX]`,
`[INT_MIN, null, INT_MAX]`, `[INT_MAX, INT_MIN]`, a node deep in a subtree
that is inside its parent's range but outside its grandparent's, and one
that is outside both.

## Key insight

Pass the allowed range down; each step left or right narrows it by one side.
