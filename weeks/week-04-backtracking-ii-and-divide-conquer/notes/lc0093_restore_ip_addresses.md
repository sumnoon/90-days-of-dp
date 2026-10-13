# LC 93: Restore IP Addresses

- **Solution:** [`solutions/lc0093_restore_ip_addresses.cpp`](../solutions/lc0093_restore_ip_addresses.cpp)
- **Day:** 23 (Tue)
- **Solved without help?** yes

## What the call does

`backtrack(idx, dot_cnts, s, cur)` records every valid IP address that starts
with `cur` (the parts placed so far, each followed by a dot) and splits the
rest of `s`, from `idx`, into the remaining parts.

**Returns** nothing. **Passes down** where the next part starts, how many dots
are placed, and `cur`, **by value**.

## Recursive case

```cpp
for (int i = 1; i <= 3 && idx + i < s.length(); ++i) {
    string segment = s.substr(idx, i);
    if (valid(segment)) backtrack(idx + i, dot_cnts + 1, s, cur + segment + ".");
}
```

The template again, with a new kind of choice: **how many digits** (1, 2 or 3)
the next part takes. A choice is valid only if that part is a legal number.
`idx + i < s.length()` keeps at least one digit for the parts still to come.

**No un-choose step.** `cur + segment + "."` builds a **new** string for the
child, so this call's `cur` is never changed and there's nothing to undo.
That's the trade-off from LC 17 again: copying strings costs a little time,
but the shared-state bookkeeping disappears. With at most 12 digits it costs
nothing worth measuring.

## Base case

```cpp
if (dot_cnts == 3) {
    string segment = s.substr(idx);
    if (valid(segment)) ans.push_back(cur + segment);
    return;
}
```

After three dots, everything left **must** be the fourth part, so there's no
choice to make: check it and record. Doing the last part here, instead of
recursing a fourth time, is what guarantees exactly four parts and no digits
left over.

## What makes a part valid

```cpp
if (cur.empty() || cur.length() > 3) return false;
if (cur.length() > 1 && cur[0] == '0') return false;   // "01", "00": leading zero
return stoi(cur) <= 255;
```

The length check comes first, which also keeps `stoi` safe: the base case can
hand over a long tail like `"2552552"`, and `stoi` on at most 3 digits can't
overflow.

## Pruning

- `restoreIpAddresses` returns at once unless the length is 4 to 12: fewer
  than 4 digits can't fill four parts, and more than 12 can't fit in them.
- Not done: checking that the **remaining** digits fit the **remaining**
  parts (between 1 and 3 each). With ≤ 12 digits the tree is tiny anyway:
  at most 3 × 3 × 3 = 27 ways to place the dots before the last part.

## Complexity

**O(1)** for practical purposes: the input is at most 12 digits, so at most
27 dot placements are tried.

## Small notes on the code

- `valid(string cur)` and `backtrack(…, string s, string cur)` take strings
  by value; `const string&` would avoid copies, but the sizes are tiny.
- `idx + i < s.length()` compares `int` with an unsigned size (`-Wall`).
- `ans` is a member that's never cleared.

## Tested

LeetCode's three examples, `"1111"`, `"010010"` (leading zeros allowed only
as a lone `0`), `"255255255255"`, `"256256256256"` (nothing valid), too short
and too long inputs, `"1"` and `""`, plus 300 random digit strings of length
1–20: every result matches a brute force that tries all three-dot
placements.

## Key insight

Each level chooses how many digits the next part takes; after three dots the rest must be the last part.
