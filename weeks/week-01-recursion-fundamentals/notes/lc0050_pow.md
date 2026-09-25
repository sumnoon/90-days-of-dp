# LC 50: Pow(x, n) ⭐

- **Link:** https://leetcode.com/problems/powx-n/
- **Solution:** [`solutions/lc0050_pow.cpp`](../solutions/lc0050_pow.cpp)
- **Day:** 5 (Fri)
- **Solved without help?** yes

The last Week 1 problem, and the first where the recursion's *shape* — not
just its correctness — decides whether it finishes at all.

## What the call returns

`helper(x, n)` — xⁿ, for any `n` including negatives.

## Recursive case

```cpp
if (n < 0)  return 1.0 / helper(x, -1 * n);          // x^-n = 1 / x^n
if (n & 1)  return x * helper(x * x, (n - 1) / 2);   // odd:  x * (x²)^((n-1)/2)
else        return helper(x * x, n / 2);             // even: (x²)^(n/2)
```

The smaller input isn't `n - 1`. It's **`n / 2` with the base squared**:
x¹⁰ = (x²)⁵. Each call cuts the exponent in half and moves the work into the
base. An odd exponent can't halve cleanly, so it peels one `x` off first:
x⁵ = x · (x²)².

## Base case

`n == 0 → 1`. The identity for multiplication again, the same reasoning as
[factorial](warmup_recursion.md).

## Complexity

Time: **O(log n)**. Space: **O(log n)** for the call stack.

## Why halving gives O(log n)

Measured by instrumenting the real function:

| n | naive `x * pow(x, n-1)` | this solution | binary digits of n |
|---|---|---|---|
| 10 | 11 | 5 | 4 |
| 1,000 | 1,001 | 11 | 10 |
| 1,000,000 | 1,000,001 | 21 | 20 |
| 10⁹ | 1,000,000,001 | 31 | 30 |
| `INT_MAX` | 2,147,483,648 | **32** | 31 |
| `INT_MIN` | 2,147,483,649 | 34 | 32 |

The fast column is always **the number of binary digits in n, plus one** for
the base case — plus one more for a negative `n`, whose wrapper frame does the
`1.0 /`. That isn't a coincidence — it's the whole idea:

- **Halving an integer drops one binary digit.** `n / 2` is `n >> 1`.
- **`n & 1` reads the lowest digit.** Odd means the last bit is 1, so that
  step contributes a factor of `x`.

So the recursion walks n's binary representation one bit per call. Tracing
n = 10, which is `1010` in binary:

```
10  even  → square, halve      (bit 0)
 5  odd   → peel an x, halve   (bit 1)
 2  even  → square, halve      (bit 0)
 1  odd   → peel an x, halve   (bit 1)
 0  base case
```

A number n has about log₂ n bits, so there are about log₂ n calls. Every
problem that halves its input gets this, which is why
[LC 231](lc0231_power_of_two.md) was O(log n) too — same shape, one line of
work different.

The naive version doesn't just run slowly at `INT_MAX`. It needs 2.1 billion
stack frames, and a default stack holds tens to hundreds of thousands,
depending on platform and frame size.
**It crashes long before it finishes.** O(log n) here is the difference
between an answer and a stack overflow.

## Key insight: the `INT_MIN` trap

`n` arrives as an `int`, range −2³¹ to 2³¹−1. The negative case negates it,
and **−(−2³¹) = 2³¹ does not fit in an `int`** — it's signed overflow, which
is undefined behaviour in C++. On most machines it silently wraps back to
−2³¹ and the recursion never terminates.

This solution avoids it by widening *before* the negation:
`helper(double x, long long n)`. The `int` becomes a `long long` at the call
boundary, so `-1 * n` happens in 64 bits, where 2³¹ is an ordinary number.

**The order matters.** `helper(x, (long long)(-n))` would still be wrong: the
negation would run on the `int` first and overflow, and only then get widened.

Handling it costs one extra frame: the table shows `INT_MIN` at 34 calls, 32
bits plus the base case plus the negative wrapper.

## Tested

13 cases, each checked against `std::pow`:

| x | n | result | why it's there |
|---|---|---|---|
| 2.0 | 10 | 1024 | LeetCode example 1 |
| 2.1 | 3 | 9.261 | LeetCode example 2 |
| 2.0 | −2 | 0.25 | LeetCode example 3 |
| 5.0 | 0 | 1 | base case |
| 1.0 | `INT_MIN` | 1 | the trap |
| 2.0 | `INT_MIN` | 0 | the trap, underflowing |
| −1.0 | `INT_MIN` | 1 | `INT_MIN` is even |
| −1.0 | `INT_MAX` | −1 | `INT_MAX` is odd |
| 0.5 | `INT_MAX` | 0 | deepest recursion, tiny result |
| −2.0 | 3 / 4 | −8 / 16 | negative base, odd and even n |
| 0.0 | 5 | 0 | zero base |
| 1.00001 | 123456 | 3.436844752 | many squarings, precision holds |

## Small notes on the code

- For odd `n`, `(n - 1) / 2` and `n / 2` are equal in integer division
  (5 / 2 = 2), so either works. `(n - 1) / 2` states the intent more plainly:
  one `x` is peeled off, and what's left is even.
- The stack peaks at about 32 frames even for the largest input, so recursion
  is entirely safe here — unlike the naive version.
