# LC 509: Fibonacci Number ⭐

- **Link:** https://leetcode.com/problems/fibonacci-number/
- **Solution:** [`solutions/lc0509_fibonacci_number.cpp`](../solutions/lc0509_fibonacci_number.cpp)
- **Day:** 2 (Tue)
- **Solved without help?** yes

The problem is trivial. The **call count** is the point, and it's the reason
this week exists at all.

## What the call returns

`calc(n)` — the nth Fibonacci number.

## Recursive case

```cpp
return calc(n - 1) + calc(n - 2);
```

Two recursive calls instead of one. That single change is what makes the cost
explode: the recursion stops being a chain and becomes a **tree**.

## Base case

`n == 0 → 0` and `n == 1 → 1`. Two of them, because the recursive case reaches
back two steps and both need to land somewhere.

## Complexity

Time: **O(φⁿ)** ≈ O(1.618ⁿ). Space: O(n) — the stack only ever holds one
root-to-leaf path, even though the tree is exponentially wide.

## The recursion tree for n = 5

```
                      fib(5)
                    /        \
              fib(4)          fib(3)
             /      \        /      \
        fib(3)    fib(2)  fib(2)   fib(1)
        /    \     /   \   /    \
   fib(2)  fib(1) f(1) f(0) f(1) f(0)
    /   \
  f(1)  f(0)
```

Read it left to right: the whole `fib(3)` subtree on the left is recomputed
from scratch as the right child of `fib(5)`.

Counted by instrumenting the real function — 15 calls in total:

| argument | times called |
|---|---|
| `calc(5)` | 1 |
| `calc(4)` | 1 |
| `calc(3)` | 2 |
| **`calc(2)`** | **3** |
| `calc(1)` | 5 |
| `calc(0)` | 3 |

`fib(2)` is computed **3 times**, and each time from scratch.

## How fast it gets bad

| n | total calls | distinct values | wasted |
|---|---|---|---|
| 5 | 15 | 6 | 60% |
| 10 | 177 | 11 | 94% |
| 20 | 21,891 | 21 | 99.9% |
| 30 | 2,692,537 | 31 | 99.999% |

At n = 30 there are only **31 distinct subproblems** but **2.7 million calls**.
After the first 31, nothing new is ever computed.

## Key insight

The gap between *distinct subproblems* and *calls made* is the whole of
dynamic programming.

> **Overlapping subproblems** — the same input recurs across different
> branches of the recursion tree.

Store each answer the first time it's computed and return the stored copy
afterwards, and the tree collapses to a single path: O(1.618ⁿ) → **O(n)**.
That's memoization, and it arrives in Week 5. Nothing about the recurrence
changes; only how many times it runs.

## See it

- **Interactive recursion tree:** https://sumnoon.github.io/90-days-of-dp/fib/ — drag n from 2
  to 9, click any node to light up every place that value is recomputed, then
  tick *memoize* and watch the tree collapse to a spine.
  ([source](../../../docs/fib/index.html))

## Worth trying

Run the file with `n = 45`, then `50`. Watching it stall is more convincing
than the table.
