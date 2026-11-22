# Week 6 checkpoint: one state sentence per problem

Written from memory on Mon 23 Nov, before looking at the solutions.

LC 53 · Maximum Subarray — memo[i] is the largest sum of a nonempty contiguous subarray ending exactly at index i.

LC 152 · Maximum Product Subarray
- maxMemo[i] is the largest product of a nonempty contiguous subarray ending at i.
- minMemo[i] is the smallest product of a nonempty contiguous subarray ending at i.

LC 322 · Coin Change — memo[remaining] is the fewest coins needed to make exactly remaining, or ∞ if that amount is unreachable.

LC 139 · Word Break — memo[i] tells me whether I can split the suffix s[i:] into complete dictionary words.

LC 91 · Decode Ways — memo[i] counts the valid ways to decode the suffix s[i:].

LC 300 · Longest Increasing Subsequence
- Take or skip — memo[i][prev + 1] is the maximum number of elements I can still choose from index i onward while keeping the sequence strictly increasing, given that prev is my last chosen index (-1 if none).
- Ending at i — memo[i] is the length of the longest strictly increasing subsequence ending at index i.
- O(n log n) list — tails[k] is the smallest possible last value of a strictly increasing subsequence of length k + 1 seen so far.

LC 673 · Number of Longest Increasing Subsequence
- lengthMemo[i] is the length of the longest strictly increasing subsequence ending at i.
- countMemo[i] counts how many distinct choices of indices achieve that length and end at i.

LC 1048 · Longest String Chain — memo[word] is the number of words in the longest chain ending at word, including word itself.

LC 983 · Minimum Cost for Tickets — memo[i] is the minimum cost to cover the remaining travel days when days[i] is the first uncovered day.

CSES · Minimizing Coins — memo[remaining] is the fewest coins needed to make exactly remaining, or ∞ if that sum is unreachable.

LC 354 · Russian Doll Envelopes (stretch) — memo[i] is the maximum number of envelopes I can nest with envelope i as the outermost, counting i itself. Each inner envelope must be strictly smaller in both width and height.
