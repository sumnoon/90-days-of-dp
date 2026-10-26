# LC 740: Delete and Earn

- **Solution:** [`solutions/lc0740_delete_and_earn.cpp`](../solutions/lc0740_delete_and_earn.cpp)
- **Day:** 33 (Fri)
- **Solved without help?** yes. The second version followed a hint about the
  first one's speed.

## The idea

Taking a value `v` deletes every `v − 1` and `v + 1`, so you may as well take
**every copy** of `v`: that earns `v × (copies of v)`. Write that down for
every value and the problem is **LC 198 House Robber**. The values are the
houses, and robbing `v` blocks its neighbours `v − 1` and `v + 1`.

```cpp
vector<int> sums(mx + 1, 0);
for (auto num : nums) sums[num] += num;      // sums[v] = v × copies of v
return calcMemo(0, sums);                    // House Robber on sums
```

## State and recurrence

`calcMemo(idx, sums)` returns **the most points from values `idx` up to
`mx`**. The recurrence is House Robber's, unchanged:

```cpp
return memo[idx] = max(calcMemo(idx + 2, sums) + sums[idx], calcMemo(idx + 1, sums));
```

Take value `idx` and jump to `idx + 2`, or skip it. A value that never
appears has `sums[v] = 0`, which works as an empty house: nothing to take.

Base case: `idx >= sums.size()` means no values left, so 0.

## Complexity

O(n) to build `sums`, then O(max value) states, one step each: **O(n + max
value)**, no sort needed. The recursion is at most 10,001 calls deep (one per
value), which fits even Windows' default stack.

## The first version, and why it changed

The first version sorted `nums` and ran take / skip over **indices**:

- take every copy of `cur`, then jump past the `cur + 1`s;
- or skip to `idx + 1`.

It was correct. But each state walked its run of equal values, and skipping
by one index started the same walk again one position later. A run of k equal
numbers cost about k²/2 steps.

| Input (LeetCode's limits) | First version, `-O0` | This version |
|---|---|---|
| 20,000 random numbers | 3 ms | 0 ms |
| 20,000 copies of 10,000 | **1,343 ms** | 0 ms |

Grouping equal values *before* the DP, instead of during it, removes the
repeated walk, and the sort along with it.

## Small notes on the code

- `memo[20001]` is sized for 20,000 indices, but this version indexes by value
  (up to 10,000). 10,001 slots would do.
- Three `int` vs `size()` comparisons (`-Wall`).
- `calcRecurse` is the same recursion without the cache; the tests check it on
  small inputs.

## Tested

- LeetCode's two examples
- small cases: `[1]`, `[1, 1, 1]`, `[1, 2]`, `[1, 3]`, and a mixed
  10-number case
- 500 random arrays of up to 30 numbers from small ranges
- LeetCode's limits: 20,000 random numbers, and 20,000 copies of 10,000

Both the memoized and the plain recursion match an independent House Robber
reference.

## Key insight

Taking a value means taking all its copies and losing its neighbours, so add up each value's points and run House Robber over the values.
