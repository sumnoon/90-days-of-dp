# ⭐ LC 22: Generate Parentheses

- **Solution:** [`solutions/lc0022_generate_parentheses.cpp`](../solutions/lc0022_generate_parentheses.cpp)
- **Day:** 20 (Sat)
- **Solved without help?** hint: the first version compared the counts the wrong way round, and the bug was explained

## What the call does

`backtrack(idx, cur, lPar, rPar)` records every balanced string that starts
with `cur`, where `lPar` and `rPar` are how many `(` and `)` are **still left
to place**.

**Returns** nothing. **Passes down** `cur` (by value) and the two remaining
counts.

## Recursive case

```cpp
if (lPar) {                 // a '(' is still left
    cur.push_back('(');
    backtrack(idx + 1, cur, lPar - 1, rPar);
    cur.pop_back();
}
if (lPar < rPar) {          // more ')' left than '(' left
    cur.push_back(')');
    backtrack(idx + 1, cur, lPar, rPar - 1);
    cur.pop_back();
}
```

Two choices per call, each with its own rule:

- **`(`** is allowed while any are left.
- **`)`** is allowed only if it has something to close: more `(` placed than
  `)` so far. Counting what's **left**, that reads the other way: fewer `(`
  left than `)` left, `lPar < rPar`.

These rules *are* the pruning. No invalid prefix like `())` is ever built,
so every branch ends in a valid string, and nothing has to be checked or
thrown away at the end.

## The bug in the first version

The first version had `if (lPar > rPar)`, the condition for counts of what's
**placed**, applied to counts of what's **left**. Starting from `(n, n)`,
`lPar` only goes down and `rPar` never does, so `lPar > rPar` is never true:
no `)` is ever placed, the base case is never reached, and the result is
**empty for every n** (n = 3: 4 calls, 0 answers, measured). When the
counters count down, every comparison flips.

## Base case

```cpp
if (lPar == 0 && rPar == 0) { ans.push_back(cur); return; }
```

Everything placed. Because of the rules above, the string is always balanced
here.

## Counting

The number of balanced strings with n pairs is the **Catalan number** Cₙ:
1, 2, 5, 14, 42, 132, 429, 1430 for n = 1 … 8. That's about 4ⁿ / n^1.5,
against 2²ⁿ = 4ⁿ unrestricted strings of length 2n: for n = 8, 1,430 valid
strings out of 65,536. The rules cut every invalid branch before it starts,
so the search only ever builds the 1,430.

## Small notes on the code

- `idx` is passed and incremented but never used; `cur.size()` already says
  where we are.
- `cur` is passed by value, like LC 17, so each call has its own copy; the
  `pop_back` is still needed because that copy is reused for the second
  branch.
- `ans` is a member that's never cleared.

## Tested

n = 1 … 8 (LeetCode's maximum): exactly Cₙ strings each time, all distinct,
all of length 2n, and all balanced (a running count never drops below 0 and
ends at 0).

## Key insight

Allow `(` while any are left, and `)` only when it has something to close; with counts of what's left, that's `lPar < rPar`.
