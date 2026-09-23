# Print 1..N and N..1 recursively

- **Solutions:** [`solutions/day1_1ToN.cpp`](../solutions/day1_1ToN.cpp) and
  [`solutions/day1_NTo1.cpp`](../solutions/day1_NTo1.cpp)
- **Day:** 1 (Mon)
- **Solved without help?** yes

One note for both, because the contrast *is* the lesson. The two files are
the same function with one line moved.

## The two versions

```cpp
void func(int n) {                 void func(int n) {
    if (n == 0) return;                if (n == 0) return;
    func(n - 1);   // recurse           cout << n << endl;  // print
    cout << n << endl;  // print        func(n - 1);   // recurse
}                                  }
        prints 1..N                        prints N..1
```

## Why the order flips

The calls happen in the same order either way: `func(5)`, `func(4)`, …
`func(1)`. What changes is **when the work happens relative to the call**.

- **Print before recursing** (pre-order): each frame does its work on the way
  *down*, so the largest `n` prints first → `5 4 3 2 1`.
- **Print after recursing** (post-order): each frame waits for every smaller
  call to finish, then prints on the way back *up*, so the deepest frame
  (`n = 1`) prints first → `1 2 3 4 5`.

Nothing is reversed and no extra storage is used. The call stack holds the
order for you: the unwinding is what plays it back.

## Base case

`n == 0` returns without printing, so `n = 0` correctly prints nothing.

## Complexity

Time: O(n). Space: O(n) for the call stack.

## Key insight

**Work before the recursive call happens top-down; work after it happens
bottom-up.** That single choice is the whole difference between these two
programs — and it keeps coming back:

- [LC 206](lc0206_reverse_linked_list.md) rewires links *after* the call, so
  the list reverses on the way back up.
- Pre-order / in-order / post-order tree traversal is this same choice
  (Week 2).
- Every DP recurrence is post-order: solve the subproblems, *then* combine.
