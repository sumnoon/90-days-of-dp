# CSES: Dice Combinations

- **Solution:** [`solutions/cses_dice_combinations.cpp`](../solutions/cses_dice_combinations.cpp)
- **Problem:** https://cses.fi/problemset/task/1633
- **Day:** 35 (Week 5 Sun), solved on Wed 28 Oct
- **Solved without help?** The memoized and table versions, yes (the table
  after a hint about recursion depth). The O(1)-space version needed the fix
  explained, so it's on the [redo list](../../../redo-list.md).

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

## Three versions

- **Memoized, `calc`:** the same recurrence, top-down. It's correct, but the
  recursion is **one call deep per unit of `n`**: a million calls at CSES's
  limit. That crashes with Windows' default stack (already at n ≈ 50,000),
  and with a 256 MB stack it runs.
- **Table, `calcTab`:** what `main` uses. Filling `memo[1]`, `memo[2]`, …
  in order means `memo[i − 6 … i − 1]` are always ready, and there's no
  recursion. n = 1,000,000 takes about 0.2 s with the normal stack.

- **O(1) space, `calcConst`:** what `main` uses now. See below.

This is the practical reason to know the table form: same answers, but no
recursion depth limit.

## O(1) space: six slots, indexed by `i % 6`

```cpp
int ret[6] = {1, 0, 0, 0, 0, 0};          // ways(0) = 1; ways(-1..-5) = 0
for (int i = 1; i <= n; ++i) {
    int sum = 0;
    for (int j = 0; j < 6; ++j) sum = (sum + ret[j]) % mod;
    ret[i % 6] = sum;                     // overwrites ways(i - 6), which is no longer needed
}
```

The table only reads its last six entries, so keep those in six slots, with
`ways(i)` stored in slot `i % 6`. Just before step `i`, the slots hold exactly
`ways(i − 6) … ways(i − 1)` in some order, and their sum is `ways(i)`.

**The bug in the first attempt** added into slot `i % 6` *while* reading:

- the slot started out holding `ways(i − 6)`;
- then `j = 6` read that same slot again, by which time it held the sum built
  so far.

Every answer from n = 6 on came out wrong, starting at **double**: 64 instead
of 32. The rule: when an update reads storage it's about to overwrite, compute
the new value in a separate variable first and write it last. That's the same
reason House Robber uses `next`.

## Modulo

The six terms are added one at a time, each followed by `% mod`. Before
reducing, the largest a sum can be is about 2 × 10⁹, still under `INT_MAX`
(2.147 × 10⁹). So `int` is enough, but only because it's reduced after
**every** addition.

## Small notes on the code

- `main` still calls `memo.resize(n + 1)`, allocating a million `int`s that
  `calcConst` never touches. Drop it when using `calcConst` to make the whole
  program O(1) space.
- `calc` is no longer called. If it were, it would need the vector filled with
  −1 first: `main` now resizes with zeros, which `calc` would read as "already
  computed, 0 ways".
- In `calc`, `if (n < 0) return 0;` never runs, because the loop skips
  `n - i < 0`. And `ret % mod` is a no-op, since `ret` is always below `mod`.
- `if (i - j < 0) continue;` in `calcTab` could be the loop bound instead:
  `j <= min(6, i)`. `calcConst` needs no such check: the zeros in the starting
  slots stand in for the negative sums.

## Complexity

O(6n) time for all three. O(n) space for the memo and table versions; O(1)
for `calcConst`.

## Tested

CSES's example (n = 3 gives 4); every n from 1 to 60; n = 100, 1,000,
54,321 and 999,999; and n = 1,000,000, which gives 874,273,980 in about
0.2 s. The table and O(1) versions were each checked against a separate
bottom-up count.

## Key insight

Split on the last throw: ways(i) = ways(i − 1) + … + ways(i − 6). Fill in order to drop the recursion, then keep only the last six values, summing before you overwrite.
