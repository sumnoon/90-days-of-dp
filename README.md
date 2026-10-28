# 90 Days of DP

**From recursion to dynamic programming mastery, one day at a time.** Follow along with **#90DaysOfDP**.

A 12-week plan to go from basic recursion to strong dynamic programming, built around a Monday–Friday job.
The plan runs from **Sun Sep 20, 2026** (Day 0) to **Sun Dec 13, 2026**, with a mastery test Dec 14–20.

- 📘 **Full plan:** [PLAN.md](PLAN.md)
- 🔁 **Redo list:** [redo-list.md](redo-list.md)
- 📝 **Notes template:** [templates/problem-notes.md](templates/problem-notes.md)

## Weekly rhythm

| Days | Time | Focus |
|---|---|---|
| Mon–Fri | 1–1.5 h | 1–2 easier or medium problems |
| Saturday | 3–4 h | Hardest problems + main videos and reading |
| Sunday | 2–3 h | Redo, checkpoint, preview next week |

## Visualizations

Interactive pages for the ideas a static diagram can't carry:
**https://sumnoon.github.io/90-days-of-dp/**

**Week 1: recursion fundamentals**
- [Where the work happens](https://sumnoon.github.io/90-days-of-dp/order/) — pre-order vs post-order, four ways
- [Meeting in the middle](https://sumnoon.github.io/90-days-of-dp/twopointer/) — palindrome check and LC 344
- [The same answer, computed again and again](https://sumnoon.github.io/90-days-of-dp/fib/) — LC 509, the recursion tree
- [Reverse a linked list, one frame at a time](https://sumnoon.github.io/90-days-of-dp/lc206/) — LC 206, 28 steps
- [Which head goes first](https://sumnoon.github.io/90-days-of-dp/lc21/) — LC 21, heads chosen going down
- [Reading n one bit at a time](https://sumnoon.github.io/90-days-of-dp/lc50/) — LC 50, fast exponentiation in binary
- [Moving n disks means moving n − 1, twice](https://sumnoon.github.io/90-days-of-dp/hanoi/) — Tower of Hanoi, playable

**Week 2: recursion on trees**
- [Down the tree, back up it](https://sumnoon.github.io/90-days-of-dp/trees/) — traversals, LC 104, LC 112 and LC 98
- [Swap the halves, walk in lockstep](https://sumnoon.github.io/90-days-of-dp/mirror/) — LC 226 and LC 100
- [Swap a pair, trust the rest](https://sumnoon.github.io/90-days-of-dp/lc24/) — LC 24
- [What each subtree reports back](https://sumnoon.github.io/90-days-of-dp/report/) — LC 543 and LC 236

**Week 3: backtracking**
- [Choose, explore, un-choose](https://sumnoon.github.io/90-days-of-dp/subsets/) — LC 78, 77, 17, 46 and 39 on one template

**Week 4: backtracking II and divide & conquer**
- [The board is the visited set](https://sumnoon.github.io/90-days-of-dp/grid/) — LC 79, grid backtracking
- [Where do the dots go?](https://sumnoon.github.io/90-days-of-dp/ip/) — LC 93, choices rejected on the spot
- [Split, trust, merge](https://sumnoon.github.io/90-days-of-dp/mergesort/) — LC 912, merge sort level by level
- [Every operator goes last once](https://sumnoon.github.io/90-days-of-dp/exprs/) — LC 241, the repeated substrings a cache removes
- [One queen per row](https://sumnoon.github.io/90-days-of-dp/queens/) — LC 51, a column and two diagonals in three arrays

Source in [`docs/`](docs/).

## Progress

Month 1 (recursion and backtracking) is done; the Month 1 checkpoint, LC 241
with a cache, passed. **Now: Week 6**, 1D DP: writing the state in one sentence before the code.

| Week | Dates | Topic | Done |
|---|---|---|---|
| [1](weeks/week-01-recursion-fundamentals/) | Sep 21 – Sep 27 | Recursion Fundamentals | ☑ |
| [2](weeks/week-02-recursion-on-trees-and-structures/) | Sep 28 – Oct 4 | Recursion on Trees and Structures | ☑ |
| [3](weeks/week-03-backtracking-i/) | Oct 5 – Oct 11 | Backtracking I (Subsets, Permutations, Combinations) | ☑ |
| [4](weeks/week-04-backtracking-ii-and-divide-conquer/) | Oct 12 – Oct 18 | Backtracking II and Divide & Conquer | ☑ |
| [5](weeks/week-05-from-memoization-to-dp/) | Oct 19 – Oct 25 | From Memoization to DP | ☑ |
| [6](weeks/week-06-1d-dp/) | Oct 26 – Nov 1 | 1D DP (Sequences and Decisions) | ☐ |
| [7](weeks/week-07-2d-grid-dp/) | Nov 2 – Nov 8 | 2D Grid DP | ☐ |
| [8](weeks/week-08-string-dp/) | Nov 9 – Nov 15 | String DP (Two Sequences) | ☐ |
| [9](weeks/week-09-the-knapsack-family/) | Nov 16 – Nov 22 | The Knapsack Family | ☐ |
| [10](weeks/week-10-interval-dp/) | Nov 23 – Nov 29 | Interval DP | ☐ |
| [11](weeks/week-11-tree-dp-and-state-machine-dp/) | Nov 30 – Dec 6 | Tree DP and State Machine DP | ☐ |
| [12](weeks/week-12-bitmask-dp-digit-dp-and-final-review/) | Dec 7 – Dec 13 | Bitmask DP, Digit DP, and Final Review | ☐ |

## Repo layout

```
weeks/week-NN-topic/
  README.md      schedule, problem checklist, checkpoint
  solutions/     my code, e.g. lc0070_climbing_stairs.cpp
  notes/         one note per solved problem, plus a README.md index
  redos/         re-solves and checkpoint attempts
docs/            the visualizations (GitHub Pages)
redo-list.md     problems that needed a hint, re-solved on Sundays
```

All solutions are in **C++20**. Files are named `lcXXXX_short_name.cpp` (or
`cses_name.cpp`, `atcoder_dp_x.cpp`). Each note covers the state, the recursive
case or transition, the base case, complexity and the key insight, following
the [template](templates/problem-notes.md).
