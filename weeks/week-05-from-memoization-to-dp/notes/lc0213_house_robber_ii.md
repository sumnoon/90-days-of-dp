# ⭐ LC 213: House Robber II

- **Solution:** [`solutions/lc0213_house_robber_ii.cpp`](../solutions/lc0213_house_robber_ii.cpp)
- **Day:** 34 (Week 5 Sat), solved on Tue 27 Oct
- **Solved without help?** yes

## The idea

The houses are in a circle, so the first and the last are neighbours. You
can't rob both, so at least one of them is left out. Split on which one:

- **leave out the last:** LC 198 on houses `0 … n − 2`;
- **leave out the first:** LC 198 on houses `1 … n − 1`.

The answer is the better of the two. Every valid choice of houses falls into
at least one of those cases, and neither case can break the circle rule. So
the problem is just LC 198 run twice, with no new recurrence.

## Recurrence, inside each run

Unchanged from LC 198: `best = max(rob this one + best two back, skip it)`.
`calcConst` is the O(1)-space version, and `calc` / `calcMemo` the memoized
one.

## Base case

`n == 1`: a single house has no neighbour on either side, so take it. This
check matters, because both ranges would be empty without it.

## Small notes on the code

- **Two conventions for `en`.** `calc` treats it as the last house
  (`st > en` stops), while `calcConst` treats it as one past the last
  (`i < en`). Both are right as used, but `rob` passes `(0, n - 1)` and
  `(1, n)`, which only fits `calcConst`. Calling `calcMemo` with the same
  arguments would include the house you meant to leave out. Picking one
  convention avoids that trap; the tests call `calcMemo` with inclusive ends.
- `calcMemo` resets `memo` itself, so it's safe to call twice in a row, once
  for each range.
- `calcConst` reads `nums[st]` straight away, so it needs a range of at least
  one house; `n == 1` returning early guarantees that.

## Complexity

Two O(n) passes: **O(n)** time, O(1) space for `calcConst`.

## Tested

- LeetCode's three examples
- small cases: one house, `[0]`, two houses both ways round, `[9, 1, 1, 9]`
  (first and last are the best, but only one may be taken) and a 5-house case
- 500 random arrays of 1–16 houses

Both `rob` and the memoized version were checked against a brute force that
tries every set of houses, treating the first and last as neighbours.

## Key insight

The first and last houses can't both be robbed, so run LC 198 twice, once without each, and keep the better.
