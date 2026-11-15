# ⭐ LC 300: Longest Increasing Subsequence

- **Solution:** [`solutions/lc0300_longest_increasing_subsequence.cpp`](../solutions/lc0300_longest_increasing_subsequence.cpp)
- **Day:** 41 (Week 6 Sat), O(n²) versions solved on Mon 16 Nov
- **Solved without help?** yes
- **Still to do:** the O(n log n) version.

Find the length of the longest strictly increasing subsequence. Its elements
keep their order but needn't be next to each other.

## Two states for the same problem

The two O(n²) versions ask different questions, and that changes both the
transition and where the answer comes from. This is Week 6's key idea:
"ends exactly at `i`" versus "from here on, given what came before".

### 1. Memoized: take or skip, remembering the last taken

`calc(idx, prev)` = **the longest increasing subsequence of `nums[idx..]`
whose elements are all above `nums[prev]`** (`prev = −1`: nothing taken yet).

```cpp
int exclude = calc(idx + 1, prev, n, nums);
if (prev == -1 || nums[idx] > nums[prev]) include = 1 + calc(idx + 1, idx, n, nums);
```

- **skip** `nums[idx]`: `prev` stays the same;
- **take** it, allowed only if it's bigger than `nums[prev]`: it becomes the
  new `prev`.

Base case: `idx == n`, no numbers left, so 0. The answer is `calc(0, −1)`.

`prev` can be −1, so it's stored at `memo[idx][prev + 1]`: the shift by one
makes column 0 mean "nothing taken yet".

### 2. Table: the longest one that ends at `i`

`memo[i]` = **the length of the longest increasing subsequence that ends
exactly at `nums[i]`**.

```cpp
if (nums[j] < nums[i]) memo[i] = max(memo[i], memo[j] + 1);
```

Split on the element **before** `i`: any earlier `j` with a smaller value can
come before `nums[i]`. Base case: `nums[i]` alone, so every entry starts at 1.

The best subsequence can end anywhere, so the answer is **the largest
`memo[i]`**, not `memo[n − 1]`, which is why `ans` is updated in the loop.
It's LC 53's "ending at `i`" state, looking back at every earlier `j`
instead of just `i − 1`.

## Two versions, one class

| Call | Version |
|---|---|
| `lengthOfLISMemo(nums)` | take / skip with `prev`; resets `memo` itself |
| `lengthOfLIS(nums)` | ending at `i` (submitted) |

## Complexity

Both are **O(n²)** time: n × (n + 1) states with one step each, or two nested
loops. Space is O(n²) for the memoized version and O(n) for the table.

## Small notes on the code

- `int memo[2510][2510]` is **25 MB**, and `memset` clears all of it on every
  call, even for a 3-number array. It fits LeetCode's limits, but the test
  creates the `Solution` with `make_unique` because it would never fit on the
  stack. A `vector` sized `n × (n + 1)` per call would use only what's needed.
- `calc`'s `n` parameter is never used.
- The table's local `memo` hides the class member (`-Wshadow`), and its
  `n + 1` slots are one more than it uses.
- The recursion is at most n + 1 calls deep, 2,501 here, so the stack is fine.

## Tested

- LeetCode's three examples
- `[5]`, increasing, decreasing, `[-10000, 10000]` and `[3, 1, 2, 1, 2, 3]`
- 300 random arrays of 1–16 numbers from −5 to 5, so lots of repeats
  (strictly increasing means equal values can't both be taken)
- LeetCode's limit: 2,500 increasing numbers, and 2,500 random ones

The small cases were checked against a brute force that tries every
subsequence. The 2,500-number cases are too long for that, so the two
versions were checked against each other.

## Key insight

Choose the state first: "longest from `idx` on, above `nums[prev]`" needs `prev` in the state, while "longest ending at `i`" needs only `i`, but then the answer is the max over every `i`.
