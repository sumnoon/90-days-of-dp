# LC 152: Maximum Product Subarray

- **Solution:** [`solutions/lc0152_maximum_product_subarray.cpp`](../solutions/lc0152_maximum_product_subarray.cpp)
- **Day:** 37 (Week 6 Tue), solved on Thu 5 Nov
- **Solved without help?** yes

Find the largest product of a non-empty run of neighbouring numbers.

## The idea: the best run is a prefix or a suffix

Take a stretch with **no zeros**. Every number's size is at least 1, so making
the run longer never makes the product smaller in size; only its **sign**
matters.

- An **even** number of negatives: the whole stretch is positive, and it's the
  best.
- An **odd** number: one negative has to go. Cut after the first negative and
  keep everything after it (a suffix), or cut before the last negative and
  keep everything before it (a prefix).

Either way the answer is a prefix or a suffix of the stretch. A **zero** ends
a stretch: no useful run goes through it.

## What the code tracks

```cpp
l *= nums[i];          // product of the current stretch's prefix, from the left
r *= nums[n - i - 1];  // product of the current stretch's suffix, from the right
res = max(res, max(l, r));
if (l == 0) l = 1;     // a zero ends the stretch: start a new one
```

- `l` is the product from the start of the current stretch up to `i`: every
  prefix of every stretch is seen.
- `r` is the same from the right, so every suffix is seen.
- `res` is compared **before** the reset, so a 0 counts as an answer itself:
  `[-2, 0, -1]` gives 0.
- `res` starts at `nums[0]`, so a single negative number such as `[-2]`
  returns −2.

## Compared with the plan's version

The plan's hint, "track both max and min", is the DP form: keep the largest
and the smallest product of a subarray **ending at `i`**, because a negative
number turns the smallest into the largest. That's LC 53's state with a
second variable. This solution skips the DP by proving the answer is a prefix
or a suffix instead.

## Complexity

One pass: **O(n)** time, O(1) space.

## Overflow

`l` and `r` are always products of a real subarray (a stretch's prefix or
suffix), and LeetCode guarantees every subarray's product fits in an `int`.
The tests run with `-ftrapv`, which aborts on any signed overflow; none
happened.

## Tested

- LeetCode's two examples
- small cases: `[-2]`, `[0]`, `[-2, 3, -4]`, `[-1, -1]`, `[0, 2]`,
  `[2, -5, -2, -4, 3]`, `[-3, 0, -2, 0, -1]` and `[3, -1, 4]`
- 5,000 random arrays of 1–12 numbers from −4 to 4, many with zeros
- LeetCode's limit: 20,000 numbers mixing ±1, ±10 and a 0

All checked against a brute force that multiplies out every subarray in
`long long`.

## Key insight

Between zeros, only the sign matters, and it is fixed by dropping everything up to the first negative or from the last one; so the best run is a prefix or a suffix, and one pass from each end finds it.
