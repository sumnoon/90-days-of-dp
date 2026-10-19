# ⭐ LC 912: Sort an Array (merge sort)

- **Solution:** [`solutions/lc0912_sort_an_array.cpp`](../solutions/lc0912_sort_an_array.cpp)
- **Day:** 24 (Wed)
- **Solved without help?** yes
- **Video:** the unnumbered *Merge Sort* video in Striver's recursion playlist

## What the call returns

`mergeSort(nums, start, end)` returns a **new** sorted vector holding
`nums[start..end]`. It doesn't change `nums`.

**Returns** the sorted piece. **Passes down** the range to sort.

This is **divide & conquer**, not backtracking: no choices, nothing to undo.
Split the problem in two, solve both halves the same way, combine the
answers. It's bottom-up like LC 104: each call waits for both halves to report
back.

## Recursive case

```cpp
int mid = start + (end - start) / 2;
vector<int> left = mergeSort(nums, start, mid);
vector<int> right = mergeSort(nums, mid + 1, end);
return merge(left, right);
```

Leap of faith: trust both calls to hand back their half sorted. Then only one
job is left, **merging two sorted lists**, which is LC 21 again with vectors
instead of linked lists: repeatedly take the smaller front element, then copy
whatever remains of the other.

`start + (end - start) / 2` instead of `(start + end) / 2` can't overflow,
a habit worth keeping even where indices are small.

## Base case

```cpp
if (start == end) return {nums[start]};
```

One element is already sorted.

**Empty input:** with `nums` empty, `end` is −1, `start == end` is false, and
the next call reads `nums[0]` out of bounds. LeetCode guarantees at least one
number, so it never happens there; `if (nums.empty()) return {};` would close
the gap.

## Merge

```cpp
while (i < a.size() && j < b.size())
    if (a[i] <= b[j]) take a[i]; else take b[j];
// then whatever is left of a, then of b
```

`<=` takes from the **left** half on ties, so equal values keep their
original order: the sort is **stable**. With `<` it would still sort
correctly, just not stably.

The two `empty()` checks at the top are shortcuts, not requirements: the
loops below already handle an empty side.

## The recurrence

*To write in your own words (Week 4 Wednesday task):* why merge sort costs
T(n) = 2T(n/2) + n, and why that works out to O(n log n). Two things a
complete answer covers:

1. where each of the three terms comes from (the 2, the n/2, the + n)
    - The $n/2$ (Size of Each Subproblem — Divide): You split the current array of length $n$ right down the middle (mid), producing two sub-arrays of length $n/2$ each. Calculating the midpoint index takes $\mathcal{O}(1)$ constant time, so the split itself adds negligible cost.
   - The $2$ (Number of Recursive Branches — Conquer): Because you have two independent halves (Left and Right), the function calls itself twice. Sorting a single half of size $n/2$ costs $T(n/2)$, so sorting both halves costs $2 \times T(n/2)$.
   - The $+ n$ (The Two-Pointer Merge Step — Combine): Once the two recursive calls return, you have two sorted halves of size $n/2$. Merging them into a single sorted array of size $n$ uses two pointers (i and j). On each iteration, you compare left_half[i] and right_half[j] and copy the smaller element into a temporary buffer. Because each step places one element into its final sorted position, placing all $n$ elements takes linear work proportional to $n$.
2. how many levels the recursion has, and how much merging happens on each
   level
   - The recursion has $\log_2 n$ merging levels (or $\log_2 n + 1$ total levels including the base cases), and every level performs exactly $n$ total merge operations because $2^i$ subproblems of size $n/2^i$ always multiply out to $n$.

## Complexity

Time: **O(n log n)**. Measured: 50,000 numbers (LeetCode's maximum) in
**10 ms**.
Space: **O(n)** at any moment for the vectors being merged, plus O(log n)
stack. This version also **allocates a new vector for every call**, about 2n
of them in total; the usual faster version merges into one shared buffer.

## Small notes on the code

- `i < a.size()` compares `int` with an unsigned size (`-Wall`).
- The file was named `0902_sort_an_array.cpp`; *Sort an Array* is **LC 912**.

## Tested

LeetCode's two examples, one and two numbers, negatives and the value limits
(±50,000), reversed and already-sorted input, 200 random arrays of up to 300
numbers drawn from a small range (lots of duplicates), and 50,000 random
numbers: every result matches `std::sort`.

## See it

- **Split, trust, merge:** https://sumnoon.github.io/90-days-of-dp/mergesort/ —
  one row per depth of the recursion, one box per call. Splitting does
  nothing; merging fills each parent box from the two fronts below it, and a
  counter beside each row adds up the merging done on that level: at most n,
  on about log n levels. ([source](../../../docs/mergesort/index.html))

## Key insight

Trust each half to come back sorted; the only real work is merging two sorted lists, LC 21 again.
