# ⭐ LC 543: Diameter of Binary Tree

- **Solution:** [`solutions/lc0543_diameter_of_binary_tree.cpp`](../solutions/lc0543_diameter_of_binary_tree.cpp)
- **Day:** 13 (Sat)
- **Solved without help?** yes
- **Video, after solving:** Striver's Tree series L16 · NeetCode LC 543

## What the call returns, and what the answer is

These are **two different numbers**, which is the whole problem:

- `func(root)` **returns** the height of the subtree: the number of nodes on
  the longest path from `root` straight down. Exactly LC 104.
- The **answer** is the longest path between *any* two nodes, counted in
  edges. It's kept in the member `diameter` and updated on the side.

**Returns** a height. **Passes down** nothing. **Updates** a running maximum.

## Recursive case

```cpp
int lHeight = func(root->left);
int rHeight = func(root->right);

diameter = max(diameter, lHeight + rHeight);

return max(lHeight, rHeight) + 1;
```

Every path in a tree has one highest node, where it turns from going up to
going down. A path whose highest node is `root` goes down the left as far as
it can and down the right as far as it can: `lHeight + rHeight` edges. Each
node checks that one candidate, so every possible turning point is checked
once.

But the parent can't use that path: a path can't fork. What the parent
needs is the longest path going **straight down** through this node, the
height. So the function returns the height and only *records* the diameter.

## Base case

```cpp
if (root == nullptr) return 0;
```

An empty subtree has height 0, so a leaf's candidate is `0 + 0 = 0` edges and
its height is 1.

## Heights in nodes, diameter in edges

`lHeight + rHeight` counts **edges** without any `- 1` because each child's
height (in nodes) is exactly the number of edges from *this* node down that
side: one edge to the child, then height − 1 more below it.

## Resetting `diameter`

`diameter = 0;` at the top of `diameterOfBinaryTree` matters when the same
`Solution` object is reused: without it, a second call would start from the
first call's maximum. Don't rely on the judge creating a fresh object for
each test; the harness reuses one object on purpose, and with the reset it
passes.

## Complexity

Time: **O(n)**, one visit per node, compared with the O(n²) of computing
heights separately at every node.
Space: **O(h)** stack.

## Tested

LeetCode's two examples, one node (0), a chain, and a tree whose longest path
doesn't pass through the root (6 edges, all under node 2; through the root
it's only 4). Also 500 random trees, each checked against an O(n²) reference
that recomputes heights at every node.

## Key insight

Return the height upward; record the diameter on the side. They are different numbers.
