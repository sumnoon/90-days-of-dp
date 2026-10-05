# ⭐ LC 78: Subsets

- **Solutions:**
  [`solutions/lc0078_subsets_include_exclude.cpp`](../solutions/lc0078_subsets_include_exclude.cpp) (include / exclude) ·
  [`solutions/lc0078_subsets.cpp`](../solutions/lc0078_subsets.cpp) (for loop from a start index)
- **Day:** 15 (Mon), both versions
- **Solved without help?** yes
- **Videos:** Striver's recursion playlist L6 (subsequences), L7 (patterns); L10 (subset sum I) after solving

## What the call does

`backtrack(start, cur, nums)` produces every subset whose choices for
`nums[0 .. start-1]` are already fixed in `cur`, and appends them to `ans`.

**Returns** nothing. **Passes down** the index to decide next, and `cur`, by
reference: the one vector every call shares. This is Week 2's traversal
pattern (`ans` by reference) plus one new step: **undo** the change before
returning.

## Version 1: include / exclude

```cpp
if (start == nums.size()) { ans.push_back(cur); return; }

backtrack(start + 1, cur, nums);   // exclude nums[start]
cur.push_back(nums[start]);        // choose
backtrack(start + 1, cur, nums);   // include nums[start]
cur.pop_back();                    // un-choose
```

One decision per level: take `nums[start]` or don't. Each element doubles the
number of paths, so the tree has **2ⁿ leaves**, one per subset, and a subset
is only recorded at a leaf, once every element has been decided.

## Version 2: for loop from a start index

```cpp
ans.push_back(cur);

for (int i = start; i < nums.size(); ++i) {
    cur.push_back(nums[i]);        // choose
    backtrack(i + 1, cur, nums);   // explore
    cur.pop_back();                // un-choose
}
```

Here each call answers a different question: *which element comes next?*
Every node of this tree is already a subset, so it is recorded on entry, and
there's no base case: when `start == nums.size()` the loop just runs zero times.
Recursing with `i + 1` means only later elements can follow, so `{1, 2}` is
built but `{2, 1}` never is. This is the shape LC 77, 39, 40 and 90 reuse.

## Why `pop_back` matters

`cur` is shared by every call. After exploring "with `nums[i]`", the next
option must start from the same `cur` as before, so the choice is undone.
Without the `pop_back`, `cur` keeps growing and every later subset includes
leftovers from earlier branches.

## The two trees

For `[1, 2, 3]`, output order as measured:

| Version | Order |
|---|---|
| include / exclude (exclude first) | [] [3] [2] [2,3] [1] [1,3] [1,2] [1,2,3] |
| for loop from start | [] [1] [1,2] [1,2,3] [1,3] [2] [2,3] [3] |

Same 8 subsets. Version 1 makes 2ⁿ⁺¹ − 1 calls (a full binary tree); version 2
makes exactly 2ⁿ, one per subset.

## Complexity

Time: **O(n · 2ⁿ)**: 2ⁿ subsets, each copied into `ans` in up to O(n).
Space: **O(n)** for the stack and `cur`, plus the output.

## Small notes on the code

- `ans` is a **member** and is never cleared, so calling `subsets` twice on
  the same object returns both answers glued together. It's accepted on
  LeetCode, but it's the same trap as LC 543's `diameter`, which you did
  reset. Clearing it at the start of `subsets`, or making it a local
  passed by reference, avoids it.
- `i < nums.size()` and `start == nums.size()` compare an `int` with an
  unsigned `size_t`, and `-Wall` warns about it (`-Wsign-compare`). Harmless
  here, since neither side is ever negative, but `(int)nums.size()` silences it.

## Tested

LeetCode's two examples, `[-1, 5]`, and ten numbers (LeetCode's maximum): each
time exactly 2ⁿ subsets, all distinct, matching a bitmask reference where
subset k takes `nums[i]` when bit i of k is set.

## See it

- **Choose, explore, un-choose:** https://sumnoon.github.io/90-days-of-dp/subsets/ —
  both versions as decision trees, one box per call, with the `cur` strip
  growing on each push and shrinking on each pop. Compare the call counts:
  15 against 8 for `[1, 2, 3]`. ([source](../../../docs/subsets/index.html))

## Key insight

Choose, explore, un-choose: the shared `cur` must look the same after a call as it did before.
