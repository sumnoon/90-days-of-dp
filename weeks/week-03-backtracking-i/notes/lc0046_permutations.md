# ⭐ LC 46: Permutations

- **Solution:** [`solutions/lc0046_permutations.cpp`](../solutions/lc0046_permutations.cpp)
- **Day:** 18 (Thu)
- **Solved without help?** hint: graded hints on why `i + 1` no longer works and what `used[]` is for
- **Video, after solving:** Striver's recursion playlist L12 (approach 1, the `used` array) and L13 (approach 2, swapping)

## What the call does

`backtrack(idx, cur, nums)` appends every permutation that starts with `cur`
and continues with the numbers not yet used.

**Returns** nothing. **Passes down** `cur` and `used`, both shared: `cur` by
reference, `used` as a member. (`idx` is passed too, but never read; see
below.)

## Recursive case

```cpp
for (int i = 0; i < nums.size(); ++i) {
    if (used[i]) continue;
    used[i] = true;
    cur.push_back(nums[i]);
    backtrack(i, cur, nums);
    used[i] = false;
    cur.pop_back();
}
```

**Every level loops over all of `nums`, from 0.** In LC 77 and LC 78 the loop
started at a start index so only later numbers could follow: that's what
made `[2, 1]` impossible, which was right because order didn't matter. In a
permutation it does, so after choosing 2, the 1 must still be on offer.

**`used[]` replaces the start index.** Looping from 0 every time would allow
`[1, 1, 2]`; `used[i]` skips any number already in `cur`. Choosing now changes
**two** pieces of shared state, `used` and `cur`, so both are undone after the
call. The order of the two undo lines doesn't matter: they're independent.

## Base case

```cpp
if (cur.size() == nums.size()) { ans.push_back(cur); return; }
```

Every number placed: record and stop. Every leaf is at depth n and every leaf
is an answer, so there's nothing to prune.

## The tree

The root has n choices, each child n − 1, then n − 2, … so there are
n · (n − 1) · … · 1 = **n!** leaves: 6 for `[1, 2, 3]`, 720 for six numbers
(LeetCode's maximum).

## Small notes on the code

- **`idx` is never read.** The recursive call passes `i`, but the body
  loops from 0 regardless, and `-Wextra` warns `unused parameter 'idx'`. It's
  left over from the start-index pattern; with `used[]` it has no job, so it
  can go.
- `used` is a **member**, resized in `permute`. `resize(n, false)` only sets
  *new* elements to false, so reusing one object for a second, longer input
  would keep stale values in the old slots. With a fresh object per call it's
  fine; `used.assign(n, false)` would be safe either way. `ans` is never
  cleared, as before.
- `i < nums.size()` compares `int` with an unsigned size, as in LC 78.

## Complexity

Time: **O(n · n!)**: n! permutations, each copied in O(n). Each node also
scans all n slots of `used`.
Space: **O(n)** for the stack, `cur` and `used`, plus the output.

## Tested

LeetCode's three examples, `[3, -1, 7, 0]`, and `[6, 5, 4, 3, 2, 1]`
(720 permutations): each time exactly n! distinct permutations, matching
`std::next_permutation` run from the sorted order.

## See it

- **Choose, explore, un-choose:** https://sumnoon.github.io/90-days-of-dp/subsets/ —
  pick *LC 46 permutations* to watch the `used` strip alongside `cur`: both
  set before each call, both undone after, and every skipped slot shown.
  ([source](../../../docs/subsets/index.html))

## Key insight

Order matters, so every level may pick any number; `used[]` is what stops a number being picked twice.
