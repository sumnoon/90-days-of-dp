# Redo List

Problems I needed a hint or solution for, plus anything flagged for
re-practice. Re-solve them on Sunday, then tick them off.

| Problem | Week | Why I got stuck | Redo 1 | Redo 2 |
|---|---|---|---|---|
| [⭐ LC 206 Reverse Linked List](weeks/week-01-recursion-fundamentals/notes/lc0206_reverse_linked_list.md) | 1 | Solved it first try, but flagged on purpose: the leap of faith should be rebuilt from scratch, not remembered. Re-solve without looking at the notes. | ☑ Sat 26 Sep | ☐ |
| [Recursive palindrome check](weeks/week-01-recursion-fundamentals/notes/palindrome_check.md) | 1 | Base case took three attempts. `r < l` returned `false`, so every even-length palindrome failed; the second attempt read `s[l-1]` and went out of bounds on `""`. | ☑ Sun 27 Sep | ☐ |
| [Tower of Hanoi: why no solution beats 2ⁿ − 1](weeks/week-01-recursion-fundamentals/notes/tower_of_hanoi.md#ans-for-2) | 1 | Checkpoint answer 2 needed the full argument: why the other n − 1 disks *must* be on the spare peg, and that each tower move costs at least F(n − 1), not n − 1. Re-derive the lower bound without looking. | ☐ | ☐ |
