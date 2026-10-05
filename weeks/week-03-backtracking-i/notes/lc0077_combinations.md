# ⭐ LC 77: Combinations

- **Solution:** [`solutions/lc0077_combinations.cpp`](../solutions/lc0077_combinations.cpp)
- **Day:** 16 (Tue)
- **Solved without help?** yes

## What the call does

`func(cur, idx, n, k)` records every combination of size `k` that starts with
`cur` and continues with numbers from `idx` to `n`.

**Returns** nothing. **Passes down** `cur` by reference (choose / un-choose)
and `idx`, the smallest number still allowed.

## Recursive case

```cpp
for (int i = idx; i <= n; ++i) {
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
if (cur.size() == k) ans.push_back(cur);
```

Record once `cur` holds `k` numbers.

## Open question: what happens after recording?

The call records, then **keeps going**: the loop still pushes more numbers
onto a `cur` that is already full. Those deeper calls can never record
anything, because `cur.size()` only grows past `k`. The output is right, but
the code walks the **entire subsets tree** of LC 78 and keeps only one layer.
Measured, with an instrumented copy:

| n, k | combinations | calls as written | with an early `return` | with pruning too |
|---|---|---|---|---|
| 4, 2 | 6 | 16 | 11 | 10 |
| 10, 3 | 120 | 1,024 | 176 | 165 |
| 20, 2 | 190 | 1,048,576 | 211 | 210 |
| 20, 10 | 184,756 | 1,048,576 | 616,666 | 352,716 |
| 20, 18 | 190 | 1,048,576 | 1,048,555 | 1,330 |

As written it is always 2ⁿ calls, whatever `k` is.

- **Return after recording** stops a branch from growing past `k`. That's the
  big win when `k` is small.
- **Pruning** stops a branch from starting when there aren't enough numbers
  left to *reach* `k`. That's the big win when `k` is close to `n`: for
  (20, 18) a full `cur` is rare, but hopeless branches are everywhere.

Both are worth working out before Saturday's problems; the pruning question
is: *with `cur.size()` numbers chosen, what is the largest `i` that can still
lead to a full combination?*

## Complexity

Output size: C(n, k) combinations of length k.
As written: **O(2ⁿ)** calls. With the return and pruning, the work is
proportional to the output, **O(k · C(n, k))**.
Space: **O(k)** for `cur` and the stack, plus the output.

## Small notes on the code

- `cur.size() == k` compares an unsigned size with an `int`, which `-Wall`
  warns about, as in LC 78.
- `ans` is again a member that's never cleared.

## Tested

(4, 2), (1, 1), (5, 5), (5, 1), (10, 3), (20, 2), (20, 10): each time exactly
C(n, k) combinations, all distinct, matching a reference that takes every
bitmask of n bits with k set.

## Key insight

LC 78's for-loop tree, keeping one layer: a call with `k` numbers is finished.
