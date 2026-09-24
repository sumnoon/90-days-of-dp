# Week 1 notes

One note per solved problem: what the call returns, the recursive case, the
base case, complexity, and the one idea that unlocked it. Written to be
re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [Day 0 warm-ups](warmup_recursion.md) | 0 | clean | The base case is the **identity value** of whatever the recursive case combines with: 1 for `*`, 0 for `+`. |
| [Print 1..N and N..1](print_1_to_n.md) | 1 | clean | Work **before** the call happens top-down; work **after** it happens bottom-up. One moved line flips the output. |
| [Palindrome check](palindrome_check.md) | 1 | hint | Reaching `r <= l` means every pair already matched, so the answer there is `true` — not another comparison. |
| [LC 344 Reverse String](lc0344_reverse_string.md) | 1 | clean | Same traversal as the palindrome check; only the work in the middle changes. |
| [⭐ LC 509 Fibonacci](lc0509_fibonacci_number.md) | 2 | clean | 2.7M calls for 31 distinct values. That gap **is** dynamic programming. |
| [LC 231 Power of Two](lc0231_power_of_two.md) | 3 | clean | Short-circuit `&&` is doing the work of a base case. |
| [⭐ LC 206 Reverse Linked List](lc0206_reverse_linked_list.md) | 3 | clean | Grant that the rest is reversed; then exactly one link needs changing. |
| [LC 21 Merge Two Sorted Lists](lc0021_merge_two_sorted_lists.md) | 4 | clean | The smaller head *is* the answer's head; hand the rest to the recursion. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).

## Visualizations

Interactive step-throughs built alongside the notes, published at
**https://sumnoon.github.io/90-days-of-dp/** and served from [`docs/`](../../../docs/).

| Page | What it shows |
|---|---|
| [Where the Work Happens](https://sumnoon.github.io/90-days-of-dp/order/) | Print 1..N, print N..1, factorial and sum of digits on one stack. Work before the call fires top-down; work after it fires bottom-up. |
| [Meeting in the Middle](https://sumnoon.github.io/90-days-of-dp/twopointer/) | The palindrome check and LC 344 as one recursion, with a compare/swap toggle. |
| [LC 206 Frame by Frame](https://sumnoon.github.io/90-days-of-dp/lc206/) | 28 steps of `reverseList([1,2,3,4,5])` with live pointer diagram, call stack and code line. Nothing rewires on the way down. |
| [Fibonacci's Repeated Work](https://sumnoon.github.io/90-days-of-dp/fib/) | The recursion tree for n up to 9. Click a node to see every recomputation; toggle memoization to collapse it. |
| [Which Head Goes First](https://sumnoon.github.io/90-days-of-dp/lc21/) | LC 21 step by step. Heads chosen on the way down, links written on the way back up; the `<=` toggle makes stability visible. |

## The thread through Week 1

Every problem so far is the same question asked once per level:

> If I already had the answer for a smaller input, how would I build the
> answer for this one?

What changes is the shape of "smaller":

| Shape | Problems |
|---|---|
| One step down (`n - 1`) | factorial, sum of digits, print 1..N |
| Two pointers moving inward | palindrome, LC 344 |
| Halving (`n / 2`) | LC 231, and LC 50 next |
| Following a pointer (`head->next`) | LC 206 |
| Two inputs, advance one | LC 21 — the shape Week 8 string DP reuses |
| **Two recursive calls** | **LC 509** — and this is the one that becomes DP |
