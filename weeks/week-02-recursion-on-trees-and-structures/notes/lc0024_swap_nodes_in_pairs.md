# LC 24: Swap Nodes in Pairs

- **Solution:** [`solutions/lc0024_swap_nodes_in_pairs.cpp`](../solutions/lc0024_swap_nodes_in_pairs.cpp)
- **Day:** 12 (Fri)
- **Solved without help?** yes

## What the call returns

`func(head)` swaps every adjacent pair in the list starting at `head` and
returns the **new head**: the old second node, or `head` itself if there's no
pair to swap.

**Returns** the new head of the swapped list. **Passes down** nothing but the
pointer to where the rest starts.

## Recursive case

```cpp
ListNode* firstNode = head;
ListNode* secondNode = head->next;

firstNode->next = func(secondNode->next);
secondNode->next = firstNode;

return secondNode;
```

Leap of faith, exactly as in LC 206: trust `func(secondNode->next)` to swap
everything after this pair and hand back its new head. Then only this pair
needs fixing: the first node now points at the swapped rest, the second node
points at the first, and the second node is this part's new head.

**The order of the two assignments matters.** `secondNode->next` is the only
pointer to the rest of the list, so it is read (inside the recursive call)
before it is overwritten. Swap the two lines and `func` would be called on
`firstNode` instead of the rest, recursing forever.

## Base case

```cpp
if (head == nullptr || head->next == nullptr) return head;
```

No nodes, or one node left over: there is no pair, so the list is already
"swapped". This also covers odd lengths: `[1, 2, 3]` → `[2, 1, 3]`.

## Complexity

Time: **O(n)**.
Space: **O(n / 2)** stack: one frame per pair.

## Compared with LC 206

| | LC 206 Reverse | LC 24 Swap pairs |
|---|---|---|
| Recurses on | `head->next` (1 node on) | `head->next->next` (2 nodes on) |
| Fixes per frame | one link flipped (plus `head->next = nullptr`) | two links: first → swapped rest, second → first; the caller links in the returned second node |
| Returns | the same new head, all the way up | a new head per pair |

## Tested

LeetCode's four examples (including the empty list and an odd length), two
nodes, seven nodes, and a check that the **nodes** move rather than their
values, which LeetCode doesn't allow.

## See it

- **Swap a pair, trust the rest:** https://sumnoon.github.io/90-days-of-dp/lc24/ —
  watch the frames pile up without touching a pointer, then each one rewire
  its pair on the way back; at the end the nodes slide into their new order.
  Try the odd list. ([source](../../../docs/lc24/index.html))

## Key insight

Trust the call to swap everything after this pair; then rewire the pair and return its second node.
