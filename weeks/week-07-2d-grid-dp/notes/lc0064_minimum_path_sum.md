# ⭐ LC 64: Minimum Path Sum, in one row

- **Solution:** [`solutions/lc0064_minimum_path_sum.cpp`](../solutions/lc0064_minimum_path_sum.cpp)
- **Day:** 45 (Week 7 Wed), solved on Thu 26 Nov
- **Solved without help?** yes

Each cell of an m × n grid holds a cost from 0 to 200. Moving only right or
down from the top-left to the bottom-right, find the smallest total of the
cells on the path.

## State

`memo[j]` = **the smallest sum of a path from the top-left corner to column
`j` of the current row**, counting both ends.

It's [LC 62](lc0062_unique_paths.md)'s one row, with `min` and `+ cost` in
place of adding two counts.

## Transition

```cpp
memo[j] = grid[i][j] + min(memo[j], memo[j - 1]);
```

A path into `(i, j)` arrives from above or from the left, so take the cheaper
of the two and add this cell's cost.

- `memo[j]` on the right still holds **the row above**, because it hasn't been
  overwritten yet in this pass;
- `memo[j - 1]` was just updated, so it's **this row, to the left**.

## Base cases: the edges

The first row and the first column have only one way in, so there's no `min`:

- **First row:** `memo[j] = memo[j - 1] + grid[0][j]`, a running sum from the
  left.
- **First column:** `memo[0] += grid[i][0]` at the start of each row, a
  running sum from above.

Unlike LC 62, where every edge cell is 1, these differ cell by cell, so they
have to be built up, not just set.

## Complexity

**O(m · n)** time, **O(n)** space for the one row (n = the number of columns).
That's this week's checkpoint skill: the full table would be O(m · n).

## Small notes on the code

- `vector<int> memo(m + 1)` is one slot bigger than it uses.
- The largest possible sum is 399 cells × 200 = 79,800, far inside an `int`.
  Unlike LC 63, a cell never holds more than a real path's cost, so nothing
  can grow large on the way. The tests used `-ftrapv`, which aborts on any
  signed overflow.

## Tested

- LeetCode's two examples and a 1 × 1 grid
- LeetCode's limits: 200 × 200 of all 200 (the largest sum, 79,800), one row
  of 200 and one column of 200
- 5,000 random grids up to 8 × 8, checked against a brute force that tries
  every path; a third of them all zeros, so lots of ties

## Key insight

LC 62's one row with `min` in place of `+`: a cell costs its own value plus the cheaper of the cell above (still in `memo[j]`) and the cell to the left (`memo[j - 1]`). The edges have one way in, so they're running sums.
