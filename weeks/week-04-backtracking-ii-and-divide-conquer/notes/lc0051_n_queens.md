# ⭐ LC 51: N-Queens

- **Solution:** [`solutions/lc0051_n_queens.cpp`](../solutions/lc0051_n_queens.cpp)
- **Day:** 27 (Week 4 Sat), solved on Tue 20 Oct
- **Solved without help?** yes

## What the call records

`backtrack(row, n, board)` places one queen in each row from `row` down.
When every row has a queen, it **records** a copy of the board in `ans`.

**Records** finished boards. **Passes down** the row to fill next. The board
and the three "used" arrays are shared, so they have to be undone.

One queen per row comes for free from the structure: each level is a row, and
the loop picks that row's column. Rows never need checking.

## Choose / explore / un-choose

```cpp
for (int col = 0; col < board.size(); ++col) {
    if (col_used[col] || main_diag_used[main_d] || anti_diag_used[anti_d]) continue;
    board[row][col] = 'Q';  col_used[col] = ... = true;     // choose
    backtrack(row + 1, n, board);                           // explore
    board[row][col] = '.';  col_used[col] = ... = false;    // un-choose
}
```

## The diagonal indices

Every cell on one **↘ diagonal** has the same `row - col`, and every cell on
one **↙ diagonal** has the same `row + col`.

- `row + col` runs from 0 to 2n − 2 already.
- `row - col` runs from −(n − 1) to n − 1, so adding `n - 1` moves it into
  0 … 2n − 2.

That gives 2n − 1 diagonals each way, and the arrays are sized to match.

With the three arrays, checking a square costs O(1) instead of walking back
up the column and both diagonals.

## Base case

```cpp
if (row == board.size()) { ans.push_back(board); return; }
```

Every row is filled, and every queen passed the check when it was placed, so
the board is a solution.

## Complexity

At most n choices in the first row, fewer in each one after: O(n!) as an upper
bound, much less in practice because the checks prune early. Measured on
LeetCode's largest input, **n = 9: 352 boards in 4.3 ms**. Space: O(n) for the
board and the arrays, plus the answers.

## Small notes on the code

- **`valid()` is never called.** It's the slower check, walking back up the
  column and both diagonals, and the three arrays replaced it. Delete it.
- `ans` is a member, so calling `solveNQueens` twice on one object would keep
  the first call's boards. LeetCode makes a new object each time, so it's
  fine there.
- `j < board.size()`, `row == board.size()` and `col < board.size()` compare
  an `int` with an unsigned size (`-Wall`). Using `n` instead avoids all three.
- The file was named `lc0051_n_queen.cpp`; the problem is *N-Queens*.

## Tested

n = 1 … 9 (LeetCode's range), each on a fresh `Solution`:

- the number of boards matches the known counts (1, 0, 0, 2, 10, 4, 40, 92,
  352);
- every board passes an independent check: one queen per row, and no two
  queens share a column or a diagonal;
- no board appears twice.

## Key insight

One queen per row is the structure; the only checks are the column and the two diagonals, and `row - col` and `row + col` name a diagonal in one number.
