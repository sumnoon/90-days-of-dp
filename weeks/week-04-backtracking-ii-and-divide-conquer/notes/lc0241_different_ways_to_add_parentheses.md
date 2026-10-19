# ⭐ LC 241: Different Ways to Add Parentheses

- **Solution:** [`solutions/lc0241_different_ways_to_add_parentheses.cpp`](../solutions/lc0241_different_ways_to_add_parentheses.cpp)
- **Day:** 26 (Fri)
- **Solved without help?** yes
- **Video, after solving:** NeetCode's LC 241 explanation

## What the call returns

`diffWaysToCompute(expression)` returns **every** value the expression can
take over all ways of adding parentheses, duplicates included.

**Returns** a list of values. **Passes down** a substring: the left or right
side of one operator.

## Recursive case

```cpp
for each operator c at position i:
    left  = diffWaysToCompute(expression.substr(0, i));
    right = diffWaysToCompute(expression.substr(i + 1));
    for every a in left, every b in right:  results.push_back(a c b);
```

Divide & conquer, like merge sort, but the split point isn't fixed: **every
operator takes a turn as the last one applied**. Whatever goes on around it,
the operator done last splits the expression into a left part and a right
part, and each part can be bracketed any way at all. So: solve both sides
(leap of faith), then combine every left answer with every right answer.

## Base case

```cpp
if (results.empty()) results.push_back(stoi(expression));
```

No operator found: the expression is a plain number. Checking for "no
results" after the loop instead of scanning for operators first is neat: one
loop does both jobs.

## Solved more than once (Friday's question)

Measured with an instrumented copy, counting every call per substring:

| Expression | results | calls | different substrings | solved more than once |
|---|---|---|---|---|
| `2*3-4*5` | 5 | 27 | 10 | 7 |
| `1+2-3*4+5` | 14 | 81 | 15 | 12 |
| `1+1+1+1+1+1+1+1+1+1` | 4,862 | **19,683** | **10** | 9 |

In `2*3-4*5`, `"3"` and `"4"` are each solved **5 times**, `"2"` and `"5"` 4
times, and `"2*3"`, `"3-4"`, `"4*5"` twice: the top-level split at `-` asks
for `"2*3"` as its left side, and so does the split of `"2*3-4"` at its own `-`. With ten 1s the
code makes 19,683 calls to answer questions about only 10 different strings.
That's Fibonacci's overlapping subproblems again, and **Sunday's Month 1
checkpoint** is to remove it by adding a cache.

## Complexity

Without a cache: the number of results alone is a **Catalan number**
(4,862 for ten numbers, the same count as LC 22's 9 pairs), and the calls grow
exponentially; ten numbers took 19,683 = 3⁹. LeetCode's limit (20 characters)
keeps it small.

## Small notes on the code

- `expression.substr(...)` builds new strings on every call; passing a range
  (start, end) into one string would avoid the copies.
- `i < expression.length()` and `j < left.size()` compare `int` with unsigned
  sizes (`-Wall`).
- The final `else if (c == '*')` can be a plain `else`.

## Tested

LeetCode's two examples, plain numbers (`7`, `99`), `1+2`, `2*3*4` (two
results, both 24), `10-5-2-1`, `11*2-3+4*5-6`, and 200 random expressions of
up to 20 characters: every result list matches, as a multiset, a reference
that combines token ranges bottom-up.

## Key insight

Every operator takes a turn as the last one applied; combine every left answer with every right answer.
