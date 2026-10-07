# ⭐ LC 90: Subsets II

- **Solution:** [`solutions/lc0090_subsets_ii.cpp`](../solutions/lc0090_subsets_ii.cpp)
- **Day:** 20 (Sat)
- **Solved without help?** yes
- **Video, after solving:** Striver's recursion playlist L11 (subset sum II)

## What the call does

`backtrack(idx, cur, nums)` records `cur`, then every distinct subset that
extends it with numbers from `nums[idx..]`.

**Returns** nothing. **Passes down** `cur` by reference and `idx`, exactly as
in LC 78's for-loop version.

## Recursive case

```cpp
for (int i = idx; i < nums.size(); ++i) {
    if (i != idx && nums[i] == nums[i - 1]) continue;
    cur.push_back(nums[i]);
    backtrack(i + 1, cur, nums);
    cur.pop_back();
}
```

The only new line is the skip. With `nums` **sorted**, equal values sit next
to each other. At one level, the loop chooses *which value comes next*;
choosing the second `2` after already trying the first `2` at this same level
would build exactly the same subtree again. So each value is tried **once
per level**: the first copy only.

`i != idx` is what makes it "per level". The first iteration of a level is
always allowed, even if it equals the number before it, because that number
was placed by the level **above**, not tried here. That's how `[2, 2]` still
gets built.

## Base case

None needed: every call is a subset and is recorded on entry; when `idx`
reaches the end, the loop runs zero times.

## Why sorting is required

The skip only compares neighbours. Without `sort`, `[2, 1, 2]` keeps the two
2s apart, the check never sees them as a pair, and `[1, 2]` / `[2, 1]` style
duplicates come out as separate subsets.

## Complexity

Time: **O(n · 2ⁿ)** in the worst case (no duplicates, it's LC 78); with
duplicates, fewer calls, one per distinct subset.
Space: **O(n)** for the stack and `cur`, plus the output.

## Small notes on the code

- `i < nums.size()` compares `int` with an unsigned size (`-Wall`).
- `ans` is a member that's never cleared.

## Tested

LeetCode's two examples, `[2, 2, 2]` (4 subsets), an unsorted
`[4, 4, 4, 1, 4]` (10), and ten numbers with three values repeated (80): no
duplicates, and the same set as a reference that takes every bitmask subset
and keeps each sorted one once.

## Key insight

Sort, then at each level try each value only once: skip a copy unless it's the first one this level tried.
