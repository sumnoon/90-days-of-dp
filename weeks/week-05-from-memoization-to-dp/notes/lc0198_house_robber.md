# ⭐ LC 198: House Robber, four versions

- **Solution:** [`solutions/lc0198_house_robber.cpp`](../solutions/lc0198_house_robber.cpp)
- **Day:** 32 (Thu)
- **Solved without help?** yes
- **This week's checkpoint:** write all four from memory.

## State: what the call returns

`func(nums, idx)` returns **the most money from houses `idx` to the end**.
The answer is `func(nums, 0)`.

## 1. Plain recursion: the choice

```cpp
return max(func(nums, idx + 2) + nums[idx], func(nums, idx + 1));
```

At house `idx` there are two choices:

- **rob it:** take `nums[idx]`, and the next house you're allowed is `idx + 2`.
- **skip it:** move on to `idx + 1` with nothing taken.

Keep the better one. Base case: `idx >= nums.size()` means no houses left, so
0.

Compared with LC 746: there you *must* pay for the step you're on and choose
where to go next; here you choose *whether to take* the house you're on.

## 2. Memoized

The same function with `memo[idx]` in front. Each `idx` is computed once:
O(n). `memo` has to be filled with −1 before the first call. `rob` doesn't do
that because it doesn't call `func_memo`, so the test does it.

## 3. Table: bottom-up

```cpp
memo[0] = 0;  memo[1] = nums[0];
for (int i = 1; i < n; ++i) memo[i + 1] = max(memo[i - 1] + nums[i], memo[i]);
```

This one turns the state around: `memo[k]` is **the best from the first `k`
houses**, shifted by one so `memo[0]` (no houses) needs no special case.

- rob house `i`: the best of the first `i - 1` houses, `memo[i - 1]`, plus
  `nums[i]`
- skip it: the best of the first `i` houses, `memo[i]`

The memoized version works **from the end** (houses `idx` onward), the table
**from the start** (the first `k` houses). Both are correct; what matters is
that each entry only reads entries already filled in.

## 4. O(1) space: what `rob` submits

```cpp
next = max(prev + nums[i], cur);
prev = cur;
cur = next;
```

The table only ever reads its last two entries, so keep just those:
`prev` = `memo[i - 1]` and `cur` = `memo[i]`. Then shift both along by one.

## Measured

Plain recursion on 30 houses takes 17 ms; on 40 houses, **2.2 s**. Every house
added multiplies the time by about 1.6, Fibonacci's growth again. The other
three versions are O(n), and LeetCode's 100 houses are instant.

## Small notes on the code

- `bottomO_up` has a stray `O`: `bottom_up`.
- `func` and `func_memo` compare `int idx` with `nums.size()` (`-Wall`).

## Tested

- LeetCode's two examples
- small cases: one house, `[0]`, two houses both ways round,
  `[2, 1, 1, 2]` (skips two in a row) and `[400, 0, 0, 400]`
- 500 random arrays of 1–16 houses

**All four versions** were checked against a brute force that tries every set
of houses with no two next to each other.

## Key insight

At each house: rob it and jump two, or skip it and move one. Keep the better; then notice the table only needs its last two entries.
