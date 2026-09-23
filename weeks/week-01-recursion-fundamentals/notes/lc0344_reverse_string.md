# LC 344: Reverse String

- **Link:** https://leetcode.com/problems/reverse-string/
- **Solution:** [`solutions/lc0344_reverse_string.cpp`](../solutions/lc0344_reverse_string.cpp)
- **Day:** 1 (Mon)
- **Solved without help?** yes

## What the call returns

Nothing. `func(s, l, r)` reverses the slice `s[l..r]` **in place**, which is
what the problem demands.

## Recursive case

```cpp
swap(s[l], s[r]);
func(s, l + 1, r - 1);
```

Swap the outermost pair, then hand the middle slice to the recursion.

## Base case

`r <= l` returns immediately — a slice of one character (or none) is already
reversed. Identical to the palindrome check's base case, for the same reason.

## Complexity

Time: O(n). Space: **O(n)** for the call stack.

Note the mismatch with the problem statement: LC 344 asks for O(1) extra
memory. The recursive version is accepted, but n/2 stack frames are not O(1).
The iterative two-pointer loop is the honest O(1) answer, and is what an
interviewer will push for.

## Key insight

This and the palindrome check are **the same function** with different work
at each level:

| | work at each level | base case |
|---|---|---|
| Palindrome | compare the ends, bail on mismatch | `r <= l` → true |
| LC 344 | swap the ends | `r <= l` → return |

Once the traversal shape is right, changing the problem often just means
changing the one line in the middle. Spotting that a new problem reuses a
shape you already have is most of what "pattern recognition" means later on.

## Note on the file

The `Solution` class is exactly what was submitted to LeetCode. The includes
and `main` were added locally so the file runs on its own — LeetCode supplies
those.
