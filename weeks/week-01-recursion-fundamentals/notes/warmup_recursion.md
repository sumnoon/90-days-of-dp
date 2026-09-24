# Day 0 warm-ups: factorial and sum of digits

- **Solution:** [`solutions/warmup_recursion.cpp`](../solutions/warmup_recursion.cpp)
- **Day:** 0 (kickoff)
- **Solved without help?** yes

The first two recursive functions of the 90 days. No problem statement to
read, no edge cases to argue about — just the shape.

## What the call returns

| Function | Returns |
|---|---|
| `factorial(n)` | `n!` |
| `sum_of_digits(n)` | the sum of the decimal digits of `n` |

## Recursive case

```cpp
factorial(n)      = n * factorial(n - 1)
sum_of_digits(n)  = (n % 10) + sum_of_digits(n / 10)
```

Both follow the same question: *if I already had the answer for a smaller
input, what one operation turns it into the answer for this one?*

- For factorial, the smaller input is `n - 1` and the operation is `* n`.
- For sum of digits, `n % 10` peels off the last digit and `n / 10` is
  everything else, so the operation is `+ (n % 10)`.

## Base case

Both stop at `n == 0`:

- `factorial(0) = 1` — the empty product. Returning `0` here would make every
  answer `0`.
- `sum_of_digits(0) = 0` — the empty sum. It has to be `0`, not `n % 10`, so
  the recursive case can add cleanly at every level.

`factorial(1)` works without its own base case: it recurses once down to 0.

## Complexity

Time: O(n) for factorial, O(log₁₀ n) for sum of digits (one call per digit).
Space: the same, for the call stack.

## See it

- **Stack, building then unwinding:** https://sumnoon.github.io/90-days-of-dp/order/ —
  pick *factorial* or *sum of digits* and watch the value assemble on the way
  back up from the identity at the base case.
  ([source](../../../docs/order/index.html))

## Key insight

A base case isn't just "where it stops" — it's the **identity value** for
whatever the recursive case combines with. Multiplication combines with 1,
addition combines with 0. Pick the wrong one and every answer above it is
wrong, even though the recursion terminates perfectly.

## Gotcha

In C++ a missing base case doesn't raise a tidy error — it overflows the
stack and the process dies with no message. That's why the harness prints
each case label before it runs.
