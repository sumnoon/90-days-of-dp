---
name: 90 Days of DP
description: Interactive explanations of recursion and dynamic programming, published alongside a 12-week training log.
colors:
  bg: "#E9EEF2"
  surface: "#FDFEFE"
  surface-2: "#DFE7EC"
  ink: "#0F1B24"
  muted: "#576875"
  faint: "#8598A5"
  line: "#C4D2DB"
  accent: "#0A6E6C"
  accent-soft: "#CDE6E4"
  hot: "#B2451A"
  hot-soft: "#F6DED3"
  blue: "#1F5FA8"
  blue-soft: "#D4E3F5"
  bad: "#97261F"
  bad-soft: "#F6D6D3"
typography:
  display:
    fontFamily: "Bricolage Grotesque, Trebuchet MS, sans-serif"
    fontSize: "clamp(28px, 6vw, 46px)"
    fontWeight: 700
    lineHeight: 1.04
    letterSpacing: "-0.02em"
  title:
    fontFamily: "Bricolage Grotesque, Trebuchet MS, sans-serif"
    fontSize: "22px"
    fontWeight: 700
    lineHeight: 1.2
    letterSpacing: "-0.01em"
  body:
    fontFamily: "Source Sans 3, -apple-system, Segoe UI, sans-serif"
    fontSize: "16px"
    fontWeight: 400
    lineHeight: 1.55
  label:
    fontFamily: "JetBrains Mono, ui-monospace, Consolas, monospace"
    fontSize: "11px"
    fontWeight: 700
    letterSpacing: "0.12em"
  mono:
    fontFamily: "JetBrains Mono, ui-monospace, Consolas, monospace"
    fontSize: "12.5px"
    fontWeight: 400
rounded:
  sm: "4px"
  md: "6px"
spacing:
  xs: "6px"
  sm: "10px"
  md: "18px"
  lg: "22px"
components:
  button-primary:
    backgroundColor: "{colors.accent}"
    textColor: "{colors.surface}"
    rounded: "{rounded.sm}"
    padding: "7px 14px"
  button-default:
    backgroundColor: "{colors.surface}"
    textColor: "{colors.ink}"
    rounded: "{rounded.sm}"
    padding: "7px 14px"
  button-toggle-selected:
    backgroundColor: "{colors.hot-soft}"
    textColor: "{colors.hot}"
    rounded: "{rounded.sm}"
    padding: "6px 11px"
  panel:
    backgroundColor: "{colors.surface}"
    textColor: "{colors.ink}"
    rounded: "{rounded.md}"
  panel-header:
    backgroundColor: "{colors.surface-2}"
    textColor: "{colors.muted}"
    padding: "11px 16px"
  stack-frame:
    backgroundColor: "{colors.surface-2}"
    textColor: "{colors.muted}"
    rounded: "{rounded.sm}"
    padding: "6px 9px"
  stack-frame-top:
    backgroundColor: "{colors.hot-soft}"
    textColor: "{colors.ink}"
    rounded: "{rounded.sm}"
    padding: "6px 9px"
---

# Design System: 90 Days of DP

<!-- INCUMBENT CAPTURE — recorded before a redesign, as evidence and anti-reference.
     This records what the six pages under docs/ look like today. It is not a
     commitment to preserve any of it. Descriptive language here was derived from
     the code and its authoring intent; the qualitative interview that `document`
     normally runs was deliberately skipped, because this world is being replaced. -->

## Overview

**Creative North Star: "The Quiet Instrument Panel"**

The incumbent world reads as a well-kept technical readout: cool slate grounds,
a single teal accent for "settled" state, a burnt-orange accent for "happening
right now", and everything else in greys. It behaves like a debugger that has
been tidied up — dense information, flat surfaces, hairline borders, tabular
alignment — rather than like a teaching artifact or an editorial page.

Density is moderate-to-high and uniform. Every page is a vertical stack of
bordered panels of equal visual weight: a control bar, a stage, a narration
strip, then a two-column code/stack pair. The structure repeats so literally
across all five steppers that the pages are hard to tell apart at a glance,
which is the system's central weakness rather than a strength.

The type pairing does most of the personality work: a wide, slightly eccentric
display grotesque against a plain humanist body and a monospace used for every
piece of data. The palette carries almost none. Motion is effectively absent —
one `transition` declaration per page, none on the landing page.

**Key Characteristics:**

- Cool blue-grey neutrals throughout; no warm tone anywhere in the system
- One structural idiom (the bordered panel) reused for every role
- Semantic color carries state: teal = resolved, orange = active, blue = origin
- Monospace for all data, numbers and code; never for prose
- Flat by default, with one shared ambient shadow on containers
- Full light/dark parity through a three-block token pattern

## Colors

A cool, desaturated palette: slate-blue neutrals with one teal accent, one
burnt-orange accent, and two situational hues.

### Primary

- **Deep Teal** (#0A6E6C): the brand accent. Buttons, links, eyebrow labels,
  focus rings, and — semantically — anything already resolved or reversed.
  Lightens to **Phosphor Teal** (#3FC6BE) in dark mode.

### Secondary

- **Burnt Orange** (#B2451A): "this is happening now." The active stack frame,
  the executing code line, the current pointer, the node just changed. Paired
  with **Orange Wash** (#F6DED3) as a fill behind active rows.

### Tertiary

- **Plot Blue** (#1F5FA8): origin marking where a second identity is needed —
  the second input list on the LC 21 page, the downward direction on the order
  page. Named `--blue` on one page and `--down` on another for the same value,
  which is drift, not intent.
- **Alarm Red** (#97261F): mismatch only, on the two-pointer page. Appears in
  exactly one situation across the whole site.

### Neutral

- **Slate Mist** (#E9EEF2): page ground.
- **Near White** (#FDFEFE): panel and card surfaces.
- **Cool Chalk** (#DFE7EC): panel headers, control bars, inline code fills.
- **Deep Slate Ink** (#0F1B24): primary text.
- **Slate Grey** (#576875): secondary prose and supporting text.
- **Faint Slate** (#8598A5): line numbers, axis labels, metadata.
- **Hairline** (#C4D2DB): every border in the system.

### Named Rules

**The Two-Accent Rule.** Teal and orange are the only accents allowed to carry
meaning site-wide. Teal means settled, orange means active. Any further hue must
be justified by a third identity on that specific page, and is local to it.

**The Cool-Only Rule.** Every neutral is blue-biased. No warm grey, cream or
paper tone exists anywhere in the incumbent system.

## Typography

**Display Font:** Bricolage Grotesque (fallback Trebuchet MS, sans-serif)
**Body Font:** Source Sans 3 (fallback system UI stack)
**Label/Mono Font:** JetBrains Mono (fallback ui-monospace, Consolas)

**Character:** A wide, slightly quirky variable grotesque for headlines against
a neutral humanist body — the display face supplies nearly all the personality
while the body face gets out of the way. Monospace is not decorative here: it
marks *data*, and is used for every number, identifier, code line and label.

### Hierarchy

- **Display** (700, clamp(28px, 6vw, 46px), 1.04, -0.02em): the one page
  headline. `text-wrap: balance`.
- **Title** (700, 22px, 1.2, -0.01em): section headings in the notes area below
  the interactive stage.
- **Body** (400, 16px, 1.55): all prose. Constrained to 64–68ch.
- **Label** (700, 11px, 0.12em, uppercase, mono): panel headers, eyebrows, the
  legend, stat-tile keys.
- **Mono** (400, 12.5px): code panels, stack frames, cell values, counters.

### Named Rules

**The Mono-Means-Data Rule.** Monospace marks something the program actually
computed — a value, a line of code, an index, a count. It is never used for
prose, and prose is never set in the display face.

**The Single Headline Rule.** One display-size element per page, at the top.
Everything below it steps down to 22px or smaller.

## Layout

A single centered column, `max-width` 960–1000px, with 20px side padding and
`padding-block: 32px 56px`. Content is a vertical flex stack with a 22px gap.

Inside the interactive stage, a consistent vertical order: control bar → visual
stage → narration strip → transport controls → legend. Below the stage sits a
two-column grid (`1.15fr .85fr` or `1.2fr .8fr`) pairing the code panel with the
call-stack panel, collapsing to one column at 720px. The landing page uses a
two-column card grid collapsing at 640px.

Spacing is informal rather than tokenized: 6px within components, 10–12px
between siblings, 18px panel padding, 22px between major blocks. There is no
named spacing scale in the code — the values above are observed, not declared.

Wide content (code, diagrams, trees) sits in its own `overflow-x: auto`
container so the page body never scrolls sideways. The Fibonacci tree sets an
explicit pixel width and scrolls horizontally at larger n.

## Elevation & Depth

Nearly flat. Depth comes from tonal layering — page ground, panel surface,
header fill — reinforced by 1px hairline borders, not from shadows.

### Shadow Vocabulary

- **Ambient container** (`0 1px 2px rgba(15,27,36,.06), 0 8px 24px -12px rgba(15,27,36,.18)`):
  the single shared shadow, applied to panels and cards. In dark mode it
  deepens to `0 1px 2px rgba(0,0,0,.5), 0 10px 28px -14px rgba(0,0,0,.7)`.

### Named Rules

**The One-Shadow Rule.** The system has exactly one shadow token and it never
changes on interaction. Hover moves a border color, never elevation.

## Shapes

Rectilinear and restrained. Two radii only: 4px for controls and small cells,
6px for panels and cards. SVG nodes use 4–5px, circles appear only in the
Fibonacci tree where the data is a node graph.

Borders are the primary form-defining device: every panel, cell, frame and
control is outlined in 1px hairline. State is expressed by *thickening* or
recoloring that border (3px orange outline for the current element, dashed for
pending or skipped) rather than by fill alone.

## Components

### Buttons

- **Shape:** 4px radius, 1px hairline border
- **Primary:** teal fill, near-white text, 7px 14px padding, 600 weight
- **Default:** surface fill, ink text, same metrics
- **Hover:** border and text shift to teal; no movement, no elevation
- **Toggle selected:** orange wash fill, orange border, orange text, mono
- **Disabled:** `opacity: .4`, default cursor
- **Focus:** global `:focus-visible` — 2px teal outline, 2px offset

### Panels / Containers

- **Corner Style:** 6px
- **Background:** near-white surface; header strip in cool chalk
- **Border:** 1px hairline, plus a hairline divider under the header
- **Shadow:** the single ambient container shadow
- **Header:** 11px uppercase mono label, 0.12em tracking, muted, 11px 16px

### Stat tiles (Fibonacci page)

Bordered surface blocks with an 10px uppercase mono key, a 26px display-weight
value colored by role (orange for cost, teal for the useful figure), and a 12px
supporting line. Tabular numerals are not set, which is a defect at this size.

### Signature component: the stepper

The recurring pattern that defines the site. Prev / Next / a range scrubber /
Play / Reset, with `←` `→` keyboard support, a step counter in mono, and a
synchronized set of panels: a visual stage, a one-sentence narration, a code
panel with the executing line filled orange, and a call-stack list with the
innermost frame on top and outlined in orange. Play auto-advances at
1050–1150ms and stops at the end.

### Signature component: the call-stack list

Frames as bordered mono rows, innermost first, top frame in orange wash. Empty
state is a dashed-border row reading "empty". This is the clearest piece of the
incumbent system and the idea most worth carrying forward in spirit.

## Do's and Don'ts

### Do:

- **Do** define the complete light palette on bare `:root`, then redefine only
  the tokens under `@media (prefers-color-scheme: dark)` guarded by
  `:root:not([data-theme="light"])`, and again under `:root[data-theme="dark"]`.
- **Do** give `body` an explicit token background.
- **Do** put every wide element (code, tree, diagram) in its own
  `overflow-x: auto` container.
- **Do** use monospace for every computed value, and tabular numerals wherever
  digits change in place.
- **Do** express state with both color and a second channel (border weight,
  dash pattern, position) so it survives color-blindness.

### Don't:

- **Don't** duplicate the token block per page. Six copies already drifted:
  `--down` and `--blue` are the same color under two names, and `--bad`,
  `--dead` and `--hot-soft` exist on some pages but not others.
- **Don't** add a third semantic accent without a page-specific identity to
  justify it.
- **Don't** convey state by fill color alone.
- **Don't** reach for shadow on hover; the system moves borders instead.

### Known defects in this incumbent (reasons for the redesign)

- **Every page looks the same.** One panel idiom, one layout order, identical
  chrome. Five different ideas wear one uniform.
- **No motion.** One `transition` per page, none on the landing page. Steppers
  cut between states with no continuity, so the reader must re-find what moved.
- **Token duplication across six files**, already drifting.
- **No spacing scale.** Values are ad hoc.
- **The landing page is thin** — two cards and a short explainer, carrying none
  of the identity and no sense of a 12-week body of work.
- **Display face does all the identity work**; palette and layout contribute
  almost nothing distinctive.
