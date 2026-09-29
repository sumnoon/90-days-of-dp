# LC 100: Same Tree

- **Solution:** [`solutions/lc0100_same_tree.cpp`](../solutions/lc0100_same_tree.cpp)
- **Day:** 9 (Tue)
- **Solved without help?** yes
- **Video, after solving:** Striver's Tree series L18

## What the call returns

`isSameTree(p, q)` returns whether the subtrees under `p` and `q` have the
same shape and the same values.

**Returns** a bool. **Passes down** two pointers that move in lockstep:
left with left, right with right.

## Recursive case

```cpp
return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
```

Two trees are the same when their roots match **and** their left subtrees are
the same **and** their right subtrees are the same. This is the palindrome
check's two-pointer recursion on a tree: two positions walked together,
compared at each step.

`&&` short-circuits: the first mismatch stops the walk, and nothing to its
right is visited. The same thing did the work of a base case in LC 231.

## Base case

```cpp
if (p == q) return true;
if (p == nullptr || q == nullptr) return false;
```

- `p == q` covers **both empty** (both `nullptr`) in one comparison, and also a
  tree compared with itself.
- If only one is empty, the shapes differ.

After those two lines both pointers are real nodes, so `p->val` is safe.

## Complexity

Time: **O(min(n, m))**. The walk stops at the first difference.
Space: **O(min(h₁, h₂))** stack.

## Tested

LeetCode's three examples, including `[1,2]` vs `[1,null,2]` (same values,
different shape), both empty, each side empty on its own, the 9-node tree
against itself, and against a copy with one deep leaf changed.

## See it

- **Swap the halves, walk in lockstep:** https://sumnoon.github.io/90-days-of-dp/mirror/ —
  pick *LC 100 same tree* to walk `p` and `q` together; try *different shape*
  and *one deep leaf*. ([source](../../../docs/mirror/index.html))

## Key insight

Walk both trees together; the first difference decides it.
