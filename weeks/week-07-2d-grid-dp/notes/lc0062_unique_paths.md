# ⭐ LC 62: Unique Paths, three ways

- **Solution:** [`solutions/lc0062_unique_paths.cpp`](../solutions/lc0062_unique_paths.cpp)
- **Day:** 43 (Week 7 Mon), solved on Tue 24 Nov
- **Solved without help?** yes

A robot starts at the top-left of an m × n grid and moves only right or down.
How many different paths reach the bottom-right corner?

## 1. Memoized: from here to the end

`calcRecurse(i, j)` = **the number of paths from `(i, j)` to the bottom-right
corner**.

```cpp
return memo[i][j] = calcRecurse(i + 1, j, n, m) + calcRecurse(i, j + 1, n, m);
```

Split on the **first move**, down or right. Every path makes exactly one of
them, so the two counts add.

Base cases: on the corner, 1 path (stay there); off the grid, 0.

## 2. Table: from the start to here

`memo[i][j]` = **the number of paths from the top-left corner to `(i, j)`**:
the same question turned around, splitting on the **last** move.

```cpp
memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
```

The first row and the first column are all 1: there's only one way along an
edge. Filling row by row, left to right, means the cell above and the cell to
the left are always ready.

## 3. One row

The table only ever reads the row above and the cell to the left, so one row
of m numbers is enough:

```cpp
dp[j] = dp[j] + dp[j - 1];
```

- `dp[j]` on the right still holds **the row above**, because it hasn't been
  updated yet in this pass;
- `dp[j - 1]` was just updated, so it's **this row, to the left**.

That's the same trick as CSES Minimizing Coins, and the skill this week's
checkpoint asks for (LC 64 in O(n) space).

## Versions in the class

| Call | Version |
|---|---|
| `uniquePathsMemo(m, n)` | memoized; fills `memo` with −1 itself |
| `uniquePathsTable(m, n)` | the full table |
| `uniquePaths(m, n)` | one row (submitted) |

`uniquePathsMemo` and `uniquePathsTable` are one-line wrappers added so each
version can run on its own. The three functions inside are unchanged.

## Complexity

**O(m · n)** time for all three. Space: O(m · n) for the memo and the table,
O(n) for one row.

## Small notes on the code

- `uniquePaths(m, n)` calls `calc(n, m)`, swapping rows and columns. The
  answer is the same either way, since turning the grid sideways doesn't
  change the count.
- `vector<int> dp(m + 1)` is one slot bigger than it uses.
- An `int` is enough because LeetCode guarantees the answer is at most
  2 × 10⁹. Every cell is at most the final answer, so nothing overflows on the
  way. The tests used `-ftrapv`, which aborts on any signed overflow.

## Tested

Every grid from 1 × 1 to 100 × 100 whose answer is at most 2 × 10⁹ (1,773 of
them), for all three versions, checked against the exact count
C(m + n − 2, m − 1): every path is m − 1 downs and n − 1 rights in some
order.

## Key insight

Split on the first move (memo) or the last move (table); either way a cell adds the two cells it can come from. The table only reads the row above and the cell to the left, so one row is enough.
