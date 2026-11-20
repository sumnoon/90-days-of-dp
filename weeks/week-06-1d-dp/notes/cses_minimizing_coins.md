# CSES: Minimizing Coins

- **Solution:** [`solutions/cses_minimizing_coins.cpp`](../solutions/cses_minimizing_coins.cpp)
- **Problem:** https://cses.fi/problemset/task/1634
- **Day:** 42 (Week 6 Sun), solved on Fri 20 Nov
- **Solved without help?** No. It took three rounds of hints, so it's on the
  [redo list](../../../redo-list.md).

[LC 322](lc0322_coin_change.md) with CSES's input and output: n ≤ 100 coins,
a target x ≤ 1,000,000, and −1 if x can't be made.

## State

`memo[j]` = **the fewest coins that make exactly `j`**, using the coins
processed so far.

## Transition

```cpp
for (int i = 0; i < n; ++i)
    for (int j = coins[i]; j <= x; ++j)
        memo[j] = min(memo[j], 1 + memo[j - coins[i]]);
```

This is LC 322's 2D table squeezed into one row. Row `i` only read the row
above (skip coin `i`) and its own row to the left (take coin `i` again), so
one array does both:

- before the update, `memo[j]` still holds the row above;
- `memo[j - coins[i]]` has already been updated in this pass, so it's "this
  row, to the left". That's what lets a coin be used **again**.

Running `j` **upwards** is what makes coins reusable. Running it downwards
would make each coin usable once: the 0/1 knapsack in Week 9.

## Base case

`memo[0] = 0`, and every other amount starts at `INT_MAX - 1`, meaning
impossible.

## The three rounds

1. **Memoized on `amount` alone, recursive.** The state was `(idx, amount)`,
   but the memo was indexed by `amount` only and returned `memo[idx]`, so
   values from different states got mixed: 142 of 193 solvable cases were
   wrong. Impossible amounts printed 2147483646 instead of −1. And at
   x = 1,000,000 the recursion overflowed the stack. A correct
   `(idx, amount)` memo would need 100 × 1,000,000 entries anyway, so CSES's
   limits call for the 1D table.
2. **1D table with `INT_MAX` for impossible.** `1 + INT_MAX` overflows to a
   large negative number, which wins every `min` and spreads to other
   amounts. 261 of 304 cases were wrong.
3. **`INT_MAX - 1`**, as in LC 322. `1 +` it is `INT_MAX`, which can't
   overflow and still loses every `min`.

## Complexity

**O(n · x)** time, at most 100 × 1,000,000 = 10⁸ simple steps: 0.17 s
measured. O(x) space, with no recursion.

## Small notes on the code

- `memo[1000010]` is global, so it lives outside the stack; the same array
  as a local would overflow it.
- A coin larger than x makes the inner loop run zero times, which is correct.

## Tested

- CSES's example: coins 1, 5, 7 for 11 gives 3
- 300 random cases: 1–6 coins of value 1–30, x from 1 to 120, about a third
  of them impossible
- x = 1,000,000 with a single coin of 1 (1,000,000 coins)
- the worst case: 100 coins with x = 1,000,000, in 0.17 s

The random cases were checked against a separate table. Built with `-ftrapv`;
no overflow.

## Key insight

One row over amounts, coins in the outer loop and amounts rising in the inner loop, so a coin can be reused; start "impossible" at `INT_MAX - 1` so `1 +` it can't overflow.
