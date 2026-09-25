---
version: 1
slug: "docs-index-html"
primary_target: "docs/index.html"
related_targets: ["docs/order/index.html","docs/twopointer/index.html","docs/lc206/index.html","docs/fib/index.html","docs/lc21/index.html"]
---

# Surface brief: the docs/ visualization site

**Scope:** `docs/index.html` plus the five stepper pages (`order`, `twopointer`,
`lc206`, `fib`, `lc21`). URLs are fixed. No build step.

**Visitor mode:** Read — the visitor arrives cold from a link and leaves
understanding one idea.

**Audience & job:** A learner mid-struggle with recursion, on desktop at night
or on a phone from a social post. They need the claim, the mechanism, and a
way to step it. Secondary: the author revising, and anyone evaluating him.

**Constraints:** plain HTML/CSS/JS, shared assets allowed, must scale to ~30
pages across 12 weeks with a copyable page template.

## Direction contract

**THESIS:** Every recursion is drawn as a route map — fixed geometry, named
lines, one legend that never lies. It refuses both category defaults: the dark
editor cosplay and the white docs page with a blue accent.

**OWN-WORLD:** Enamel wayfinding signage. Pale concrete ground, near-black
ink, three route colours that each mean one thing and never decorate: red is
the frame acting now, blue is settled, green is the base case. Rules are heavy
(2–3px) and corners are square — no radius anywhere. Station nodes are
circles; routes are thick segments, dashed when not yet written. Archivo for
voice, Spline Sans Mono for everything the program computed.

**STORY:** The visitor reads one claim, steps the route, and understands that
the order of work is decided in one direction and the result assembled in the
other. They leave able to re-derive it.

**FIRST VIEWPORT:** Headline top-left at 40px over a heavy rule; the page's
single claim directly beneath in an inverted ink bar; the diagram plate — white,
2px ink border — carrying the route at working scale with the legend locked
bottom-left; the call stack as a bordered panel to its right; the transport bar
below a full-width rule. The primary action (Next) is the only red fill.

**FORM:** The Schematic, candidate 1 of my ordered grounded list, chosen by the
user over the assigned roll; seed key c8ff1d4d.

**Raises carried from the hands the roll beat:** colour commits at page scale
rather than as chips (cyclorama); one imperative per page, set large enough to
be the spine (WPA poster); no decorative grey — every mark was made by the
program (datamatics).

**Signature interaction:** the route redraws between steps — a segment that
becomes settled travels from dashed to solid along its own length, and the
active station moves rather than blinking on and off.

**FINISH:** unreviewed and undocumented is unfinished; this build ends with the
finish review, the verdict, DESIGN.md, and every shipping raster carrying its
provenance
