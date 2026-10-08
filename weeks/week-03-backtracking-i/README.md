# Week 3: Backtracking I

**Dates:** Subsets, Permutations, Combinations) (Oct 5 – Oct 11  
**Full guide:** [PLAN.md](../../PLAN.md)

## Schedule

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | Memorize the backtracking template. Solve LC 78 using include/exclude. |
| Tue | 1–1.5 h | LC 78 again with a for-loop from a start index, then LC 77. |
| Wed | 1–1.5 h | LC 17. |
| Thu | 1–1.5 h | LC 46 using a `used[]` array. |
| Fri | 1–1.5 h | LC 39 (the same element can be reused, so recurse with `i`, not `i+1`). |
| **Sat** (weekend) | 3–4 h | The duplicate-handling problems: LC 90, LC 47, LC 40. Then LC 22 (prune with open/close counts). Read the issac3 backtracking post. |
| **Sun** (weekend) | 2–3 h | Redo list, then do the **checkpoint**. Preview Week 4 by re-reading Erickson section 2.1 (N Queens), properly this time. |

## Problems

⭐ = core, don't skip

- [x] ⭐ LC 78 Subsets — both ways, include/exclude and for-loop — [notes](notes/lc0078_subsets.md)
- [x] ⭐ LC 90 Subsets II — [notes](notes/lc0090_subsets_ii.md)
- [x] ⭐ LC 46 Permutations — [notes](notes/lc0046_permutations.md)
- [x] LC 47 Permutations II — [notes](notes/lc0047_permutations_ii.md)
- [x] ⭐ LC 77 Combinations — [notes](notes/lc0077_combinations.md)
- [x] ⭐ LC 39 Combination Sum — [notes](notes/lc0039_combination_sum.md)
- [x] LC 40 Combination Sum II — [notes](notes/lc0040_combination_sum_ii.md)
- [x] LC 17 Letter Combinations of a Phone Number — [notes](notes/lc0017_letter_combinations_of_a_phone_number.md)
- [x] ⭐ LC 22 Generate Parentheses — [notes](notes/lc0022_generate_parentheses.md)

## Checkpoint

- [ ] Write the template from memory and solve Subsets and Permutations in under 10 minutes each.

## Notes

One note per problem in [`notes/`](notes/): what the call records, what it
passes down, where the choice is undone, complexity, and the idea that
unlocked it. Start at the [notes index](notes/README.md).