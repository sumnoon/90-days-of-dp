# ⭐ LC 300: Longest Increasing Subsequence

- **Solution:** [`solutions/lc0300_longest_increasing_subsequence.cpp`](../solutions/lc0300_longest_increasing_subsequence.cpp)
- **Day:** 41 (Week 6 Sat). The O(n²) versions were solved on Mon 16 Nov, and
  O(n log n) on Tue 17 Nov.
- **Solved without help?** yes

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

### 3. O(n log n): the smallest possible tail of each length

`memo[k]` = **the smallest value that can end an increasing subsequence of
length `k + 1`**, among the numbers seen so far.

```cpp
int pos = lower_bound(memo.begin(), memo.end(), nums[i]) - memo.begin();
if (pos == memo.size()) memo.push_back(nums[i]);
else memo[pos] = nums[i];
```

- `memo` is always **strictly increasing**: a longer subsequence's tail can't
  be smaller than a shorter one's. That's what makes binary search possible.
- `lower_bound` finds the first tail `>= nums[i]`. Everything before it is
  smaller, so `nums[i]` extends the subsequence of length `pos` and ends one of
  length `pos + 1`.
- If no tail is that large, `nums[i]` makes a **new, longer** subsequence:
  `push_back`.
- Otherwise it replaces that tail with a smaller (or equal) one, which only
  makes future extensions easier.

The answer is `memo.size()`, the longest length reached. `memo` itself is
**not** an increasing subsequence of `nums`: on `[3, 4, 1]` it ends as
`[1, 4]`, though 1 comes after 4. Only its length is meaningful.

`lower_bound` (first `>=`) rather than `upper_bound` (first `>`) is what keeps
it **strictly** increasing. An equal value replaces its twin instead of
extending it, so `[7, 7, 7]` gives 1.

This isn't a DP over indices like the other two. It keeps the same
information as the table, but organised by **length** instead of by **end
position**, so a binary search can replace the inner loop.

## Three versions, one class

| Call | Version |
|---|---|
| `lengthOfLISMemo(nums)` | take / skip with `prev`; resets `memo` itself |
| `lengthOfLISTable(nums)` | ending at `i` |
| `lengthOfLIS(nums)` | smallest tail per length, O(n log n) (submitted) |

## Complexity

| Version | Time | Space |
|---|---|---|
| memoized | O(n²): n × (n + 1) states, one step each | O(n²) |
| table | O(n²): two nested loops | O(n) |
| smallest tails | **O(n log n)**: one binary search per number | O(n) |

## Small notes on the code

- `int memo[2510][2510]` is **25 MB**, and `memset` clears all of it on every
  call, even for a 3-number array. It fits LeetCode's limits, but the test
  creates the `Solution` with `make_unique` because it would never fit on the
  stack. A `vector` sized `n × (n + 1)` per call would use only what's needed.
- `calc`'s `n` parameter is never used.
- The table's local `memo` hides the class member (`-Wshadow`), and its
  `n + 1` slots are one more than it uses. The O(n log n) version's local
  `memo` does the same, and its `ans` is never used.
- The recursion is at most n + 1 calls deep, 2,501 here, so the stack is fine.

## Tested

- LeetCode's three examples
- `[5]`, increasing, decreasing, `[-10000, 10000]` and `[3, 1, 2, 1, 2, 3]`
- 300 random arrays of 1–16 numbers from −5 to 5, so lots of repeats
  (strictly increasing means equal values can't both be taken)
- LeetCode's limit: 2,500 increasing numbers, and 2,500 random ones

The small cases were checked against a brute force that tries every
subsequence. The 2,500-number cases are too long for that, so the three
versions were checked against each other.

## Key insight

Choose the state first: "longest from `idx` on, above `nums[prev]`" needs `prev` in the state, while "longest ending at `i`" needs only `i`, but then the answer is the max over every `i`. Keep only the smallest tail for each length, and that list is sorted, so a binary search gives O(n log n).
