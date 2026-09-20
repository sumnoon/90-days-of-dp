# From Recursion to DP Mastery: A 12-Week Training Plan

**Goal:** Start with basic recursion and finish able to spot, define, and solve most dynamic programming problems seen in interviews and mid-level contests.

**Time needed:** About 12–14 hours a week, planned around a Monday–Friday job:

| Days | Time | What goes there |
|---|---|---|
| Mon–Fri (workdays) | 1–1.5 h each evening | 1–2 easier or medium problems |
| Saturday | 3–4 h | The hardest problems of the week plus the main videos and reading |
| Sunday | 2–3 h | Re-solving old problems, the weekly checkpoint, and a short preview of next week |

---

## Core Resources (used throughout)

You don't need to finish all of these. Choose **one video series and one text resource** and use the rest as backup.

| Resource | Type | Best for |
|---|---|---|
| [Jeff Erickson, *Algorithms*](https://jeffe.cs.illinois.edu/teaching/algorithms/) (free book): Ch 1 Recursion, Ch 2 Backtracking, Ch 3 Dynamic Programming | Book | The best written explanation of how recursion leads to DP |
| [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf) (free PDF): Ch 5 Complete Search, Ch 7 Dynamic Programming | Book | Short, clear, and aimed at contest-style problems |
| [MIT 6.006 Spring 2020](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/): the DP lectures (the "SRTBOT" framework) | Video lectures | A rigorous way to design DP solutions |
| freeCodeCamp: *Dynamic Programming – Learn to Solve Algorithmic Problems* (Alvin Zablan, YouTube) | Video | Beginner-friendly, moves step by step from memoization to tabulation |
| Striver / takeUforward: Recursion playlist and DP series ([takeuforward.org](https://takeuforward.org)) | Video + notes | A structured problem-by-problem walkthrough that matches this plan closely |
| Aditya Verma: Recursion and DP playlists (YouTube) | Video | Excellent on knapsack, LCS, and matrix-chain families |
| [USACO Guide](https://usaco.guide) (Gold/Platinum DP modules) | Text + problems | Knapsack, trees, bitmask, range, and digit DP |
| [CP-Algorithms](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html) | Text | Reference articles for advanced topics |
| [CSES Problem Set](https://cses.fi/problemset/), DP section | Practice | Clean, classic DP problems |
| [AtCoder Educational DP Contest](https://atcoder.jp/contests/dp) (A–Z) | Practice | 26 problems that cover nearly every DP pattern |
| [NeetCode Roadmap](https://neetcode.io/roadmap) | Practice + video solutions | Short video explanations for LeetCode problems |
| [Python Tutor](https://pythontutor.com) | Tool | Watch the call stack step by step |

> **Tip:** When a video series covers the same problem you are working on, watch it **only after** you have spent at least 30 minutes on the problem yourself.

---

## Your Calendar (starting Sunday, Sep 20, 2026)

| Week | Dates | Topic |
|---|---|---|
| 0 | **Sun Sep 20 (today)** | Kickoff day (see below) |
| 1 | Sep 21 – Sep 27 | Recursion Fundamentals |
| 2 | Sep 28 – Oct 4 | Recursion on Trees and Structures |
| 3 | Oct 5 – Oct 11 | Backtracking I (Subsets, Permutations, Combinations) |
| 4 | Oct 12 – Oct 18 | Backtracking II and Divide & Conquer |
| 5 | Oct 19 – Oct 25 | From Memoization to DP |
| 6 | Oct 26 – Nov 1 | 1D DP (Sequences and Decisions) |
| 7 | Nov 2 – Nov 8 | 2D Grid DP |
| 8 | Nov 9 – Nov 15 | String DP (Two Sequences) |
| 9 | Nov 16 – Nov 22 | The Knapsack Family |
| 10 | Nov 23 – Nov 29 | Interval DP |
| 11 | Nov 30 – Dec 6 | Tree DP and State Machine DP |
| 12 | Dec 7 – Dec 13 | Bitmask DP, Digit DP, and Final Review |
| Test | Dec 14 – 20 | Mastery test and the optional bonus weekend |

**Month milestones:** Month 1 checkpoint on **Sun Oct 18**, Month 2 on **Sun Nov 15**, and Month 3 (the Week 12 mock) on **Sun Dec 13**.

### Day 0: Today, Sunday Sep 20 (2–3 h)

1. **Setup (30 min):** Create or log in to your LeetCode, CSES, and AtCoder accounts. Start a notebook (paper or a doc) and, if you like, a GitHub repo for your solutions. Make a "redo list".
2. **First reading (60 min):** Read Jeff Erickson's *Algorithms*, Ch 1, sections 1.1–1.3, or watch the first 3 videos of Striver's recursion playlist.
3. **First code (45 min):** Write factorial and sum of digits recursively, then step through both in [Python Tutor](https://pythontutor.com) and watch the call stack.
4. **Preview (15 min):** Skim the Week 1 section below.

Because today covers Week 1's reading, Week 1's weekdays are shifted one step earlier (see its study guide).

---

## How to Use This Plan

**Weekday routine (60–90 min, after work)**

1. **Warm-up (10 min):** Reread yesterday's notebook entry.
2. **Solve (40–60 min):** Work on the day's problem or problems. Give each one 30–40 minutes before you look at a hint.
3. **Reflect (10 min):** Write down the **state**, the **transition**, the **base case**, and the one idea that unlocked the problem.

**Saturday routine (3–4 h, deep work)**

1. **Concept (45–60 min):** Watch or read the week's main resources.
2. **Hard problems (2–2.5 h):** Work on the week's hardest ⭐ problems. Take a short break between problems.
3. **Reflect (15 min):** Update your notes and your redo list.

**Sunday routine (2–3 h, review)**

1. **Redo (60 min):** Re-solve 3 problems from memory: the week's hardest one plus 2 from your redo list.
2. **Checkpoint (30–45 min):** Do the weekly checkpoint. If you don't pass it, move one problem from this week into next Saturday.
3. **Preview (30 min):** Watch or read the intro to next week's topic so Monday starts smoothly.

> **On a busy workday:** Skip it and move that problem to Saturday. Never skip Sunday review, since that's where the learning sticks.

**When you're stuck**

1. After 15 minutes: draw the recursion tree for a small input by hand.
2. After 30 minutes: read only the *hint* or the *state definition* in a solution, then close it and keep going on your own.
3. After 45 minutes: read the full solution, then code it from memory the **next day**.
4. Add every problem you needed help with to a "redo list" and re-solve it on Sunday.

**The DP framework you'll use from Week 5 onward**

1. Write the brute-force recursion first.
2. Find the parameters that change between calls. Those become your **state**.
3. Add memoization. This is **top-down DP**.
4. Turn it into a table. This is **bottom-up DP**.
5. Reduce space when a row or column depends only on the one before it.

---

# Month 1: Recursion and Backtracking

Every DP solution is a recursion with its repeated work cached. This month builds that recursive thinking.

## Week 1: Recursion Fundamentals (Sep 21 – Sep 27)

**Concepts:** base case vs. recursive case, the call stack, the "leap of faith" (trust the function to solve smaller inputs), drawing recursion trees, and time/space complexity of recursive calls.

### Resources

- 📖 Jeff Erickson, *Algorithms*, Ch 1 (Recursion): read sections 1.1–1.3, on reductions, simplify-and-delegate, and Tower of Hanoi.
- 🎥 Striver's Recursion playlist: the first 5–6 videos, on basics, parameterized vs. functional recursion, and multiple recursive calls.
- 🛠 [Python Tutor](https://pythontutor.com): step through recursive factorial and Fibonacci and watch the stack grow and shrink.
- 📝 LeetCode Explore card: *Recursion I*.

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | Print 1..N and N..1 recursively. Write a recursive palindrome check. Solve LC 344. |
| Tue | 1–1.5 h | LC 509. Draw the recursion tree for n=5 and count how many times fib(2) is called. |
| Wed | 1–1.5 h | LC 231, then LC 206 (solve it recursively). |
| Thu | 1–1.5 h | LC 21 (recursive merge). |
| Fri | 1–1.5 h | LC 50 Pow(x, n). Work out why halving the exponent gives O(log n). |
| **Sat** (weekend) | 3–4 h | Watch the rest of Striver's recursion basics. Solve Tower of Hanoi from scratch and write its recurrence. Re-solve LC 206 without notes. Use any leftover time to catch up on missed weekdays. |
| **Sun** (weekend) | 2–3 h | Redo 3 problems from memory, then do the **checkpoint**. Preview Week 2 with Striver's tree traversal videos (30 min). |

**Key ideas**

- Every recursive function answers one question: *"If I already had the answer for a smaller input, how would I build the answer for this input?"*
- A function's cost is roughly (number of calls) × (work done per call). The recursion tree shows you both.

**Common mistakes**

- A missing or wrong base case causes infinite recursion or a stack overflow.
- Trying to trace every call in your head. Trust the recursion for smaller inputs and check only one level.

| Problem | Notes |
|---|---|
| ⭐ LC 509 Fibonacci Number | Draw the recursion tree and count the repeated calls |
| ⭐ LC 50 Pow(x, n) | Fast exponentiation, O(log n) |
| LC 344 Reverse String (solve it recursively) | Two-pointer recursion |
| ⭐ LC 206 Reverse Linked List (solve it recursively) | Trust the recursion |
| LC 21 Merge Two Sorted Lists | Recursive merge |
| LC 231 Power of Two | Warm-up |

**Checkpoint:** Solve Tower of Hanoi from scratch and explain why it takes 2ⁿ − 1 moves.

---

## Week 2: Recursion on Trees and Structures (Sep 28 – Oct 4)

**Concepts:** tree traversals, returning values up the tree vs. passing state down, helper functions with extra parameters.

### Resources

- 🎥 Striver's Tree series: the traversal videos and the "height / diameter / max path sum" videos.
- 🎥 NeetCode video solutions for LC 543 and LC 236.
- 📝 LeetCode Explore card: *Binary Tree*, the section on solving problems recursively ("top-down" vs. "bottom-up").

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | Write preorder, inorder, and postorder traversals recursively. Solve LC 104. |
| Tue | 1–1.5 h | LC 226 and LC 100. |
| Wed | 1–1.5 h | LC 112 (pass the remaining sum down). |
| Thu | 1–1.5 h | LC 98 (pass (low, high) bounds down). |
| Fri | 1–1.5 h | LC 24. |
| **Sat** (weekend) | 3–4 h | Harder problems: LC 543 (return height, update a global answer) and LC 236 (what does each subtree report back?). Watch the NeetCode solutions after you attempt them. |
| **Sun** (weekend) | 2–3 h | Re-solve LC 543 from memory, then do the **checkpoint**. Preview Week 3 by reading the start of Erickson Ch 2. |

**Key ideas**

- **Top-down:** pass information down as parameters, as with remaining sum or bounds.
- **Bottom-up:** return information up from children, as with height or whether a node was found.
- The pattern "return one thing, but update the answer with something else" is the basis of **tree DP** in Week 11.

**Common mistakes**

- Mixing up what the function *returns* with what the *final answer* is. In LC 543 these are two different values.

| Problem | Notes |
|---|---|
| ⭐ LC 104 Maximum Depth of Binary Tree | Return values upward |
| ⭐ LC 226 Invert Binary Tree | |
| LC 100 Same Tree | |
| LC 112 Path Sum | Pass state downward |
| ⭐ LC 543 Diameter of Binary Tree | Return height, update a global answer |
| ⭐ LC 236 Lowest Common Ancestor of a Binary Tree | |
| LC 98 Validate Binary Search Tree | Pass bounds down |
| LC 24 Swap Nodes in Pairs | |

**Checkpoint:** For every problem, explain in one sentence what the function returns and what it passes down.

---

## Week 3: Backtracking I (Subsets, Permutations, Combinations) (Oct 5 – Oct 11)

**Concepts:** the choose / explore / un-choose template, the include-or-exclude decision tree, handling duplicates by sorting and skipping.

```text
backtrack(state):
    if goal reached: record the answer; return
    for each choice:
        if the choice is valid:
            make the choice
            backtrack(next state)
            undo the choice
```

### Resources

- 📖 Jeff Erickson, *Algorithms*, Ch 2 (Backtracking): sections 2.1–2.3.
- 🎥 Striver's Recursion playlist: the subsequences, combination sum, subsets I/II, and permutations videos.
- 📝 LeetCode Discuss post by *issac3*: "A general approach to backtracking questions (Subsets, Permutations, Combination Sum, Palindrome Partitioning)". Search the title on LeetCode.

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | Memorize the backtracking template. Solve LC 78 using include/exclude. |
| Tue | 1–1.5 h | LC 78 again with a for-loop from a start index, then LC 77. |
| Wed | 1–1.5 h | LC 17. |
| Thu | 1–1.5 h | LC 46 using a `used[]` array. |
| Fri | 1–1.5 h | LC 39 (the same element can be reused, so recurse with `i`, not `i+1`). |
| **Sat** (weekend) | 3–4 h | The duplicate-handling problems: LC 90, LC 47, LC 40. Then LC 22 (prune with open/close counts). Read the issac3 backtracking post. |
| **Sun** (weekend) | 2–3 h | Redo list, then do the **checkpoint**. Preview Week 4 by reading the N-Queens section of Erickson Ch 2. |

**Key ideas**

- Subsets means include or exclude each item, giving 2ⁿ options. **This is the recursion behind 0/1 knapsack.**
- Combination Sum reuses items. **This is the recursion behind unbounded knapsack.**
- Draw the decision tree before you code. Each level is one decision.

**Common mistakes**

- Forgetting to undo the choice, as with a missing `path.pop()`.
- Adding `path` itself to the results instead of a **copy** of it.
- Skipping duplicates at the wrong level, which also removes valid answers.

| Problem | Notes |
|---|---|
| ⭐ LC 78 Subsets | Include or exclude |
| ⭐ LC 90 Subsets II | Skip duplicates |
| ⭐ LC 46 Permutations | |
| LC 47 Permutations II | |
| ⭐ LC 77 Combinations | |
| ⭐ LC 39 Combination Sum | Reuse elements |
| LC 40 Combination Sum II | |
| LC 17 Letter Combinations of a Phone Number | |
| ⭐ LC 22 Generate Parentheses | Pruning with constraints |

**Checkpoint:** Write the template from memory and solve Subsets and Permutations in under 10 minutes each.

---

## Week 4: Backtracking II and Divide & Conquer (Oct 12 – Oct 18)

**Concepts:** pruning, backtracking on grids, divide & conquer (merge sort, splitting at every point).

### Resources

- 📖 Jeff Erickson, *Algorithms*, Ch 2 (N-Queens, Subset Sum) and Ch 1 (Mergesort section).
- 📖 Competitive Programmer's Handbook, Ch 5 (Complete Search: backtracking and pruning).
- 🎥 Striver: the N-Queens, Sudoku Solver, Palindrome Partitioning, and Word Search videos.
- 🎥 NeetCode: LC 241 explanation.

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | LC 79 (mark visited cells in place and restore them). |
| Tue | 1–1.5 h | LC 93. |
| Wed | 1–1.5 h | LC 912 with merge sort. Write the recurrence T(n) = 2T(n/2) + n. |
| Thu | 1–1.5 h | LC 131 (try every split point). |
| Fri | 1–1.5 h | LC 241 using plain recursion only. Note which substrings get solved more than once. |
| **Sat** (weekend) | 3–4 h | The hard ones: LC 51 (sets for columns and both diagonals), LC 37, and LC 95. |
| **Sun** (weekend) | 2–3 h | **Month 1 checkpoint:** add a cache to LC 241. Clear the redo list. Preview Week 5 with the first hour of the freeCodeCamp DP video. |

**Key ideas**

- Pruning early, for example rejecting a queen placement immediately, turns impossible searches into fast ones.
- When a divide & conquer solution solves the **same subproblem more than once**, it needs DP. LC 241 is where you first see this.

**Common mistakes**

- On grids, forgetting to restore a visited cell after returning.

| Problem | Notes |
|---|---|
| ⭐ LC 79 Word Search | Grid backtracking |
| ⭐ LC 51 N-Queens | |
| LC 37 Sudoku Solver | |
| ⭐ LC 131 Palindrome Partitioning | Try every split point |
| LC 93 Restore IP Addresses | |
| ⭐ LC 912 Sort an Array (write merge sort) | Divide & conquer |
| ⭐ LC 241 Different Ways to Add Parentheses | First look at overlapping subproblems |
| LC 95 Unique Binary Search Trees II | |

**Month 1 checkpoint:** Solve LC 241 with plain recursion, then add a hashmap cache. You've just written your first DP.

---

# Month 2: Core Dynamic Programming

## Week 5: From Memoization to DP (Oct 19 – Oct 25)

**Concepts:** overlapping subproblems, optimal substructure, top-down vs. bottom-up, and the 5-step framework.

### Resources

- 🎥 freeCodeCamp: *Dynamic Programming – Learn to Solve Algorithmic Problems* (Alvin Zablan). Watch the memoization half this week.
- 🎥 MIT 6.006 Spring 2020, the first DP lecture (SRTBOT: Subproblems, Relate, Topological order, Base, Original, Time).
- 📖 Jeff Erickson, *Algorithms*, Ch 3.1–3.4.
- 🎥 Striver DP series, lectures 1–6 (1D DP: climbing stairs, frog jump, house robber).
- 📖 [CP-Algorithms: Introduction to DP](https://cp-algorithms.com/dynamic_programming/intro-to-dp.html).
- 🏋 AtCoder DP Contest problems A (Frog 1), B (Frog 2), and C (Vacation).

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | LC 509 three ways (recursion, memoized, table). Time each one for n=40. |
| Tue | 1–1.5 h | LC 70. |
| Wed | 1–1.5 h | LC 746. |
| Thu | 1–1.5 h | LC 198 in four versions: recursion, memoized, table, O(1) space. |
| Fri | 1–1.5 h | LC 1137 and LC 740 (turns into House Robber). |
| **Sat** (weekend) | 3–4 h | Watch the MIT 6.006 SRTBOT lecture. Solve LC 213 and LC 96, then AtCoder A, B, and C. |
| **Sun** (weekend) | 2–3 h | Do the **checkpoint** and CSES Dice Combinations. Preview Week 6 with the tabulation half of the freeCodeCamp video. |

**Key ideas**

- **Rule for this week:** solve every problem three ways. Never write a table before you have written the recursion.
- Top-down DP is plain recursion plus a cache. Bottom-up DP is the same recursion, filled in dependency order.

**Common mistakes**

- Defining the state vaguely. Write it in words, such as "dp[i] = max money robbing houses 0..i".
- Using a mutable default argument or a global cache that isn't reset between test cases.

| Problem | Notes |
|---|---|
| ⭐ LC 70 Climbing Stairs | |
| ⭐ LC 746 Min Cost Climbing Stairs | |
| ⭐ LC 198 House Robber | Take or skip |
| ⭐ LC 213 House Robber II | Circular array, so run it twice |
| LC 740 Delete and Earn | Turns into House Robber |
| LC 1137 N-th Tribonacci Number | |
| LC 96 Unique Binary Search Trees | |
| CSES: Dice Combinations | |

**Checkpoint:** Write all 4 versions of House Robber from memory.

---

## Week 6: 1D DP (Sequences and Decisions) (Oct 26 – Nov 1)

**Concepts:** "dp[i] = best answer ending at i" vs. "best answer using the first i items", and the LIS pattern.

### Resources

- 🎥 freeCodeCamp DP video: the tabulation half (canSum / howSum / bestSum are the same idea as Coin Change).
- 📖 [USACO Guide](https://usaco.guide): Gold → *Longest Increasing Subsequence* module (covers the O(n log n) method).
- 🎥 Striver DP series: the LIS lectures (near the end of the series).
- 🎥 NeetCode: LC 322, LC 139, LC 91.
- 🏋 CSES: Minimizing Coins, Coin Combinations I, Removing Digits.

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | LC 53. Rewrite Kadane's algorithm as dp[i] = max(nums[i], dp[i−1] + nums[i]). |
| Tue | 1–1.5 h | LC 152 (track both max and min). |
| Wed | 1–1.5 h | LC 322. Write the recursion first, then the table. |
| Thu | 1–1.5 h | LC 139. |
| Fri | 1–1.5 h | LC 91. |
| **Sat** (weekend) | 3–4 h | LIS day: read the USACO Guide LIS module. Solve LC 300 in O(n²) and then O(n log n). Then LC 673 and LC 1048. |
| **Sun** (weekend) | 2–3 h | Do the **checkpoint**. Solve LC 983 and CSES Minimizing Coins. LC 354 is an optional stretch. |

**Key ideas**

- Ask whether your dp[i] means **"ends exactly at i"** or **"using the first i items"**. The two lead to different transitions and different final answers.
- For LIS "ending at i", the final answer is `max(dp)`, not `dp[n−1]`.

**Common mistakes**

- Initializing with the wrong value: use ∞ for a minimum, −∞ or 0 for a maximum, and 0 or 1 for counting.
- In LC 91, forgetting that '0' cannot be decoded on its own.

| Problem | Notes |
|---|---|
| ⭐ LC 53 Maximum Subarray | Kadane's algorithm is a DP |
| LC 152 Maximum Product Subarray | Track both max and min |
| ⭐ LC 322 Coin Change | |
| ⭐ LC 139 Word Break | |
| ⭐ LC 91 Decode Ways | |
| ⭐ LC 300 Longest Increasing Subsequence | O(n²), then O(n log n) |
| LC 673 Number of Longest Increasing Subsequence | |
| LC 1048 Longest String Chain | |
| LC 983 Minimum Cost For Tickets | |
| LC 354 Russian Doll Envelopes (stretch) | 2D sort + LIS |

**Checkpoint:** For each problem, write the state definition in one sentence before you write any code.

---

## Week 7: 2D Grid DP (Nov 2 – Nov 8)

**Concepts:** dp[r][c] over a grid, fill order, rolling arrays for space optimization, and filling the table backward when the answer depends on future cells.

### Resources

- 🎥 Striver DP series: the grid lectures (unique paths, obstacles, min path sum, triangle, falling path sum, and cherry pickup).
- 📖 [USACO Guide](https://usaco.guide): Gold → *Paths on Grids* module.
- 🏋 CSES: Grid Paths. AtCoder DP Contest problem H (Grid 1).

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | LC 62 with recursion, then a table, then a 1D array. |
| Tue | 1–1.5 h | LC 63. |
| Wed | 1–1.5 h | LC 64. |
| Thu | 1–1.5 h | LC 120 (bottom-up from the last row). |
| Fri | 1–1.5 h | LC 931. |
| **Sat** (weekend) | 3–4 h | Watch Striver's grid DP lectures. Solve LC 221, LC 174 (work out why it must be filled backward), and LC 329 (memoized DFS). |
| **Sun** (weekend) | 2–3 h | **Checkpoint:** reduce LC 64 to O(n) space. Solve CSES Grid Paths and AtCoder H. Preview Week 8 with the first Aditya Verma LCS video. |

**Key ideas**

- The fill order must make sure each cell's dependencies are already computed.
- If row r depends only on row r−1, you only need two rows, or even one.
- Some problems (LC 174) only work when you define the state as "what I need from here to the end".

**Common mistakes**

- Off-by-one errors on the first row and column. Handle them explicitly or pad the table.

| Problem | Notes |
|---|---|
| ⭐ LC 62 Unique Paths | |
| ⭐ LC 63 Unique Paths II | |
| ⭐ LC 64 Minimum Path Sum | |
| LC 120 Triangle | Bottom-up is cleaner |
| LC 931 Minimum Falling Path Sum | |
| ⭐ LC 221 Maximal Square | |
| ⭐ LC 174 Dungeon Game | Fill backward |
| LC 329 Longest Increasing Path in a Matrix | Memoized DFS on a DAG |
| CSES: Grid Paths | |

**Checkpoint:** Reduce LC 64 from O(m·n) space to O(n).

---

## Week 8: String DP (Two Sequences) (Nov 9 – Nov 15)

**Concepts:** dp[i][j] over prefixes of two strings, and the match/mismatch transition. This family appears in interviews very often.

### Resources

- 📖 Jeff Erickson, *Algorithms*, Ch 3: the *Edit Distance* section.
- 🎥 Aditya Verma DP playlist: the LCS section (about 15 videos building variants from LCS).
- 🎥 Striver DP series: the DP-on-strings lectures (LCS through wildcard matching).
- 🎥 MIT 6.006 Spring 2020: the DP lecture on subsequence problems (LCS, LIS).
- 🏋 AtCoder DP Contest problem F (LCS). CSES Edit Distance.

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | LC 1143 with recursion, then memoization. |
| Tue | 1–1.5 h | LC 1143 as a table. Then reconstruct the LCS string itself. |
| Wed | 1–1.5 h | LC 583 (LCS in disguise). |
| Thu | 1–1.5 h | LC 712. |
| Fri | 1–1.5 h | LC 5. |
| **Sat** (weekend) | 3–4 h | LC 72 (draw the table for "horse" → "ros" by hand), LC 516, LC 1312, and LC 115. |
| **Sun** (weekend) | 2–3 h | **Month 2 checkpoint** (Edit Distance cold in under 20 min). Solve LC 44 and AtCoder F. LC 10 is a stretch. Preview Week 9 with the first Aditya Verma knapsack videos. |

**Key ideas**

- The state is almost always dp[i][j] = the answer for s1[0..i) and s2[0..j).
- The transition asks: *do the characters match?* If they do, move diagonally. If not, take the best of the neighboring cells.
- A lot of "palindrome" problems are really LCS problems.

**Common mistakes**

- Mixing up 0-indexed strings with a 1-indexed table. Pad with an empty-string row and column.
- Confusing subsequence (can skip characters) with substring (must be contiguous).

| Problem | Notes |
|---|---|
| ⭐ LC 1143 Longest Common Subsequence | The core pattern |
| ⭐ LC 72 Edit Distance | Insert / delete / replace |
| LC 583 Delete Operation for Two Strings | LCS in disguise |
| LC 712 Minimum ASCII Delete Sum for Two Strings | |
| ⭐ LC 516 Longest Palindromic Subsequence | |
| ⭐ LC 5 Longest Palindromic Substring | |
| LC 1312 Minimum Insertion Steps to Make a String Palindrome | |
| ⭐ LC 115 Distinct Subsequences | |
| LC 44 Wildcard Matching | |
| LC 10 Regular Expression Matching (stretch) | |

**Month 2 checkpoint:** Solve Edit Distance cold in under 20 minutes and explain each of the three transitions.

---

# Month 3: Advanced DP Patterns

## Week 9: The Knapsack Family (Nov 16 – Nov 22)

**Concepts:** 0/1 knapsack (loop capacity **backward**), unbounded knapsack (loop capacity **forward**), counting vs. optimizing, and combinations vs. permutations (which loop goes on the outside).

### Resources

- 🎥 Aditya Verma DP playlist: the 0/1 knapsack and unbounded knapsack sections. This is the most-recommended knapsack series.
- 📖 [USACO Guide](https://usaco.guide): Gold → *Knapsack DP* module.
- 📖 [CP-Algorithms: Knapsack Problem](https://cp-algorithms.com/dynamic_programming/knapsack.html).
- 🎥 Striver DP series: the DP-on-subsequences lectures (subset sum through coin change II).
- 🏋 AtCoder DP Contest problems D (Knapsack 1) and E (Knapsack 2). CSES Book Shop and Money Sums.

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | 0/1 knapsack with recursion, then a 2D table. |
| Tue | 1–1.5 h | Rewrite it as a 1D array looping backward. Solve AtCoder D. |
| Wed | 1–1.5 h | LC 416. |
| Thu | 1–1.5 h | LC 518 (unbounded knapsack, loop forward). |
| Fri | 1–1.5 h | LC 279. |
| **Sat** (weekend) | 3–4 h | LC 494 (turn it into a subset-sum count), LC 474, LC 1049, and LC 377. Compare LC 377's loop order with LC 518. |
| **Sun** (weekend) | 2–3 h | Do the **checkpoint**. Solve CSES Book Shop and Money Sums. AtCoder E is a stretch. Preview Week 10 with the Aditya Verma MCM intro. |

**Key ideas**

- 0/1 knapsack: loop capacity **backward** so each item is used at most once.
- Unbounded knapsack: loop capacity **forward** so an item can be reused.
- Items in the outer loop count **combinations**. Capacity in the outer loop counts **permutations**.
- When the capacity is huge but the values are small, index the table by value instead (AtCoder E).

**Common mistakes**

- Looping capacity forward in 0/1 knapsack, which lets an item be used more than once.
- For LC 494, not checking that (sum + target) is even and non-negative.

| Problem | Notes |
|---|---|
| Classic 0/1 knapsack | Implement it from scratch |
| ⭐ LC 416 Partition Equal Subset Sum | 0/1, true/false |
| ⭐ LC 494 Target Sum | Turn it into a subset-sum count |
| LC 1049 Last Stone Weight II | |
| ⭐ LC 474 Ones and Zeroes | Two capacities |
| ⭐ LC 518 Coin Change II | Unbounded, counting combinations |
| LC 377 Combination Sum IV | Unbounded, counting permutations |
| LC 279 Perfect Squares | |
| CSES: Book Shop, Money Sums | |

**Checkpoint:** Explain why swapping the two loops turns LC 518 into LC 377.

---

## Week 10: Interval DP (Nov 23 – Nov 29)

**Concepts:** dp[i][j] over a subarray, trying every split point k, iterating by **length** (short intervals first), and the "last action" trick.

### Resources

- 🎥 Aditya Verma DP playlist: the Matrix Chain Multiplication section (MCM and its variants).
- 🎥 Striver DP series: the partition DP lectures (MCM, cutting a stick, burst balloons, palindrome partitioning II).
- 📖 [USACO Guide](https://usaco.guide): Platinum → *Range DP* module.
- 🏋 AtCoder DP Contest problems L (Deque) and N (Slimes).

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | Matrix Chain Multiplication with recursion, then memoization. |
| Tue | 1–1.5 h | MCM as a table, filled by interval length. |
| Wed | 1–1.5 h | LC 1039. |
| Thu | 1–1.5 h | Game DP: LC 877 and LC 486. |
| Fri | 1–1.5 h | LC 1547. |
| **Sat** (weekend) | 3–4 h | LC 312 (choose the last balloon to burst), LC 132 (precompute a palindrome table), and AtCoder L. |
| **Sun** (weekend) | 2–3 h | Do the **checkpoint**. Solve LC 375. AtCoder N and LC 1000 are stretches. Preview Week 11 with the USACO *DP on Trees* module. |

**Key ideas**

- Template: `dp[i][j] = best over k in [i, j) of dp[i][k] + dp[k+1][j] + cost(i, k, j)`.
- Always iterate by interval length, from short to long.
- When choosing the *first* action splits the problem badly, try choosing the **last** action instead.
- Game DP: dp[i][j] = (my score − opponent's score) when it's my turn to play on range [i, j].

**Common mistakes**

- Filling the table row by row instead of by length, which reads cells that haven't been computed yet.

| Problem | Notes |
|---|---|
| Matrix Chain Multiplication (classic) | The template |
| ⭐ LC 312 Burst Balloons | Choose the last balloon |
| ⭐ LC 1039 Minimum Score Triangulation of Polygon | |
| ⭐ LC 132 Palindrome Partitioning II | |
| LC 375 Guess Number Higher or Lower II | Minimax |
| LC 1547 Minimum Cost to Cut a Stick | |
| LC 486 Predict the Winner | Game DP |
| LC 877 Stone Game | |
| LC 1000 Minimum Cost to Merge Stones (stretch) | |

**Checkpoint:** Solve Burst Balloons and explain why choosing the *first* balloon to burst doesn't work.

---

## Week 11: Tree DP and State Machine DP (Nov 30 – Dec 6)

**Concepts:** returning a tuple of states from each subtree, and modeling a problem as a finite set of states with transitions between them.

### Resources

- 📖 [USACO Guide](https://usaco.guide): Gold → *DP on Trees* module.
- 📖 Competitive Programmer's Handbook: the tree algorithms chapter (sections on tree DP).
- 📝 LeetCode Discuss post by *fun4LeetCode*: "Most consistent ways of dealing with the series of stock problems". Search the title on LeetCode. This is the best write-up of the stock problems.
- 🎥 Striver DP series: the DP-on-stocks lectures.
- 🏋 AtCoder DP Contest problem P (Independent Set). CSES Tree Matching.

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | LC 337. Each node returns (rob, skip). |
| Tue | 1–1.5 h | LC 124. |
| Wed | 1–1.5 h | LC 1372. |
| Thu | 1–1.5 h | Read the fun4LeetCode stock post. Solve LC 121 and LC 122. |
| Fri | 1–1.5 h | LC 714. |
| **Sat** (weekend) | 3–4 h | LC 968 (three states per node). Then LC 309 (draw the state diagram first), LC 123, and LC 188. |
| **Sun** (weekend) | 2–3 h | Do the **checkpoint**. Solve AtCoder P and CSES Tree Matching. Preview Week 12 with the USACO *Bitmask DP* module. |

**Key ideas**

- **Tree DP:** decide what each subtree needs to report back to its parent. That tuple is the state.
- **State machine DP:** draw circles for the states and arrows for the actions. Each arrow becomes one line of the transition.
- All six stock problems are one template: `dp[day][transactions_left][holding]`.

**Common mistakes**

- In tree DP, returning only one value when the parent needs to know more than that.

**Tree DP**

| Problem | Notes |
|---|---|
| ⭐ LC 337 House Robber III | Return (rob, skip) |
| ⭐ LC 124 Binary Tree Maximum Path Sum | |
| ⭐ LC 968 Binary Tree Cameras | Three states per node |
| LC 1372 Longest ZigZag Path in a Binary Tree | |

**State machine DP (the stock problems)**

| Problem | Notes |
|---|---|
| ⭐ LC 121 Best Time to Buy and Sell Stock | |
| LC 122 Best Time to Buy and Sell Stock II | |
| ⭐ LC 309 Best Time to Buy and Sell Stock with Cooldown | Draw the state diagram |
| LC 714 Best Time to Buy and Sell Stock with Transaction Fee | |
| ⭐ LC 123 Best Time to Buy and Sell Stock III | |
| LC 188 Best Time to Buy and Sell Stock IV | Generalize to k transactions |

**Checkpoint:** Draw the state diagram for LC 309 and derive every transition from it.

---

## Week 12: Bitmask DP, Digit DP, and Final Review (Dec 7 – Dec 13)

**Concepts:** using a bitmask to represent "which items are used" (practical when n ≤ 20), TSP-style DP, and digit DP with a "tight" flag.

### Resources

- 📖 [USACO Guide](https://usaco.guide): Gold → *Bitmask DP* module, and the *Digit DP* module.
- 📖 Competitive Programmer's Handbook: Ch 10 (Bit Manipulation), the sections on DP over subsets.
- 🎥 Errichto (YouTube): his DP lectures, including bitmask DP.
- 🏋 AtCoder DP Contest problems O (Matching) and S (Digit Sum). CSES Hamiltonian Flights.

### Study Guide

| Day | Time | Plan |
|---|---|---|
| Mon | 1–1.5 h | Review bit operations (`1<<i`, `mask & (1<<i)`, `mask | (1<<i)`). Solve LC 526. |
| Tue | 1–1.5 h | LC 698. |
| Wed | 1–1.5 h | LC 1335. |
| Thu | 1–1.5 h | LC 787. |
| Fri | 1–1.5 h | Read the USACO Digit DP module. Solve LC 902. |
| **Sat** (weekend) | 3–4 h | LC 847 (BFS over (node, mask)), LC 1125, CSES Hamiltonian Flights, and AtCoder S. LC 233 is a stretch. |
| **Sun** (weekend) | 2–3 h | **Mock session:** 3 random DP problems in 90 minutes. Then clear the redo list. |

**Key ideas**

- A bitmask of n bits stands for a subset of n items. The state `dp[mask][last]` covers most TSP-like problems.
- The complexity is O(2ⁿ · n²), so bitmask DP only works for n ≤ about 20.
- Digit DP state: `(position, tight, other info such as a sum or count)`. The "tight" flag tracks whether you're still bounded by the digits of N.

**Common mistakes**

- Operator precedence with bitwise operators. Always use parentheses.
- In digit DP, caching states where tight is true. Those are only reached once, and caching them can give wrong answers if you reuse the cache across different N.

| Problem | Notes |
|---|---|
| ⭐ LC 526 Beautiful Arrangement | First bitmask DP |
| ⭐ LC 698 Partition to K Equal Sum Subsets | |
| ⭐ LC 847 Shortest Path Visiting All Nodes | BFS + bitmask |
| LC 1125 Smallest Sufficient Team | |
| LC 1434 Number of Ways to Wear Different Hats to Each Other (stretch) | |
| ⭐ LC 902 Numbers At Most N Given Digit Set | Introduction to digit DP |
| LC 233 Number of Digit One (stretch) | |
| LC 1335 Minimum Difficulty of a Job Schedule | Partition DP |
| LC 787 Cheapest Flights Within K Stops | DP over edges |

**After Week 12 (optional bonus weekend):** Finish the AtCoder DP Contest problems you haven't solved yet, and re-solve everything on your redo list.

---

## Pattern Cheat Sheet

| Pattern | State | Typical transition | Key problems |
|---|---|---|---|
| Linear | dp[i] | dp[i-1], dp[i-2] | 70, 198 |
| LIS | dp[i] = best ending at i | max over j < i | 300, 1048 |
| Grid | dp[r][c] | from top and left | 62, 64, 174 |
| Two strings | dp[i][j] over prefixes | match / skip | 1143, 72 |
| 0/1 knapsack | dp[cap] | loop capacity backward | 416, 494 |
| Unbounded knapsack | dp[cap] | loop capacity forward | 322, 518 |
| Interval | dp[i][j] | split at k, iterate by length | 312, 1039 |
| Tree | tuple per node | combine children | 337, 968 |
| State machine | dp[i][state] | state diagram | 309, 123 |
| Bitmask | dp[mask][last] | add one more element | 847, 526 |
| Digit | dp[pos][tight][...] | choose the next digit | 902 |

## How to Recognize a DP Problem

- The question asks for a **count**, a **min/max**, or a **yes/no**, and there are many possible choices.
- A brute-force solution would try every choice or every subset.
- The same subproblem comes up more than once in the recursion tree.
- Constraints of n ≤ 5000 suggest O(n²). n ≤ 20 suggests bitmask. Values ≤ 10⁴ suggest a capacity dimension.

## Progress Tracker

| Week | Topic | ⭐ solved | Checkpoint passed | Notes |
|---|---|---|---|---|
| 1 | Recursion fundamentals | / 4 | ☐ | |
| 2 | Trees and structures | / 4 | ☐ | |
| 3 | Backtracking I | / 6 | ☐ | |
| 4 | Backtracking II and D&C | / 5 | ☐ | |
| 5 | Memoization to DP | / 4 | ☐ | |
| 6 | 1D DP | / 5 | ☐ | |
| 7 | Grid DP | / 5 | ☐ | |
| 8 | String DP | / 5 | ☐ | |
| 9 | Knapsack | / 5 | ☐ | |
| 10 | Interval DP | / 3 | ☐ | |
| 11 | Tree and state machine DP | / 6 | ☐ | |
| 12 | Bitmask and digit DP | / 4 | ☐ | |

**Mastery test:** After Week 12, pick 10 random unseen DP problems (Medium/Hard). The goal is to solve 7 or more without hints, writing the state and transition before coding.
