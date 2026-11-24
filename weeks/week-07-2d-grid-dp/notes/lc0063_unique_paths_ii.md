# ⭐ LC 63: Unique Paths II, three ways

- **Solution:** [`solutions/lc0063_unique_paths_ii.cpp`](../solutions/lc0063_unique_paths_ii.cpp)
- **Day:** 44 (Week 7 Tue), solved on Tue 24 Nov
- **Solved without help?** yes, then a hint for an overflow in the table versions

[LC 62](lc0062_unique_paths.md) with obstacles: a robot moves only right or
down through a grid where `1` marks a blocked cell. How many paths reach the
bottom-right corner?

## What changes from LC 62

One rule: **a blocked cell has 0 paths**. Everything else is LC 62's
transition, a cell adds the two cells it can come from.

The edges are no longer all 1. One obstacle on the first row cuts off every
cell to its right, so the table can't fill the first row and column with 1s.
Instead it treats a missing neighbour (off the grid) as 0 and sets only the
start to 1.

## 1. Memoized: from here to the end

`calcRecurse(i, j)` = **the number of paths from `(i, j)` to the bottom-right
corner**.

Base cases, in order:

- on the corner: 1 if it's open, 0 if it's blocked;
- off the grid: 0;
- on an obstacle: 0.

The corner check comes first, so a blocked end returns 0 there rather than 1.

## 2. Table: from the start to here

`memo[i][j]` = **the number of paths from the top-left corner to `(i, j)`**.

```cpp
if (grid[i][j] == 1)        memo[i][j] = 0;
else if (i == 0 && j == 0)  memo[i][j] = 1;
else                        memo[i][j] = safeAdd(top, left);   // 0 for a neighbour off the grid
```

A blocked start gets 0, since the obstacle check comes before the start check.

## 3. One row

The same as LC 62's one row: `dp[j]` still holds the row above until it's
overwritten, and `dp[j - 1]` is this row, to the left. A blocked cell just
writes 0 into its slot.

## The overflow trap

LeetCode only promises the **final answer** fits in an `int` (at most 2 × 10⁹).
That's enough for the recursion but not for the two tables.

- **The recursion** counts paths *to the end*. Every cell it visits is
  reachable from the start, so its count is at most the answer.
- **The tables** count paths *from the start*, for every cell, including ones
  that can't reach the end.

On a 100 × 100 grid that's open except for the end cell, the answer is 0, but
the cells near the corner hold counts around C(198, 99), about 10⁵⁸. The
first version overflowed an `int` there; signed overflow is undefined
behaviour, and `-ftrapv` aborted on it.

**The fix:** `safeAdd` stops at `INT_MAX` instead of overflowing. Capping is
safe because a cell whose true count passes `INT_MAX` can't reach the end (if
it could, the answer would be at least that big). Everything right of or below
such a cell can't reach the end either, so the capped number never feeds into
the answer.

The other fix would be a wider type, but `long long` isn't enough either
(10⁵⁸ is far past 9 × 10¹⁸), so the cap is the cleaner choice.

## Versions in the class

| Call | Version |
|---|---|
| `uniquePathsWithObstacles(grid)` | memoized; fills `memo` with −1 itself (submitted) |
| `uniquePathsWithObstaclesTable(grid)` | the full table |
| `uniquePathsWithObstaclesRow(grid)` | one row |

The table and row calls are one-line wrappers added so each version can run on
its own. The functions inside are unchanged.

## Complexity

**O(m · n)** time for all three. Space: O(m · n) for the memo and the table,
O(n) for one row.

## Small notes on the code

- The recursion goes at most m + n − 1 = 199 calls deep, so the stack is never
  a worry here.
- The memoized version uses `safeAdd` too. It doesn't need it, since its
  counts never pass the answer, but it does no harm.
- `vector<int> dp(m + 1, 0)` is one slot bigger than it uses.

## Tested

- LeetCode's two examples, and 1 × 1 grids open and blocked
- 100 × 100 grids with an answer of 0 but huge counts inside: only the end
  blocked, the end walled off, only the start blocked
- 3,000 random grids up to 7 × 7, checked against a brute force that walks
  every path
- 1,604 random grids up to 100 × 100 with obstacle densities from 1 in 2 to
  1 in 31, keeping those whose answer is at most 2 × 10⁹, checked against a
  `long long` count from the end

All three versions, with `-ftrapv` and `-D_GLIBCXX_ASSERTIONS`.

## Key insight

An obstacle is a cell with 0 paths; the rest is LC 62. Counting from the start fills cells that can't reach the end, so their counts can overflow even when the answer is small: cap them, since they never reach the answer.
