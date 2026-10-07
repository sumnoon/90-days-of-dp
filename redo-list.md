# Redo List

Problems I needed a hint or solution for, plus anything flagged for
re-practice. Re-solve them on Sunday, then tick them off.

| Problem | Week | Why I got stuck | Redo 1 | Redo 2 |
|---|---|---|---|---|
| [⭐ LC 206 Reverse Linked List](weeks/week-01-recursion-fundamentals/notes/lc0206_reverse_linked_list.md) | 1 | Solved it first try, but flagged on purpose: the leap of faith should be rebuilt from scratch, not remembered. Re-solve without looking at the notes. | ☑ Sat 26 Sep | ☐ |
| [Recursive palindrome check](weeks/week-01-recursion-fundamentals/notes/palindrome_check.md) | 1 | Base case took three attempts. `r < l` returned `false`, so every even-length palindrome failed; the second attempt read `s[l-1]` and went out of bounds on `""`. | ☑ Sun 27 Sep | ☐ |
| [Tower of Hanoi: why no solution beats 2ⁿ − 1](weeks/week-01-recursion-fundamentals/notes/tower_of_hanoi.md#ans-for-2) | 1 | Checkpoint answer 2 needed the full argument: why the other n − 1 disks *must* be on the spare peg, and that each tower move costs at least F(n − 1), not n − 1. Re-derive the lower bound without looking. | ☐ | ☐ |
| [⭐ LC 77 Combinations](weeks/week-03-backtracking-i/notes/lc0077_combinations.md) | 3 | Solved, but the first version kept going after `cur` was full (2ⁿ calls), and the pruning bound `i <= n - need + 1` came after graded hints. Re-solve with both from scratch. | ☐ | ☐ |
| [⭐ LC 46 Permutations](weeks/week-03-backtracking-i/notes/lc0046_permutations.md) | 3 | Needed graded hints first: why the `i + 1` start index no longer works when order matters, and `used[]` as the replacement (set and undone alongside `cur`). | ☐ | ☐ |
| [LC 47 Permutations II](weeks/week-03-backtracking-i/notes/lc0047_permutations_ii.md) | 3 | Needed the duplicate-skip condition shown (`nums[i] == nums[i-1]` plus a `used[i-1]` check). Solved with `used[i-1]`; `!used[i-1]` prunes far earlier (9 vs 2,781 calls on eight 1s). | ☐ | ☐ |
| [⭐ LC 22 Generate Parentheses](weeks/week-03-backtracking-i/notes/lc0022_generate_parentheses.md) | 3 | First version compared the remaining counts the wrong way (`lPar > rPar`), so no `)` was ever placed and every n returned nothing; the fix was explained. Re-solve and get the `)` rule right first time. | ☐ | ☐ |
