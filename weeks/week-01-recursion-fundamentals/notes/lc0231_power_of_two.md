# LC 231: Power of Two

- **Link:** https://leetcode.com/problems/power-of-two/
- **Solution:** [`solutions/lc0231_power_of_two.cpp`](../solutions/lc0231_power_of_two.cpp)
- **Day:** 3 (Wed)
- **Solved without help?** yes

## What the call returns

`isPowerOfTwo(n)` — true if `n == 2^k` for some integer `k >= 0`.

## Recursive case

```cpp
if (n == 0) return false;
return ((n == 1) || (n % 2 == 0 && isPowerOfTwo(n / 2)));
```

Keep halving while the number stays even. If it's still even, the question
for `n` is the same question for `n / 2`.

## Base case

Three ways out, and only one of them recurses:

| Condition | Result | Why |
|---|---|---|
| `n == 0` | false | 0 is never a power of two, and halving it would loop forever |
| `n == 1` | true | 2⁰ = 1, the bottom of every successful chain |
| `n` odd and `n != 1` | false | short-circuit `&&` stops before recursing |

## Complexity

Time: O(log n) — each call halves `n`. Space: O(log n) for the stack.

## Key insight

**Short-circuit `&&` is the base case here.** `n % 2 == 0 && isPowerOfTwo(n / 2)`
never recurses when `n` is odd, so the odd-number rejection costs nothing and
needs no separate `if`. Writing the condition in the other order, or with `&`
instead of `&&`, would recurse anyway.

Negatives fall out for free: halving −16 walks −8, −4, −2, −1, and −1 is
neither 1 nor even, so it returns false without a special case.

## Tested

| n | 1 | 2 | 3 | 4 | 16 | 1024 | 2³⁰ | 0 | −16 | 5 |
|---|---|---|---|---|---|---|---|---|---|---|
| | true | true | false | true | true | true | true | false | false | false |

## Aside

The famous O(1) bit trick is `n > 0 && (n & (n - 1)) == 0`, which clears the
lowest set bit and checks that nothing is left. Worth knowing, but the
recursive version is the point this week. Bit tricks come back in Week 12
(bitmask DP).
