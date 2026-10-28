# CSES: Dice Combinations

- **Solution:** [`solutions/cses_dice_combinations.cpp`](../solutions/cses_dice_combinations.cpp)
- **Problem:** https://cses.fi/problemset/task/1633
- **Day:** 35 (Week 5 Sun), solved on Wed 28 Oct
- **Solved without help?** yes. The table version came after a hint about
  recursion depth.

Count the ways to make a sum `n` by throwing a die (1–6) any number of times,
where order matters (`1+2` and `2+1` are different), modulo 10⁹ + 7.

## State

`memo[i]` = **the number of ways to make the sum `i`**.

## Transition

```cpp
for (int j = 1; j <= 6; ++j)
    if (i - j >= 0) memo[i] = (memo[i] + memo[i - j]) % mod;
```

Split on the **last throw**. If it was `j`, the throws before it made `i − j`.
Every way ends with exactly one last throw, so the six counts add. It's LC 70
with six step sizes instead of two.

## Base case

`memo[0] = 1`: one way to make 0, by throwing nothing. Without it, every count
would stay 0.

## Two versions

- **Memoized, `calc`:** the same recurrence, top-down. It's correct, but the
  recursion is **one call deep per unit of `n`**: a million calls at CSES's
  limit. That crashes with Windows' default stack (already at n ≈ 50,000),
  and with a 256 MB stack it runs.
- **Table, `calcTab`:** what `main` uses. Filling `memo[1]`, `memo[2]`, …
  in order means `memo[i − 6 … i − 1]` are always ready, and there's no
  recursion. n = 1,000,000 takes about 0.2 s with the normal stack.

This is the practical reason to know the table form: same answers, but no
recursion depth limit.

## Modulo

The six terms are added one at a time, each followed by `% mod`. Before
reducing, the largest a sum can be is about 2 × 10⁹, still under `INT_MAX`
(2.147 × 10⁹). So `int` is enough, but only because it's reduced after
**every** addition.

## Small notes on the code

- `calc` is no longer called. If it were, it would need the vector filled with
  −1 first: `main` now resizes with zeros, which `calc` would read as "already
  computed, 0 ways".
- In `calc`, `if (n < 0) return 0;` never runs, because the loop skips
  `n - i < 0`. And `ret % mod` is a no-op, since `ret` is always below `mod`.
- `if (i - j < 0) continue;` in `calcTab` could be the loop bound instead:
  `j <= min(6, i)`.

## Complexity

O(6n) time, O(n) space. The table only reads its last six entries, so six
variables (or a ring of six) would do in O(1) space.

## Tested

CSES's example (n = 3 gives 4); n = 1–7, 10, 50, 100, 1,000, 54,321 and
999,999; and n = 1,000,000, which gives 874,273,980. Each was checked against a
separate bottom-up count.

## Key insight

Split on the last throw: ways(i) = ways(i − 1) + … + ways(i − 6). Filling the table in order removes the recursion and its million-call depth.
