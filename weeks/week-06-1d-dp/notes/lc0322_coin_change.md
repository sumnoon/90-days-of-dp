# ⭐ LC 322: Coin Change, memoized and table

- **Solution:** [`solutions/lc0322_coin_change.cpp`](../solutions/lc0322_coin_change.cpp)
- **Day:** 38 (Week 6 Wed), solved on Fri 13 Nov
- **Solved without help?** yes

Find the fewest coins that add up to `amount`, using each coin value as many
times as you like, or −1 if it can't be done.

## State

`calc(idx, amount)` returns **the fewest coins from `coins[idx..]` that make
exactly `amount`**. The answer is `calc(0, amount)`.

## Transition

```cpp
int take = 1 + calc(idx, coins, amount - coins[idx]);
int notTake = 0 + calc(idx + 1, coins, amount);
```

- **take** one `coins[idx]` and **stay** on `idx`, because the same coin can
  be used again;
- **skip** it and move to `idx + 1`, never using it again.

Staying on `idx` after a take is what makes this the **unbounded** knapsack
pattern. Moving to `idx + 1` after a take would allow each coin only once,
the 0/1 version that Week 9 covers.

## Base case

- `amount == 0`: done, so 0 more coins.
- coins run out with `amount > 0`: impossible, so `INT_MAX - 1`.

## Why `INT_MAX - 1`

"Impossible" has to lose every `min`, and `1 + impossible` can't overflow.
With `INT_MAX - 1`, `take` is at most `INT_MAX`, and `notTake` is never above
`INT_MAX - 1`. So an impossible result stays exactly `INT_MAX - 1`, and
`coinChange` can check for it with `==`. The tests run with `-ftrapv`, which
aborts on any signed overflow; none happened.

## Table

`memo[i][j]` = **the fewest coins from the first `i` coin values that make
`j`**: the same two choices, counted from the front instead of the back.

```cpp
memo[i][j] = min(memo[i - 1][j], 1 + memo[i][j - coins[i - 1]]);
```

- `memo[i - 1][j]`: skip coin `i`, from the row above;
- `memo[i][j - coins[i - 1]]`: take it and stay in **this** row, to the left.

Filling rows top to bottom, each left to right, means both cells are ready.
Row 0 (no coins) is impossible except `memo[0][0] = 0`, and column 0 is 0
everywhere.

## Two versions, one class

| Call | Version |
|---|---|
| `coinChangeMemo(coins, amount)` | memoized; resets `memo` to −1 itself |
| `coinChange(coins, amount)` | the table (submitted) |

Both share the one `memo` array. The table version overwrites every cell it
reads, so the two can be called in any order.

## Complexity

O(n × amount) states, one step each: **O(n × amount)** time and space, at most
12 × 10,000 here. The memoized version recurses once per coin taken: with a
coin of 1 and amount 10,000 that's about 10,000 calls deep, which still fits
Windows' default stack.

## Small notes on the code

- `memo[13][10010]` is 520 KB, so the test creates the `Solution` with
  `make_unique` instead of on the stack.
- `res = -1` is always overwritten before it's used.
- `idx == coins.size()` compares `int` with `size_t` (`-Wall`).
- The table only reads the row above and its own row, so one row of
  `amount + 1` would do. Trying every coin as the **last** coin gives that
  1D form: freeCodeCamp's bestSum.

## Tested

- LeetCode's three examples
- `[186, 419, 83, 408]` with 6,249 (20 coins), `[2147483647]` with 2 (−1),
  `[3, 7]` with 11, `[1]` with 10,000, and `[7, 13]` with 10,000
- 3,000 random cases: 1–12 coins of value 1–40, amounts 0–300

Both versions were checked against a separate 1D table.

## Key insight

Take a coin and stay on it, or skip it for good: staying is what lets a coin be reused. Use `INT_MAX - 1` for "impossible" so `1 +` it can never overflow.
