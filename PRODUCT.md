# Product

<!-- impeccable:product-schema 1 -->

## Platform

web

## Users

Primary: **people learning recursion and dynamic programming** who arrive from a
#90DaysOfDP post or a link in the repo. They meet an idea cold, usually on one
page, and need to understand it without the surrounding context of the plan.

Secondary: **the author (Sumnoon)**, re-reading pages while revising or before a
Sunday redo, and **anyone evaluating him professionally** — the site doubles as
evidence that he can teach, build and finish things. Design serves the learner;
craft carries the portfolio weight.

## Product Purpose

`docs/` is the public face of a personal 12-week training log that runs from
Day 0 (Sun Sep 20, 2026) to Week 12 (Dec 7–13, 2026), plus a mastery test.

The site holds **interactive explanations of ideas a static diagram cannot
carry** — things whose whole point is *when* something happens, or *how many
times*, rather than what the code says. A page exists only when the idea fails
to survive as prose or a picture. Success is a reader stepping through a page
and understanding something they could not get from the code listing.

## Positioning

Each page is built against a specific claim made in the repo's written notes,
and exists to make that claim checkable:

- LC 21's note says `<=` keeps the merge stable — invisible in the output, so
  the page colors nodes by origin and lets the reader flip the operator.
- LC 509's note says naive Fibonacci wastes almost all its work — so the page
  counts the calls and collapses the tree on a memoize toggle.
- The 1..N / N..1 pair claims one moved line flips the output — so the page runs
  both on one call stack.

That coupling (a solved problem, a written note, a page that proves the note's
claim) is the thing a generic algorithm-visualization site does not have.

## Operating Context

- Read on desktop while solving, and on a phone when the link is tapped from a
  social post. Both matter; neither dominates.
- Deployed by **GitHub Pages from `main` / `/docs`**. What is committed is what
  ships, immediately, with no pipeline in between.
- Each page is reached directly by URL from a note or a post, so pages are
  entered sideways far more often than through the landing page.
- The repo around it is C++ solutions plus one Markdown note per problem; the
  pages are linked from those notes and link back to them.

## Capabilities and Constraints

**Confirmed constraints (user-stated):**

- **No build step.** Plain HTML, CSS and JS, directly editable and directly
  servable. No npm, bundler, or CI.
- **Existing URLs must not change:** `/`, `/order/`, `/twopointer/`, `/lc206/`,
  `/fib/`, `/lc21/`. The notes and README link to them.

**Confirmed scope:**

- Shared CSS/JS across pages is **allowed and wanted** — pages need not remain
  standalone single files.
- The design must **scale to roughly 30 pages** across 12 weeks, with a page
  template so a new visualization starts from a working shell.

**Current state:** 6 pages, ~128KB total, each duplicating its own token block.
Five are interactive steppers (prev/next/play/reset, a call-stack panel, a code
panel with the executing line highlighted, keyboard arrows); one is a landing
index. Content is entirely hand-authored, no data source, no backend, no API,
no routes.

**Undecided:** whether runtime dependencies (a CDN library) are acceptable. Not
selected as a constraint, not ruled in either. Currently zero are used, and
Google Fonts is the only external request.

## Brand Commitments

- Name: **90 Days of DP**; hashtag **#90DaysOfDP**.
- Author: **sumnoon**; the repo is public and linked from social posts.
- Voice, as established in the notes: plain, exact, and willing to record
  mistakes. Claims are measured rather than asserted — call counts come from
  instrumenting the real program. Nothing is oversold.

## Evidence on Hand

Real and already written — nothing here needs inventing:

- 5 working interactive pages under `docs/`.
- 8 problem notes under `weeks/week-01-recursion-fundamentals/notes/`, each
  with verified complexity, test tables, and recorded mistakes.
- 9 compiling C++ solutions with test results.
- `PLAN.md`: the full 12-week curriculum with dates, resources and checkpoints.

**No** testimonials, user counts, traffic figures, endorsements, or
institutional affiliation exist. Future work must not fabricate any.

## Product Principles

1. **A page must earn its existence.** If prose or a static diagram carries the
   idea, no page is built. LC 231 was deliberately skipped for this reason.
2. **Show the thing the code hides** — timing, repetition, cost, order. Never
   restate what the listing already says.
3. **Every claim is checked before it ships.** Counts and outputs are measured
   against the real program, not estimated.
4. **A page is entered cold.** It must orient a stranger who arrived from a
   link, with no knowledge of the plan or the preceding pages.
5. **Nothing oversold.** Mistakes are recorded, limits are stated, and the
   reader is trusted with the real detail.

## Accessibility & Inclusion

No formal standard was set by the user. The content is visual and
interaction-driven, so future work must keep: full keyboard operation of every
stepper, state never carried by color alone, respect for
`prefers-reduced-motion`, and legibility in both light and dark themes.
