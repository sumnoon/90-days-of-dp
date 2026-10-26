# LC 1137: N-th Tribonacci Number

- **Solution:** [`solutions/lc1137_nth_tribonacci_number.cpp`](../solutions/lc1137_nth_tribonacci_number.cpp)
- **Day:** 33 (Fri)
- **Solved without help?** yes. The cache was added after the plain version
  turned out too slow.

LC 509 with three terms instead of two: `T(n) = T(n − 1) + T(n − 2) + T(n − 3)`,
with `T(0) = 0` and `T(1) = T(2) = 1`.

## Three versions, as in LC 509

- **`calcRecurse`:** plain recursion. Correct, but every call makes three
  more.
- **`calcMemo`:** the same recursion with `memo[n]`; each `n` is computed
  once. `memo` must be filled with −1 before the first call; `tribonacci`
  does that, but `calcMemo` called on its own doesn't.
- **`tribonacci`:** the table. Fill `memo[3]`, `memo[4]`, … in order, so the
  three entries before `memo[i]` are always ready. This is the one submitted.
  It doesn't use the cache, so the `memset` to −1 isn't needed here.

## Measured at n = 37 (LeetCode's largest)

| Version | Work | Time |
|---|---|---|
| plain recursion | **4,047,854,365 calls** | 7.7 s (`-O2`) |
| memoized | 37 values, each once | 0.4 µs |
| table | 35 loop steps | 0.1 µs |

Branching three ways makes the plain version grow far faster than Fibonacci:
n = 37 makes **12 times** as many calls as LC 509 does at n = 40.

## Small notes on the code

- `T(37) = 2,082,876,103` is just under `INT_MAX` (2,147,483,647), which is
  why LeetCode stops at 37.
- `memo[41]` only needs 38 slots.
- Like House Robber, the table only reads its last three entries, so three
  variables would do instead of an array.

## Tested

n = 0 … 37 against the sequence built independently. The table and the
memoized versions were checked for every n; plain recursion up to 25.

## Key insight

Same as Fibonacci with one more term; three-way branching makes the uncached recursion blow up even faster, so the cache matters more.
