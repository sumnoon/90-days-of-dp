# ⭐ LC 77: Combinations

- **Solution:** [`solutions/lc0077_combinations.cpp`](../solutions/lc0077_combinations.cpp)
- **Day:** 16 (Tue)
- **Solved without help?** yes; the early `return` after a nudge, and the pruning bound after graded hints

## What the call does

`func(cur, idx, n, k)` records every combination of size `k` that starts with
`cur` and continues with numbers from `idx` to `n`.

**Returns** nothing. **Passes down** `cur` by reference (choose / un-choose)
and `idx`, the smallest number still allowed.

## Recursive case

```cpp
int need = k - cur.size();
int remain = n - idx + 1;
int available = remain - need;

for (int i = idx; i <= idx + available; ++i) {
    cur.push_back(i);
    func(cur, i + 1, n, k);
    cur.pop_back();
}
```

LC 78's for-loop version, almost line for line. Recursing with `i + 1` means
numbers only ever go up within `cur`, so `[1, 2]` is built and `[2, 1]` never
is: each combination exactly once.

## Base case

```cpp
if (cur.size() == k) {
    ans.push_back(cur);
    return;
}
```

Record once `cur` holds `k` numbers, and **stop**: a full `cur` can't take
another number.

## Two fixes, measured

The first version recorded, then **kept going**: the loop still pushed more numbers
onto a `cur` that was already full. Those deeper calls could never record
anything, because `cur.size()` only grows past `k`. The output was right, but
the code walked the **entire subsets tree** of LC 78 and kept only one layer.
Measured, with an instrumented copy of each version:

| n, k | combinations | first version | + `return` | + pruning (current) |
|---|---|---|---|---|
| 4, 2 | 6 | 16 | 11 | 10 |
| 10, 3 | 120 | 1,024 | 176 | 165 |
| 20, 2 | 190 | 1,048,576 | 211 | 210 |
| 20, 10 | 184,756 | 1,048,576 | 616,666 | 352,716 |
| 20, 18 | 190 | 1,048,576 | 1,048,555 | 1,330 |

The first version was always 2ⁿ calls, whatever `k` is. Both fixes were
added on Day 16, and the current file's counts match the last column exactly.

- **Return after recording** stops a branch from growing past `k`. That's the
  big win when `k` is small.
- **Pruning** stops a branch from starting when there aren't enough numbers
  left to *reach* `k`. That's the big win when `k` is close to `n`: for
  (20, 18) a full `cur` is rare, but hopeless branches are everywhere.

## The pruning bound

`need = k - cur.size()` numbers are still missing. Picking `i` leaves only
the numbers from `i` to `n` to choose from, `n - i + 1` of them, so a branch
can only succeed while `n - i + 1 >= need`, that is `i <= n - need + 1`.

The code reaches the same bound in its own words: `remain` counts the numbers
from `idx` to `n`, and `available = remain - need` is how many of them can be
**skipped** before the rest are all needed. So `i` may go `available` past
`idx`: `idx + available = n - need + 1`.

Worked hint for `n = 5, k = 3`: with `cur` empty the loop stops at 3
(`3, 4, 5` is the last full run); with `cur = [1, 2]` it goes to 5.

## Complexity

Output size: C(n, k) combinations of length k.
First version: **O(2ⁿ)** calls. With the return it is far fewer when `k`
is small, but still about 2ⁿ when `k` is close to `n`. With pruning too,
every call is on the way to a combination, so the work is proportional to the
output, **O(k · C(n, k))**.
Space: **O(k)** for `cur` and the stack, plus the output.

## Small notes on the code

- `cur.size() == k` compares an unsigned size with an `int`, which `-Wall`
  warns about, as in LC 78.
- `ans` is again a member that's never cleared.

## Tested

(4, 2), (1, 1), (5, 5), (5, 1), (10, 3), (20, 2), (20, 10): each time exactly
C(n, k) combinations, all distinct, matching a reference that takes every
bitmask of n bits with k set.

## See it

- **Choose, explore, un-choose:** https://sumnoon.github.io/90-days-of-dp/subsets/ —
  pick *LC 77 combinations* and switch between the three versions: the first
  walks all 32 calls of the subsets tree for n = 5, the return trims what
  hangs below a full `cur`, and the pruning leaves no wasted call at all.
  ([source](../../../docs/subsets/index.html))

## In my own words

call records list combination of k number from list of n numbers. It passed down next index of number list and cur. the choice is undone after the recursive function is called. the complexity is O(k * C(n, k)) where n is total numbers and k is numbers size to choose. The idea that unlocks stops the call when cur is size of k and if a branch don't have enough numbers than don't proceed the calling

## Key insight

LC 78's for-loop tree, keeping one layer. Stop a branch once it's full, and don't start one that can't fill up.
