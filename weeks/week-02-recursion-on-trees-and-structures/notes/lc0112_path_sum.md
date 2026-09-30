# LC 112: Path Sum

- **Solution:** [`solutions/lc0112_path_sum.cpp`](../solutions/lc0112_path_sum.cpp)
- **Day:** 10 (Wed)
- **Solved without help?** yes

## What the call returns

`func(root, targetSum)` returns whether some path from `root` down to a
**leaf** adds up to `targetSum`, where `targetSum` is what's *still needed*
after the nodes above.

**Returns** a bool. **Passes down** the remaining sum: each call subtracts its
own value before handing it on.

## Recursive case

```cpp
return func(root->left, targetSum - root->val) || func(root->right, targetSum - root->val);
```

This node uses up `root->val` of the target, so each child is asked for the
rest. Either side will do, hence `||`, and it short-circuits: once the left
finds a path, the right is never searched.

This is the first problem this week where the answer depends on something
**passed down**. LC 104 only sent information up. Here every call gets its own
copy of the remaining sum, so nothing has to be undone on the way back.

## Base cases

```cpp
if (root == nullptr) return false;
if (root->left == nullptr && root->right == nullptr) {
    return targetSum - root->val == 0;
}
```

- **Empty tree:** no path at all, so `false`, even when the target is 0.
  `hasPathSum([], 0)` is `false`.
- **Leaf:** the only place a path can end. It succeeds exactly when this node
  uses up the rest of the target.

The leaf check is what makes the path go root-to-**leaf**. Checking
"`targetSum == 0` at `nullptr`" instead would be wrong: for `[1, 2]` with
target 1, the empty right child of 1 would report success, but 1 isn't a leaf.

## Complexity

Time: **O(n)**. Values can be negative, so a partial sum that overshoots can
still come back; there's no early cut-off.
Space: **O(h)** stack.

## Tested

LeetCode's three examples, `[1,2]` with target 1 (false: 1 isn't a leaf),
a lone root, negative values, and three different leaf paths in the example
tree (22, 26, 18), plus 9, which only a non-leaf path reaches.

## Key insight

Pass down what's still needed; a leaf checks whether it's exactly its own value.
