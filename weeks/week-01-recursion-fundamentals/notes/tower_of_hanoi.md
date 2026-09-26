# Tower of Hanoi

- **Solution:** [`solutions/tower_of_hanoi.cpp`](../solutions/tower_of_hanoi.cpp)
- **Day:** 6 (Sat)
- **Solved without help?** yes
- **Week 1 checkpoint:** Sunday — explain why it takes 2ⁿ − 1 moves.

The first recursion with **two recursive calls that both do real work**. Fibonacci
also made two calls, but most of its work was repeated; here every call moves
a disk nobody else will.

## What the call does

`towerOfHanoi(n, source, destination, temporary)` prints the moves that carry
the top `n` disks from `source` to `destination`, using `temporary` as the
spare. It returns nothing — the answer is the sequence of side effects.

## Recursive case

```cpp
towerOfHanoi(n - 1, source, temporary, destination);   // clear the way
cout << "Move from " << source << " to " << destination << endl;
towerOfHanoi(n - 1, temporary, destination, source);   // bring them back on top
```

The largest of the `n` disks can only move when everything above it is out of
the way and its target is empty. So:

1. park the top `n − 1` disks on the spare peg
2. move the largest disk across
3. bring the `n − 1` back on top of it

Steps 1 and 3 are the same problem again, **with the pegs playing different
parts**. That swap of arguments is the whole trick: in the first call the
spare peg becomes the *destination*, and in the second it becomes the
*source*. Only the argument order changes between calls.

## Base case

`n == 1` moves the single disk directly. See the bug below — it's the one
thing to fix.

## Complexity

Time: **O(2ⁿ)** — the move count doubles and adds one with every disk.
Space: **O(n)** — the stack never goes deeper than `n` frames, even though the
recursion makes 2ⁿ − 1 calls in total.

## Measured

Every move was replayed on a simulated board, checking that no disk ever lands
on a smaller one and that all disks finish on C:

| n | moves | 2ⁿ − 1 | every move legal | all on C |
|---|---|---|---|---|
| 1 | 1 | 1 | yes | yes |
| 3 | 7 | 7 | yes | yes |
| 5 | 31 | 31 | yes | yes |
| 10 | 1,023 | 1,023 | yes | yes |

(All of 1–10 were checked; the table shows a sample.)

The **number of calls equals the number of moves** — 1,023 of each for
n = 10 — because every frame, base case or not, prints exactly one move.

For n = 3 the output is `AC AB CB AC BA BC AC`.

## Bug: n = 0

**Input 0 crashes** with exit code `0xC00000FD`, which is Windows' stack
overflow. The base case only catches `n == 1`, so `n = 0` recurses into −1,
−2, −3… and never stops.

Hint rather than fix: in the Day 0 warm-ups, the base case that made
everything cleanest was the *identity* — the input for which the answer is
"do nothing." What does moving **zero** disks take? If that becomes the base
case, is `n == 1` still needed as a special case at all?

## Small notes on the code

- `string` parameters are taken **by value**, so each of the 2ⁿ − 1 calls
  copies three strings. `const string&` avoids it — the same fix as the
  [palindrome check](palindrome_check.md). Single `char`s (`'A'`) would be
  simpler still.
- `#include <string>` is missing; it compiles today only because
  `<iostream>` happens to pull it in.

## Two calls, but no DP here

`hanoi(1, A, C, B)` is called many times — the same subproblem, over and over,
like `fib(2)` was. But memoization can't help: the answer isn't a *value* you
can store and hand back, it's a list of moves that **has to be performed
again**, on a board that has changed. Overlapping subproblems only pay off
when the result can be reused. Keep that distinction for Week 5.

## See it

- **Play it, then watch it:** https://sumnoon.github.io/90-days-of-dp/hanoi/ —
  play any n from 1 to 10 yourself with a move counter against 2ⁿ − 1, then
  switch to *Watch the recursion* to step through this exact code, with the
  call stack and the *from / to / via* role of each peg for the frame on top.
  ([source](../../../docs/hanoi/index.html))

## Checkpoint: why 2ⁿ − 1

*To be written after Sunday's checkpoint, in your own words.* Two things a
complete answer covers:

1. the recurrence this code follows, and why it solves to 2ⁿ − 1
2. why **no** solution can do it in fewer — a claim about the largest disk,
   not about this code
