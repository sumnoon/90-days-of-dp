# ⭐ LC 39: Combination Sum

- **Solution:** [`solutions/lc0039_combination_sum.cpp`](../solutions/lc0039_combination_sum.cpp)
- **Day:** 19 (Fri)
- **Solved without help?** yes
- **Video, after solving:** Striver's recursion playlist L8 (combination sum)

## What the call does

`backtrack(idx, cur, candidates, target)` records every way to finish `cur`
using `candidates[idx..]`, any number of times each, adding up to exactly the
remaining `target`.

**Returns** nothing. **Passes down** `cur` by reference, `idx` (the first
candidate still allowed), and `target`, the amount **still missing**: the
LC 112 Path Sum idea, a value that shrinks on the way down.

## Recursive case

```cpp
for (int i = idx; i < candidates.size(); ++i) {
    if (candidates[i] <= target) {
        cur.push_back(candidates[i]);
        backtrack(i, cur, candidates, target - candidates[i]);
        cur.pop_back();
    }
}
```

**Recursing with `i`, not `i + 1`,** is the whole difference from LC 77: the
number just used is still on offer, so `[2, 2, 3]` can be built. Starting at
`i` rather than 0 still keeps each combination in non-decreasing *index*
order, so `[2, 3, 2]` and `[3, 2, 2]` are never built and nothing is
duplicated.

**What stops it:** nothing runs out any more; only the target does. Every
candidate is at least 2 (LeetCode's constraint), so each step down shrinks
the target and the depth is at most `target / min(candidates)`.

## Base cases

```cpp
if (target == 0) { ans.push_back(cur); return; }
if (target < 0) return;
```

- `target == 0`: `cur` adds up exactly. Record and stop.
- `target < 0` **never happens here**: the loop only recurses when
  `candidates[i] <= target`, so the remaining target is never driven below 0.
  The guard is harmless but unreachable. One of the two checks is enough:
  either test before recursing (as the loop does) or return on `target < 0`.

## Pruning that's still available

The input isn't sorted, so the loop has to look at every candidate and skip
the ones that are too big. **Sort `candidates` first** and the first
candidate that's too big means every later one is too, so the loop can
`break` instead of `continue`. It doesn't change the calls made, only how many
candidates each call checks.

## Complexity

Exponential in the worst case: up to `target / min(candidates)` levels with
up to n branches each. LeetCode guarantees fewer than 150 answers, so the
output stays small.
Space: **O(target / min)** for the stack and `cur`, plus the output.

## Small notes on the code

- `i < candidates.size()` compares `int` with an unsigned size (`-Wall`
  warns), as before.
- `ans` is a member that's never cleared, as before.

## Tested

LeetCode's three examples, `[1]` with target 1, an unsorted `[7, 3, 2]` with
target 18, `[2, 7, 6, 3, 5, 1]` with target 9 (21 answers), `[8, 7, 4, 3]`
with target 11, and LeetCode's largest target, `[2, 3, 5]` with 40
(34 answers). Each answer sums to the target, none repeats, and the set
matches a reference that decides, candidate by candidate, how many copies to
take.

## See it

- **Choose, explore, un-choose:** https://sumnoon.github.io/90-days-of-dp/subsets/ —
  pick *LC 39 combination sum*: each box shows `cur` and the target still
  missing, a `+2` can follow a `+2`, and the dead ends where nothing fits are
  dashed. ([source](../../../docs/subsets/index.html))

## Key insight

Recurse with `i` to allow reuse, not `i + 1`; the shrinking target, not the candidates, is what ends each branch.
