# Week 4 notes

One note per solved problem: what the call returns or records, what it passes
down, where the choice is undone, complexity, and the one idea that unlocked
it. Written to be re-read before a redo, not while solving.

| Problem | Day | Solved | The one idea |
|---|---|---|---|
| [⭐ LC 79 Word Search](lc0079_word_search.md) | 22 | clean | The board is the visited set: write `'#'` going in, put the letter back coming out. |
| [LC 93 Restore IP Addresses](lc0093_restore_ip_addresses.md) | 23 | clean | Each level chooses how many digits the next part takes; after three dots the rest must be the last part. |
| [⭐ LC 131 Palindrome Partitioning](lc0131_palindrome_partitioning.md) | 25 | clean | Each level chooses where the next cut goes; a cut is only valid if the piece before it is a palindrome. |

## Visualizations

| Page | What it shows |
|---|---|
| [The board is the visited set](https://sumnoon.github.io/90-days-of-dp/grid/) | LC 79: cells marked `#` on the way in and given back on the way out; the path a success leaves behind. |
| [Where do the dots go?](https://sumnoon.github.io/90-days-of-dp/ip/) | LC 93: the dots placed so far, and every call or rejected part as an outline row with its reason. |

"clean" = solved without a hint. Anything else is on the
[redo list](../../../redo-list.md).
