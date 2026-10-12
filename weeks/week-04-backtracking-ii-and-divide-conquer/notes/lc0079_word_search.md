# ⭐ LC 79: Word Search

- **Solution:** [`solutions/lc0079_word_search.cpp`](../solutions/lc0079_word_search.cpp)
- **Day:** 22 (Mon)
- **Solved without help?** yes

## What the call does

`backtrack(i, j, …, idx)` answers: can `word[idx..]` be spelled starting at
cell `(i, j)`, moving up, down, left or right, never reusing a cell already
on the current path?

**Returns** a bool. **Passes down** the cell, the index into `word`, and the
board itself, by reference, which doubles as the record of where the path
has been.

## Recursive case

```cpp
board[i][j] = '#';                      // choose: this cell is on the path

for (int k = 0; k < 4; ++k) {
    int tx = fx[k] + i, ty = fy[k] + j;
    if (valid(tx, ty, n, m) && backtrack(tx, ty, …, idx + 1)) return true;
}

board[i][j] = word[idx];                // un-choose: give the cell back
return false;
```

The Week 3 template on a grid. The **choices** are the four neighbours, the
**state** is the cell plus how much of the word is matched, and the **choose
/ un-choose** is writing `'#'` into the cell and putting the letter back.

**Why mark the board instead of a `visited` grid:** the cell itself records
"on the current path", so no extra memory is needed, and a `'#'` can never
match a letter of the word, so a marked cell fails the first check of any
call that steps onto it. That's what stops `"ABA"` on `[["A","B"]]` from
using the A twice. (The `visited` member is declared but never used; the
board does its job.)

**Restoring with `word[idx]`** works because the cell only got this far by
matching `word[idx]`, so that's exactly the letter that was there.

## Base cases

```cpp
if (word[idx] != board[i][j]) return false;   // wrong letter, or a '#'
if (idx == word.length() - 1) return true;    // last letter matched
```

## The board after a successful search

On success, `return true` leaves the loop **before** the restore line, so
every cell on the found path stays `'#'`. The harness shows it: every `true`
case reports "board left modified". LeetCode only checks the bool, so it's
accepted, but a caller that reuses the board would get a damaged grid.
Restoring before returning, or restoring after the loop and returning a
saved result, keeps the board unchanged either way. After a `false` search
the board always comes back intact, since every cell is restored on the way
out.

## Complexity

Time: **O(m · n · 3^L)** for word length L: each of the m·n starts, then at
most 3 new directions per step (the 4th is where it came from, already `'#'`).
Measured worst case at LeetCode's limits (6 × 6 of `'A'`, a 15-letter word
ending in `'B'`, so every path dies at the last letter): **37 ms**.
Space: **O(L)** recursion depth; no extra grid.

## Small notes on the code

- `idx == word.length() - 1` compares `int` with an unsigned size
  (`-Wall` warns).
- `vector<vector<bool>> visited` is never used.

## Tested

LeetCode's three examples (`ABCCED`, `SEE`, `ABCB`), single cells, `ABA` on
a two-cell board (needs a cell twice: false), a word around a 2 × 2 square,
LeetCode's long-snake case `ABCESEEEFS` (true on its own board, false on
example 1's), and the 6 × 6 worst case above.

## Key insight

The board is the visited set: write `'#'` going in, put the letter back coming out.
