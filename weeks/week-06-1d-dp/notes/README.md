# Week 6 notes

One note per solved problem: the state, the transition, the base cases, the
order a table is filled in, complexity, and the one idea that unlocked it.
Written to be re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [⭐ LC 53 Maximum Subarray, five versions](lc0053_maximum_subarray.md) | 36 | hint (recursion) | The best subarray ending at `i` starts fresh or extends the one ending at `i − 1`; Kadane keeps that table in one variable. Divide and conquer: left, right, or crossing `mid`. |
| [LC 152 Maximum Product Subarray](lc0152_maximum_product_subarray.md) | 37 | clean | Between zeros only the sign matters, so the best run is a prefix or a suffix: one pass from each end. |
| [⭐ LC 91 Decode Ways](lc0091_decode_ways.md) | 40 | clean | Split on the first piece, one digit or two; an unreadable `'0'` just contributes 0. |
| [⭐ LC 322 Coin Change, memoized and table](lc0322_coin_change.md) | 38 | clean | Take a coin and stay on it, or skip it for good; `INT_MAX - 1` for impossible so `1 +` can't overflow. |
| [⭐ LC 139 Word Break, memoized and table](lc0139_word_break.md) | 39 | hint (table) | Split on the last word; a table by length needs `n + 1` slots, with `memo[0] = true` for the empty prefix. |
| [⭐ LC 300 Longest Increasing Subsequence](lc0300_longest_increasing_subsequence.md) | 41 | clean | "From `idx` on, above `nums[prev]`" or "ending at `i`", which needs the max over every `i`. For O(n log n), keep the smallest tail per length: it's sorted, so binary search. |
| [LC 673 Number of Longest Increasing Subsequence](lc0673_number_of_longest_increasing_subsequence.md) | 41 | clean | Carry a count beside LC 300's "longest ending at `i`": a longer way in resets it, an equal one adds. |
| [LC 1048 Longest String Chain](lc1048_longest_string_chain.md) | 41 | clean | LIS over words sorted by length; delete each letter to list the only possible predecessors and look them up. |
| [LC 983 Minimum Cost For Tickets](lc0983_minimum_cost_for_tickets.md) | 42 | clean | Index by travel day: each needs one decision, which ticket starts there, and that ticket picks the next uncovered day. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
