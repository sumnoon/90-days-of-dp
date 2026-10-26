# LC 740: Delete and Earn

- **Solution:** [`solutions/lc0740_delete_and_earn.cpp`](../solutions/lc0740_delete_and_earn.cpp)
- **Day:** 33 (Fri)
- **Solved without help?** yes

## The idea

Taking a value `v` deletes every `v − 1` and `v + 1`, so you may as well take
**every copy** of `v`. Once the numbers are sorted, equal values sit together
and `v + 1` comes right after them, which turns the problem into House Robber
over **runs of equal values**.

## State: what the call returns

After sorting, `calcMemo(idx, nums)` returns **the most points from
`nums[idx..]`**, assuming nothing before `idx` blocks it.

## Recurrence

```cpp
// take: every copy of cur, then jump past all the cur + 1's
sum = cur * (copies of cur);   ind = first index after the cur + 1's
return memo[idx] = max(sum + calcMemo(ind, nums), calcMemo(idx + 1, nums));
```

- **take** `cur`: earn every copy, and skip the `cur + 1`s, which taking `cur`
  deletes. Like robbing a house and jumping two.
- **skip** it: move on to `idx + 1`.

Skipping by one index can land on another copy of the same value, and taking
it there earns *fewer* copies. That's never better than taking at the start of
the run, so `max` ignores it: the answer stays right.

## Base case

`idx >= nums.size()`: nothing left, 0 points.

## Complexity

Sorting is O(n log n). The memo is keyed on `idx`, so there are at most n
states, **but each one walks over its run of equal values**. That walk is
repeated from every position in the run, so a run of k equal numbers costs
about k²/2 steps.

| Input (LeetCode's limits) | `-O0` | `-O2` |
|---|---|---|
| 20,000 random numbers | 3 ms | 1 ms |
| 20,000 copies of 10,000 | **1,343 ms** | 47 ms |

It passes, but the second row is O(n²) where O(n) is possible.

*Hint, if you want to fix it:* when you **skip** a value, you skip all its
copies too. Where should the skip branch jump to?

## The other way: House Robber over the values

The usual solution makes `points[v] = v × (number of v's)` for every `v` up to
10,000, then runs LC 198 on `points`: robbing `v` blocks its neighbours `v − 1`
and `v + 1`. That's O(n + max value) with no sort. The tests use it as the
reference answer.

## Small notes on the code

- **Stack depth.** The recursion goes as deep as `nums.size()`: 20,000 calls.
  That's fine on LeetCode, but more than Windows' 1 MB default stack holds at
  `-O0`. The test file's header says how to build it with a bigger stack.
- `sum += nums[idx]` is right, since `nums[idx] == cur`, though `+= cur`
  says what it means.
- `calcRecurse` (no cache) is the same recursion; the tests check it on small
  inputs.
- `memo[20001]` is sized from the limit: indices go up to 19,999.
- Six `int` vs `nums.size()` comparisons (`-Wall`).

## Tested

- LeetCode's two examples
- small cases: `[1]`, `[1, 1, 1]`, `[1, 2]`, `[1, 3]`, and a mixed
  10-number case
- 500 random arrays of up to 30 numbers from small ranges, so there are lots
  of runs and neighbours

Both the memoized and the plain version match the House Robber reference. At
LeetCode's limits (run with `--limits`), both large inputs come out right.

## Key insight

Taking a value means taking all its copies and losing its neighbours, so after sorting it's House Robber over runs of equal values.
