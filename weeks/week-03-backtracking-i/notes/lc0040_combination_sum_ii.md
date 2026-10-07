# LC 40: Combination Sum II

- **Solution:** [`solutions/lc0040_combination_sum_ii.cpp`](../solutions/lc0040_combination_sum_ii.cpp)
- **Day:** 20 (Sat)
- **Solved without help?** yes
- **Video, after solving:** Striver's recursion playlist L9 (combination sum II)

## What the call does

`backtrack(idx, cur, candidates, target)` records every distinct way to
finish `cur` with candidates from `idx` onwards, **each used at most once**,
adding up to exactly the remaining `target`.

**Returns** nothing. **Passes down** `cur` by reference, `idx`, and the
remaining `target`.

## Recursive case

```cpp
for (int i = idx; i < candidates.size(); ++i) {
    if (i != idx && candidates[i] == candidates[i - 1]) continue;
    if (candidates[i] <= target) {
        cur.push_back(candidates[i]);
        backtrack(i + 1, cur, candidates, target - candidates[i]);
        cur.pop_back();
    }
}
```

Two earlier problems glued together:

- From **LC 39**: the shrinking target, and recording at `target == 0`.
  But each candidate may be used only once, so recurse with **`i + 1`**,
  not `i`.
- From **LC 90**: `sort`, then skip a value at the same level if it equals
  the one before it, so equal candidates don't produce the same combination
  twice.

## More than two equal values

The skip compares each value with its **left neighbour**, not with the copy
that was tried. Sorting puts equal values in one unbroken run, so every copy
after the first in the run has an equal neighbour and is skipped, however
long the run is. With `[1, 1, 1]`, target 2:

- **Level 1** (`idx = 0`): index 0 is taken; index 1 equals index 0, skipped;
  index 2 equals index 1, skipped.
- **Level 2** (`idx = 1`): index 1 is the **first** iteration of this level
  (`i == idx`), so it's allowed: `[1, 1]` is recorded. Index 2 equals index 1,
  skipped.

So copies can be **used** one per level, going deeper, but the same value
is only **tried** once per level. Each distinct answer is built once: one
`[1, 1]`, not three.

## Base cases

```cpp
if (target == 0) { ans.push_back(cur); return; }
if (target < 0) return;
```

As in LC 39, `target < 0` is unreachable: the loop only recurses when
`candidates[i] <= target`.

## Pruning that's free here

The candidates are already **sorted** (the duplicate skip needs it), so the
first candidate bigger than `target` means every later one is too. The loop
could `break` there instead of checking the rest.

## Complexity

Exponential in the worst case, up to 2ⁿ subsets for n ≤ 100 candidates, but
the target (≤ 30) cuts it hard: no branch goes deeper than the target allows.
Space: **O(n)** plus the output.

## Tested

LeetCode's two examples, three 1s with target 2, five 1s with target 3,
`[2]` with target 1 (no answer), `[3, 1, 3, 5, 1, 1]` with target 8, and ten
numbers with repeats, target 10 (12 answers): no duplicates, and the same set
as a reference that checks every bitmask subset.

## Key insight

LC 39 with `i + 1` instead of `i`, plus LC 90's skip: the same value is tried once per level but can be used once per level going down.
