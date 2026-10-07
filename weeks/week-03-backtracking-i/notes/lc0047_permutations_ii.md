# LC 47: Permutations II

- **Solution:** [`solutions/lc0047_permutations_ii.cpp`](../solutions/lc0047_permutations_ii.cpp)
- **Day:** 20 (Sat)
- **Solved without help?** solution: graded hints first, then the duplicate condition was shown and explained
- **Video, after solving:** Striver's recursion playlist L13 (permutations by swapping)

## What the call does

`backtrack(idx, cur, nums)` records every **distinct** ordering that starts
with `cur` and continues with the numbers not yet used.

**Returns** nothing. **Passes down** `cur` and `used`, as in LC 46. (`idx`
is passed but never read, as in LC 46.)

## Recursive case

```cpp
for (int i = 0; i < nums.size(); ++i) {
    if (i > 0 && nums[i] == nums[i - 1] && used[i - 1]) continue;
    if (!used[i]) {
        used[i] = true;
        cur.push_back(nums[i]);
        backtrack(i + 1, cur, nums);
        cur.pop_back();
        used[i] = false;
    }
}
```

LC 46 plus `sort` and one skip. Label the equal values in sorted order, say
`1a, 1b` in `[1, 1, 2]`. Plain LC 46 builds both `1a, 1b, 2` and `1b, 1a, 2`:
the same answer twice. Every duplicate is the same arrangement with equal
values in a different order, so **fix one order for equal values** and
refuse the other.

## The two versions of the skip

| Condition | Order it enforces | When a duplicate branch dies |
|---|---|---|
| `nums[i] == nums[i-1] && !used[i-1]` | equal values left to right (1a before 1b) | **immediately**, at the level where it would start |
| `nums[i] == nums[i-1] && used[i-1]` (this solution) | right to left (1b before 1a) | **later**: the branch starts, then dies deeper when the remaining copies can't be placed |

Both are correct. They keep a different copy of each answer, and do very
different amounts of work. Measured, with an instrumented copy:

| Input (sorted) | Answers | Calls with `!used[i-1]` | Calls with `used[i-1]` |
|---|---|---|---|
| 1 1 2 | 3 | 9 | 12 |
| 1 1 1 | 1 | 4 | 9 |
| 1 1 1 1 2 | 5 | 20 | 96 |
| 1 1 1 2 2 2 3 3 | 560 | 1,749 | 8,496 |
| eight 1s | 1 | 9 | 2,781 |

With `!used[i-1]`, the second copy can't start a level while the first copy
is free, so each duplicate subtree is cut at its root. With `used[i-1]`, a
copy can be placed and the branch only fails deeper down, after visiting
many calls that lead nowhere. **Prefer `!used[i-1]`.**

## Base case

```cpp
if (cur.size() == nums.size()) { ans.push_back(cur); return; }
```

## Complexity

Time: **O(n · n!)** in the worst case (all distinct, it's LC 46); fewer with
duplicates, especially with `!used[i-1]`.
Space: **O(n)** plus the output.

## Small notes on the code

- `used.resize(n, false)` and the never-cleared `ans` member, as in LC 46.
- The duplicate check runs before `used[i]`, so the order of the two checks
  doesn't matter here, but checking `used[i]` first reads more naturally.

## Tested

LeetCode's two examples, `[1, 1, 1]` (1 answer), `[2, 1, 2, 1]` (6),
`[3, 3, 0, 3]` (4), and eight numbers `[1,1,2,2,3,3,1,2]` (560): each matches
`std::next_permutation` from the sorted order, with no duplicates.

## Key insight

Sort so equal values are neighbours, then never place a copy before the copy to its left: `!used[i-1]` cuts each duplicate branch at its root.
