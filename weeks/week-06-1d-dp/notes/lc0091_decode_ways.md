# ⭐ LC 91: Decode Ways

- **Solution:** [`solutions/lc0091_decode_ways.cpp`](../solutions/lc0091_decode_ways.cpp)
- **Day:** 40 (Week 6 Fri), solved on Tue 10 Nov
- **Solved without help?** yes

Count the ways to read a digit string as letters, with `A` = 1 … `Z` = 26.

## State

`calc(idx)` returns **the number of ways to decode `s[idx..]`**. The answer is
`calc(0)`.

## Transition

Split on the **first piece**. It's one digit or two, and the two cases can't
overlap, so the counts add:

- **one digit:** allowed unless `s[idx]` is `'0'`, then `calc(idx + 1)`;
- **two digits:** allowed if the first digit isn't `'0'` and the value is at
  most 26, then `calc(idx + 2)`.

It's LC 70 with a validity check on each step. A string of all `1`s gives
exactly the Fibonacci numbers.

## Base case

`idx == n`: the whole string has been used, and that's **one** complete
decoding, so return 1. Returning 0 would make every count 0.

A `'0'` needs no base case of its own. With both options blocked, `first` and
`second` stay 0, so that path counts for nothing: `"06"` gives 0.

## Complexity

At most n + 1 states, one step each: **O(n)** by state count. `string s` is
passed by value, so each call also copies the string, making it O(n²) in
total. With n ≤ 100 that doesn't matter here.

## Small notes on the code

- `const string& s` would remove that copy.
- `tens < 3` isn't needed: `10 * tens + ones <= 26` already rules out larger
  tens digits.
- `idx >= n` could be `idx == n`, since `idx + 2` is only reached when
  `idx + 1 < n`.
- `memo[110]` is sized for LeetCode's 100 characters, and `numDecodings` resets
  it, so one object can be reused.

## Tested

- LeetCode's three examples
- zero cases: `"0"`, `"10"`, `"27"`, `"100"`, `"101"`, `"230"`, `"2101"`,
  `"1201234"` and `"11106"`
- 5,000 random strings of 1–20 digits, weighted towards 0, 1 and 2
- long strings: 40 ones (165,580,141 ways), 100 nines (1 way) and `"10"`
  repeated 50 times (1 way)

Built with `-ftrapv`; no overflow. The random and fixed cases were checked
against a separate uncached recursion in `long long`.

## Key insight

Split on the first piece, one digit or two, and let a `'0'` that can't be read simply contribute 0: it's Climbing Stairs where each step must be a valid letter.
