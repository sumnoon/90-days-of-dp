# LC 206: Reverse Linked List ⭐

- **Link:** https://leetcode.com/problems/reverse-linked-list/
- **Solution:** [`solutions/lc0206_reverse_linked_list.cpp`](../solutions/lc0206_reverse_linked_list.cpp)
- **Day:** 3 (Wed)
- **Solved without help?** yes
- **On the [redo list](../../../redo-list.md):** yes — flagged for re-practice, not
  because it failed but because the leap of faith is worth rebuilding from
  scratch rather than remembering.

The first problem where tracing is harder than trusting.

## What the call returns

`reverseList(head)` — a pointer to the **head of the reversed list**. That is
the original tail, and it's the same node at every level of the recursion.

## Recursive case

```cpp
ListNode* prev = reverseList(head->next);

head->next->next = head;   // the node after me points back at me
head->next = nullptr;      // I become the tail
return prev;               // the new head, passed up untouched
```

## Base case

```cpp
if (head == nullptr || head->next == nullptr) return head;
```

Two halves, two different jobs:

- `head == nullptr` — the empty list, and the guard that stops `head->next`
  from dereferencing null.
- `head->next == nullptr` — a single node, already reversed. **This is the
  half that produces `prev`.** Delete it and the recursion walks into
  `nullptr`, then crashes on `head->next->next`.

## Complexity

Time: O(n). Space: O(n) — all n frames are open at the deepest point. The
iterative three-pointer version is the O(1)-space answer, and is the usual
follow-up question.

## The leap of faith, precisely

Assume `reverseList(head->next)` **already works**. For `[1,2,3,4,5]` at the
frame for node 1, that means nodes 2–5 come back fully reversed:

```
prev = 5 -> 4 -> 3 -> 2 -> nullptr     (what the recursion returned)
head = 1 -> 2                          (my own next was never touched)
```

The step that makes it click: **node 2 is now the tail of the reversed part,
and `head->next` still points straight at it.** The recursion rewired links
*among* nodes 2–5, but nobody changed node 1's `next`. So the node I need is
still one hop away, and exactly one link has to change:

```
head->next->next = head;   // node 2's next = node 1
head->next = nullptr;      // node 1 is the new tail
```

You never verify the assumption — you grant it, then do one honest step of
work with what it handed you.

## Why `return prev` is the same every time

`prev` is node 5. It's discovered once, at the deepest call, and then passed
up through all five returns without being read or modified. Each frame's job
is only to fix its own local link and forward that answer along.

## Walking it

Nothing is rewired on the way down — all five frames are pushed before a
single pointer changes. Then, on the way back up:

| frame | `prev` | link flipped | node set to tail |
|---|---|---|---|
| node 4 | 5 | 5 → 4 | 4 |
| node 3 | 5 | 4 → 3 | 3 |
| node 2 | 5 | 3 → 2 | 2 |
| node 1 | 5 | 2 → 1 | 1 |

Four frames, four flipped links, one per frame.

## Key insight

Same shape as [printing 1..N](print_1_to_n.md) by recursing first and doing
the work on the way back up. That post-order shape is also every tree DP and
every DP recurrence: solve the smaller thing, *then* combine.

## See it

- **Interactive step-through** (private link, opens for the repo owner only):
  https://claude.ai/artifact/UxDwXqDRvicrjWT7xfSmLv — 28 steps, live pointer
  diagram, call stack and code line.
- **In the debugger:** breakpoint on `head->next->next = head;`, run with
  **F5**, Continue four times. `head->val` arrives as 4, 3, 2, 1 — innermost
  first.
