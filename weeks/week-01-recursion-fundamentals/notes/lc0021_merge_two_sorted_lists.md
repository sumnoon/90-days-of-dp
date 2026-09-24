# LC 21: Merge Two Sorted Lists

- **Link:** https://leetcode.com/problems/merge-two-sorted-lists/
- **Solution:** [`solutions/lc0021_merge_two_sorted_lists.cpp`](../solutions/lc0021_merge_two_sorted_lists.cpp)
- **Day:** 4 (Thu)
- **Solved without help?** yes

The first problem with **two** inputs shrinking independently. The leap of
faith still works — it just has two ways to take a step.

## What the call returns

`func(list1, list2)` — the head of a single sorted list containing every node
from both inputs. Nodes are **spliced, not copied**: no `new` anywhere.

## Recursive case

```cpp
if (list1->val <= list2->val) {
    list1->next = func(list1->next, list2);
    return list1;
} else {
    list2->next = func(list1, list2->next);
    return list2;
}
```

Whichever head is smaller is the head of the answer — nothing else can come
before it, since both lists are already sorted. So: keep that node, and hand
the recursion *the rest of that list plus the whole of the other one*.

Only one list moves forward per call. That's what makes the problem shrink:
each call removes exactly one node from consideration.

## Base case

```cpp
if (list1 == nullptr) return list2;
if (list2 == nullptr) return list1;
```

When one list runs out, the other is already sorted and already linked — so
return it whole. No loop needed to append the remainder, which is the part
the iterative version has to write out by hand.

Both being null is covered: the first check returns `list2`, which is also
null, and an empty answer is correct.

## Complexity

Time: O(n + m) — one call per node consumed. Space: O(n + m) for the call
stack. The iterative version is O(1) space, which is the usual follow-up.

## Key insight

**`<=` instead of `<` keeps the merge stable.** On a tie, the node from
`list1` goes first, so equal elements keep their original relative order.
Nothing in LC 21 detects the difference — the values are identical, so the
output looks the same either way — but the same comparison inside merge sort
is what makes it a stable sort. Getting the habit right now costs nothing;
debugging it inside a sort later is miserable.

## Compared with LC 206

Both are the leap of faith, one step apart:

| | LC 206 | LC 21 |
|---|---|---|
| shrink by | following `head->next` | dropping the smaller head |
| work per frame | rewire one link, **after** the call | pick the smaller head, **before** the call |
| result travels | the same node up every frame (`prev`) | each frame returns its own node |

LC 206 does its work post-order, on the way back up. LC 21 does its work
**pre-order**: it decides the answer's head, then delegates. Same method,
opposite half of the call — exactly the contrast from
[printing 1..N vs N..1](print_1_to_n.md).

## Why this is the last stop before DP

`func(i, j)` over two sequences, choosing how to advance, is the exact shape
of **Week 8 string DP**: LCS and edit distance are `dp[i][j]` over two
prefixes, where each transition decides which input to consume. The only
difference there is that both branches get explored and the best one is kept,
instead of the comparison telling you which single branch to take.

## Tested

| list1 | list2 | merged |
|---|---|---|
| `[1,2,4]` | `[1,3,4]` | `[1,1,2,3,4,4]` |
| `[]` | `[]` | `[]` |
| `[]` | `[0]` | `[0]` |
| `[5]` | `[1,2]` | `[1,2,5]` |
| `[1,1,1]` | `[1,1]` | `[1,1,1,1,1]` |

The first three are LeetCode's own examples.

## Note on the file

The harness reads each list as a count then that many values
(`3 1 2 4  3 1 3 4`). Freeing the merged list once frees everything, because
the merge splices the original nodes rather than allocating new ones.
