# ⭐ LC 746: Min Cost Climbing Stairs

- **Solution:** [`solutions/lc0746_min_cost_climbing_stairs.cpp`](../solutions/lc0746_min_cost_climbing_stairs.cpp)
- **Day:** 31 (Wed), solved on Thu 22 Oct
- **Solved without help?** yes

## State: what the call returns

`func(idx, cost)` returns **the cheapest way to get from step `idx` to the
top, counting `cost[idx]`**: standing on a step means paying for it. The top
is past the last step, at index `n`.

The answer is `min(func(0), func(1))`, because you may start on either of
the first two steps.

## Recurrence

```cpp
return memo[idx] = cost[idx] + min(func(idx + 1, cost), func(idx + 2, cost));
```

Pay for this step, then take whichever next move (1 step or 2) is cheaper
from there. It's LC 70's shape with **`min` in place of `+`**: LC 70 counts
*all* the ways, and this one keeps the *best* way.

## Base case

```cpp
if (idx >= cost.size()) return 0;
```

At the top (`idx == n`) or past it (`n + 1`, from a 2-step off the last
step), there's nothing left to pay.

## Small notes on the code

- `memo.resize(n + 1, -1)`: index `n` is never stored, because the base case
  returns first. `n` slots would do.
- `resize` only sets the **new** slots to −1. If one `Solution` object were
  reused for a second, longer array, the old answers would still be in the
  first slots. LeetCode makes a new object per test, so it's fine there;
  `memo.assign(n, -1)` would be safe either way.
- −1 works as "not computed" because no cost is negative.
- `func(1)` is already in the cache by the time `min` needs it: `func(0)`
  computes it on the way down. So the second call is just a lookup.
- `idx >= cost.size()` compares `int` with an unsigned size (`-Wall`).

## Complexity

Each `idx` is computed once: **O(n)** time, O(n) memo plus O(n) stack. 1,000
steps (LeetCode's limit) take under 0.1 ms.

## Tested

- LeetCode's two examples
- small cases: `[0, 0]`, `[5, 3]`, `[999, 999]` and `[0, 0, 0, 0]`
- 500 random arrays of 2–22 steps with costs 0–999, each matching a brute
  force that tries every path with no cache
- 1,000 steps of cost 999, which gives 499,500

Each test uses a fresh `Solution`.

## Key insight

Same moves as LC 70, but keep the cheapest instead of counting them all: cost(i) = cost[i] + min(cost(i + 1), cost(i + 2)).
