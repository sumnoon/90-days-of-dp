# Week 3 notes

One note per solved problem: what the call records, what it passes down,
where the choice is undone, complexity, and the one idea that unlocked it.
Written to be re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [⭐ LC 78 Subsets](lc0078_subsets.md) | 15 | clean | Choose, explore, un-choose: the shared `cur` must look the same after a call as it did before. |
| [⭐ LC 77 Combinations](lc0077_combinations.md) | 16 | hint | Stop a branch once it's full; don't start one that can't fill up: `i <= n - need + 1`. |
| [LC 17 Letter Combinations](lc0017_letter_combinations_of_a_phone_number.md) | 17 | clean | One level per digit, one branch per letter; every leaf is an answer, so nothing to prune. `""` must return `[]`. |
| [⭐ LC 46 Permutations](lc0046_permutations.md) | 18 | hint | Order matters, so every level loops from 0; `used[]` stops a number being picked twice, and is undone with `cur`. |
| [⭐ LC 39 Combination Sum](lc0039_combination_sum.md) | 19 | clean | Recurse with `i` to allow reuse; the shrinking target, not the candidates, ends each branch. |
| [⭐ LC 90 Subsets II](lc0090_subsets_ii.md) | 20 | clean | Sort, then at each level try each value once: skip a copy unless it's the first this level tried (`i != idx`). |
| [LC 47 Permutations II](lc0047_permutations_ii.md) | 20 | solution | Sort, then never place a copy before the one to its left: `!used[i-1]` cuts duplicates at the root (9 vs 2,781 calls on eight 1s). |

## Visualizations

| Page | What it shows |
|---|---|
| [Choose, explore, un-choose](https://sumnoon.github.io/90-days-of-dp/subsets/) | LC 78 as a decision tree, include/exclude and for-loop, with `cur` pushed and popped; LC 77's three versions with wasted calls marked; LC 17's tree, where every leaf is an answer; LC 46 with the `used` strip; LC 39 with reuse and dead ends. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
