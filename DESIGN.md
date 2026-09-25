---
name: 90 Days of DP
description: Enamel wayfinding signage for recursion — fixed geometry, named lines, one legend that never lies.
colors:
  ground: "#EDEDEF"
  plate: "#FFFFFF"
  plate-2: "#F5F5F7"
  ink: "#16181D"
  ink-2: "#41464E"
  ink-3: "#62676F"
  on-ink: "#EDEDEF"
  rule: "#16181D"
  hair: "#C5C8CE"
  now: "#C81326"
  now-line: "#D6202F"
  on-now: "#FFFFFF"
  now-wash: "#FBE7E8"
  set: "#0A50B8"
  set-line: "#0A5BD3"
  set-wash: "#E3EDFB"
  base: "#00684A"
  base-line: "#00875A"
  base-wash: "#DFF1E9"
  idle: "#9AA0A8"
typography:
  display:
    fontFamily: "Archivo, system-ui, -apple-system, Segoe UI, sans-serif"
    fontSize: "clamp(30px, 5.2vw, 46px)"
    fontWeight: 700
    lineHeight: 1.02
    letterSpacing: "-0.03em"
  headline:
    fontFamily: "Archivo, system-ui, -apple-system, Segoe UI, sans-serif"
    fontSize: "clamp(20px, 3vw, 24px)"
    fontWeight: 700
    lineHeight: 1.15
    letterSpacing: "-0.02em"
  claim:
    fontFamily: "Archivo, system-ui, -apple-system, Segoe UI, sans-serif"
    fontSize: "clamp(15px, 2.2vw, 18px)"
    fontWeight: 600
    lineHeight: 1.3
    letterSpacing: "normal"
  body:
    fontFamily: "Archivo, system-ui, -apple-system, Segoe UI, sans-serif"
    fontSize: "16px"
    fontWeight: 400
    lineHeight: 1.55
    letterSpacing: "normal"
  control:
    fontFamily: "Archivo, system-ui, -apple-system, Segoe UI, sans-serif"
    fontSize: "13.5px"
    fontWeight: 600
    lineHeight: 1
    letterSpacing: "normal"
  mono:
    fontFamily: "Spline Sans Mono, ui-monospace, Consolas, monospace"
    fontSize: "12.5px"
    fontWeight: 400
    lineHeight: 1.6
    letterSpacing: "normal"
  label:
    fontFamily: "Spline Sans Mono, ui-monospace, Consolas, monospace"
    fontSize: "11px"
    fontWeight: 700
    lineHeight: 1
    letterSpacing: "0.12em"
spacing:
  s1: "4px"
  s2: "8px"
  s3: "12px"
  s4: "16px"
  s5: "24px"
  s6: "32px"
  s7: "48px"
  s8: "72px"
components:
  button:
    backgroundColor: "{colors.plate}"
    textColor: "{colors.ink}"
    typography: "{typography.control}"
    padding: "8px 12px"
  button-hover:
    backgroundColor: "{colors.ink}"
    textColor: "{colors.on-ink}"
  button-go:
    backgroundColor: "{colors.now-line}"
    textColor: "{colors.on-now}"
    typography: "{typography.control}"
    padding: "8px 12px"
  button-go-hover:
    backgroundColor: "{colors.now}"
    textColor: "{colors.on-now}"
  button-disabled:
    backgroundColor: "{colors.plate}"
    textColor: "{colors.ink-3}"
  toggle-pressed:
    backgroundColor: "{colors.ink}"
    textColor: "{colors.on-ink}"
    typography: "{typography.control}"
    padding: "8px 12px"
  plate:
    backgroundColor: "{colors.plate}"
    textColor: "{colors.ink}"
    padding: "24px 16px"
  panel-head:
    backgroundColor: "{colors.ink}"
    textColor: "{colors.on-ink}"
    typography: "{typography.label}"
    padding: "12px 16px"
  claim-bar:
    backgroundColor: "{colors.ink}"
    textColor: "{colors.on-ink}"
    typography: "{typography.claim}"
    padding: "8px 12px"
  frame-active:
    backgroundColor: "{colors.now-wash}"
    textColor: "{colors.ink}"
    typography: "{typography.mono}"
    padding: "8px 16px"
  code-row-executing:
    backgroundColor: "{colors.now-wash}"
    textColor: "{colors.ink}"
    typography: "{typography.mono}"
    padding: "1px 16px"
---

# Design System: 90 Days of DP

## Overview

**Creative North Star: "The Schematic"**

Every recursion on this site is drawn as a route map. The page is a piece of
enamel wayfinding signage: a pale concrete ground, near-black ink, heavy rules,
square corners, and three route colours that each mean exactly one thing. The
visitor does not browse; they read one claim, step a route, and leave able to
re-derive it. Nothing on the surface is decoration — every mark was either
authored as signage or made by the program being visualized.

The system refuses both defaults of its category: the dark editor cosplay and
the white documentation page with a blue accent. Colour commits at page scale
rather than as chips — an inverted ink bar carries the page's single claim, a
panel header is a solid ink band, the primary control is a full red fill. There
is no decorative grey: grey means *not yet written*, and it says so in the
legend. Density is high and flat; information arrives in bordered plates and
panels butted against rules, not in floating cards.

The world is built to scale to roughly thirty pages across twelve weeks from one
starter shell (`docs/_template/index.html`) and one stylesheet, with no build
step. Chrome, type, colour and motion all come from the shared system; a page
owns only its own drawing. Both themes ship: the light enamel ground is the
default and a dark ground follows the operating system, with every route colour
re-tuned rather than dimmed.

**Key Characteristics:**
- Square corners everywhere; no radius token exists in the system
- Heavy rules (2px standard, 3px structural) instead of shadows or fills
- Three semantic route colours, each with exactly one meaning, declared in a legend
- Archivo for the voice, Spline Sans Mono for everything the program computed
- One claim per page, set in an inverted ink bar
- Motion measured in 100–160ms, asymmetric on press and release

## Colors

Pale concrete ground and near-black ink, cut by three saturated route colours
that carry state and never decorate.

### Primary
- **Signal Red** (`now` / `now-line`): the frame acting *right now*. It marks the
  top of the call stack, the executing code row (via its wash), the active
  station node and the segment just written — and it fills exactly one control,
  Next. Its line variant is the stroke/border weight; the flat variant is used
  for text and numerals. `on-now` exists so the red fill carries correct text
  contrast in either theme.
- **Signal Red Wash** (`now-wash`): the tint behind the executing code row, the
  active stack frame and the current table row. Never used as a decorative
  background.

### Secondary
- **Settled Blue** (`set` / `set-line`): work already written. Segments that have
  been committed, the landing page's route line and station rings, links in
  prose, and the "good" readout on the memoization page.
- **Settled Blue Wash** (`set-wash`): the fill behind a settled token or cell,
  and the text-selection colour.

### Tertiary
- **Base-Case Green** (`base` / `base-line`): the base case, and only the base
  case. Base frames, base nodes, values produced on the way back up.
- **Base-Case Green Wash** (`base-wash`): the fill behind a base-case frame or node.

### Neutral
- **Concrete Ground** (`ground`): the page background. Never used for a drawing surface.
- **Plate White** (`plate`) and **Plate Grey** (`plate-2`): the drawing surface and
  the inline-code tint. A plate is always bordered in ink; it is never a floating card.
- **Ink** (`ink`): body headings, active text, and the fill of inverted bars
  (claim, panel head, pressed toggle) where `on-ink` becomes the text.
- **Ink 2** (`ink-2`) and **Ink 3** (`ink-3`): running prose and quiet metadata /
  line numbers / disabled control text. Three ink steps is the whole text ramp.
- **Rule** (`rule`): every structural border. It tracks ink in both themes.
- **Hair** (`hair`): the 1px internal divider inside a panel or table, and the
  border of a disabled control.
- **Idle Grey** (`idle`): *not yet written* — dashed segments, dashed station
  rings, pruned subtrees. It is the one grey with a meaning.

### Named Rules
**The One Meaning Rule.** Each route colour means exactly one thing across every
page: red is the frame acting now, blue is settled, green is the base case, grey
is not yet written. A page may not borrow a route colour for emphasis, branding
or category, and a page that introduces a fourth meaning must extend the legend.

**The Legend Never Lies Rule.** Any drawing that uses a route colour ships a
`.legend` naming every colour it actually uses, and nothing it does not.

**The Single Red Fill Rule.** At most one element in a viewport carries a solid
red fill, and it is the primary action (Next). Everything else red is a stroke,
a numeral, or a wash.

**The No Decorative Grey Rule.** Grey is never atmosphere. If a mark is grey it
is either quiet ink (`ink-3`, `hair`) or it means the program has not written it
yet (`idle`).

## Typography

**Display / Body Font:** Archivo (with `system-ui`, `-apple-system`, "Segoe UI", sans-serif)
**Label / Mono Font:** Spline Sans Mono (with `ui-monospace`, Consolas, monospace)

**Character:** Archivo is the voice of the signage — grotesque, tightly tracked
at display sizes, confident at 700. Spline Sans Mono is the machine's register:
every value, frame, line number, count and legend label is set in it. The split
is semantic, not decorative — if the program produced it, it is monospaced.
`font-synthesis-weight: none` is set globally, so only real weights (400 / 600 / 700)
are ever used.

### Hierarchy
- **Display** (700, clamp 30→46px, 1.02, -0.03em): the page headline, top-left
  above a 3px rule, capped at 19ch and balanced.
- **Headline** (700, clamp 20→24px, 1.15, -0.02em): section headings in the prose
  below the stage, capped at 24ch.
- **Claim** (600, clamp 15→18px, 1.3): the page's single imperative, reversed out
  of an ink bar, capped at 62ch.
- **Body** (400, 16px, 1.55): lede and running prose, `ink-2`, capped at 66ch.
  Narration under the diagram runs slightly larger (clamp 15→17px) with a
  reserved `min-height` so stepping never reflows the page.
- **Control** (600, 13.5px, 1): transport buttons and mode toggles.
- **Mono / Data** (400, 12.5px, 1.6): call-stack frames, code rows, rail
  metadata, station and node labels. Numerals are `tabular-nums` wherever they
  change between steps.
- **Label** (700, 11px, 0.12–0.16em, uppercase): legend entries, panel heads,
  table heads, readout captions.

### Named Rules
**The Two Registers Rule.** Archivo speaks; Spline Sans Mono computes. A value
the program produced is never set in Archivo, and a sentence addressed to the
reader is never set in mono.

**The One Imperative Rule.** Each page carries exactly one claim, set large
enough to be the spine of the first viewport, and it is the only sentence given
an inverted bar.

**The No Kicker Rule.** No label, eyebrow or category tag sits above a heading.
Wayfinding lives in the top rail (`Week 1 of 12 · recursion fundamentals`), and
the heading starts the page.

## Layout

A single centred column, `max-width: 1120px`, 20px side padding, stacked with a
24px gap and 72px of tail padding. The page opens with the nav rail (a 3px
bottom rule), then the masthead, then the working area.

The working area is a two-column grid: the stage at `minmax(0, 1fr)` and a
260px aside holding the call-stack and code panels, 24px apart, collapsing to a
single column at 800px. The landing page uses a variant of the same idea — a
content column plus a 300px "ticket" of run facts, collapsing at 860px. Split
comparison views (two recursions side by side) use two equal columns inside one
bordered plate, divided by a 2px internal rule, stacking at 720px.

Spacing is an eight-step ramp (4 / 8 / 12 / 16 / 24 / 32 / 48 / 72px). Chrome
padding uses the small end (8–16px), plate interiors use 24px vertical and 16px
horizontal, and 72px only ever closes the page. Measure is capped in `ch`, not
px: 19ch headlines, 62ch claims and narration, 66ch prose.

**The Rule Separates Rule.** Regions are divided by a rule, not by a gap or a
card edge: 3px under the rail and above the transport, 2px above the footer and
under a control strip, 1px hair between rows inside a panel.

## Elevation & Depth

This system has no shadows. There is no shadow token, no `box-shadow` anywhere
in the shipped stylesheet or any page, and no blur or filter. Depth is carried
entirely by three devices: a 2px ink border that makes a plate a physical
surface, tonal separation between the concrete ground and the white plate, and
full-bleed ink inversion for the elements that must sit on top (the claim bar,
panel heads, pressed toggles). The one movement in the system is a 6% scale on
the active station node and a 3% press on a control — motion, not lift.

### Named Rules
**The Flat Enamel Rule.** Nothing casts a shadow and nothing lifts. If an
element needs to read as foreground, invert it to ink or give it a heavier rule;
never float it.

## Shapes

Corners are square by commitment. **There is no radius token in this system, and
that is a defining rule rather than an omission** — plates, panels, buttons,
tokens, cells and washes are all hard-cornered rectangles.

The only curve in the world is a full circle, and it is a material with a
meaning: a station node. Station circles are drawn as SVG circles or as a
`border-radius: 50%` marker on the landing page's route line, always ringed at
3px in a route colour and filled with plate. Routes are thick straight segments
(5px settled, 7px acting now, 3px dashed when not yet written) with butt caps.
Dashes always mean unwritten, never style.

Icons are inline SVG with `stroke-linecap: square` and `stroke-linejoin: miter`
at 13px, drawn from the same geometry as the signage: no icon font, no glyph
characters, no raster icons.

### Named Rules
**The Square Corner Rule.** No border radius on any rectangular element, ever.
The only round thing in the system is a station node, and a station node is
always a circle.

## Components

### Buttons
- **Shape:** hard square corners, 2px ink border, 8px × 12px padding, 13.5px Archivo 600, inline SVG icon at 13px.
- **Default (`.btn`):** plate background, ink text and border.
- **Primary (`.btn--go`, "Next"):** solid `now-line` fill with `on-now` text and a
  matching border — the only red fill on the page. Its label precedes its icon;
  every other button leads with the icon.
- **Hover:** only on fine pointers with hover. Default buttons invert to solid
  ink; the primary deepens to `now`. Transitions run 160ms.
- **Active:** `scale(0.97)` in 100ms, released over 160ms on `--ease-out`.
- **Disabled:** plate background, `ink-3` text, `hair` border, default cursor. The
  primary loses its red entirely when disabled — a spent control is never loud.
- **Focus:** a 3px `now-line` outline offset 2px, system-wide on `:focus-visible`.

### Toggles
- **Style:** same silhouette as a button, driven by `aria-pressed`. Unpressed is
  plate with an ink border; pressed inverts to solid ink with `on-ink` text.
- **Use:** switching the thing being compared (`1..N` vs `N..1`, `<=` vs `<`,
  memoization on/off). Toggles sit in a strip above the stage closed by a 2px rule.

### Cards / Containers
There are no cards. Two container types exist:
- **Plate** (`.plate`): the drawing surface. Plate-white background, 2px ink
  border, 24px/16px padding, square, `overflow-x: auto`. `.plate--flush` drops
  the padding when the drawing bleeds to the border.
- **Panel** (`.panel`): plate-white background, 2px ink border, and an inverted
  ink header band (`.panel__head`) set in 11px uppercase mono at 0.16em.

### Inputs / Fields
- **Scrub** (`.scrub`): a bare `range` input, no border or background, flexing to
  fill the transport bar; `accent-color` is set to `now-line` globally, so the
  native track and thumb carry the system's red. Checkboxes and per-page range
  sliders inherit the same accent.
- Text inputs do not exist in this system.

### Navigation
- **Rail:** a single row closed by a 3px ink rule. The home link is 12.5px mono,
  700, uppercase, 0.16em, ink, reddening on hover. Opposite it sits the location
  (`Week 1 of 12 · recursion fundamentals`) in 12.5px mono `ink-3` with `ink-2`
  bold for the numbers. It wraps rather than collapsing; there is no hamburger.
- **Footer:** a 2px top rule, 13.5px `ink-3`, links in `ink-2`.

### Stepper Transport (signature)
A full-width control bar opened by a 3px rule: Prev, Next, scrub, Play/Pause,
Reset, and a right-aligned mono step counter (`7 / 28`, tabular). Prev and Next
disable at the ends of the sequence; Play swaps its own icon and label to Pause
and advances every 1100ms (1800ms under reduced motion), stopping automatically
at the last step. Left/Right arrow keys step the sequence from anywhere on the
page that is not a text field. The narration line above it is an
`aria-live="polite"` region with a reserved height.

### Call-Stack Panel (signature)
A bordered panel titled `CALL STACK`, listing frames top-of-stack first in
12.5px mono, each row divided by a 1px hair and padded 8px × 16px. The top
frame is boxed on all four sides by a 2px `now-line` outline (inset, so it
never shifts layout), tints its row `now-wash`, and sets its label to bold ink,
with the frame's secondary value in `ink-3`. It is never a one-sided accent
tab: the order page's stack uses the same four-sided box. An empty stack renders one centred italic
`empty` row rather than collapsing.

### Code Panel (signature)
The function under discussion, one row per line, 12.5px mono, with right-aligned
tabular line numbers in `ink-3`. The executing row tints to `now-wash`, bolds its
source to full ink, and turns its line number `now` and bold. Rows are built once
and toggled — never rebuilt — so the 160ms colour transition can fire.

### Legend (signature)
A row of 11px uppercase mono entries at the foot of a plate, each pairing an
18×5px colour bar with its meaning. Unwritten state is drawn as a 3px dashed
`idle` top-border instead of a bar, so the swatch itself shows the dash.

### Route Index (signature)
The landing page replaces a card grid with a line and its stops: a 3px
`set-line` vertical route drawn behind the list, and one 19px circular station
ring per stop, plate-filled, `set-line`-ringed. Each stop is a heading link
(clamp 19→23px Archivo 700), a sentence, and a mono meta line; rows are divided
by 1px hairs, not boxed. The next unbuilt week is a `--next` stop: its ring
turns dashed `idle` and its title drops to `ink-3` 600. Hovering a stop reddens
its ring and title.

### Readout Strip
Where numbers must be compared, they go in one bordered strip of flexed cells
divided by 1px hairs — never a row of metric cards. Captions are 11px uppercase
mono `ink-3`; values are 26px Archivo 700 tabular, coloured `now` for a cost and
`set` for a saving.

### Motion
Motion is a system layer, not a per-page choice. Two easings — `--ease-out`
(`cubic-bezier(0.23, 1, 0.32, 1)`) for settling and `--ease-in-out`
(`cubic-bezier(0.77, 0, 0.175, 1)`) — and three durations: `--t-press` 100ms,
`--t-release` 160ms, `--t-state` 160ms. Press and release are deliberately
asymmetric: the deliberate half snaps, the return settles. Everything is a
transition, never a keyframe animation, because a reader can fire Next twice in a
second and transitions retarget from wherever they are. `prefers-reduced-motion`
keeps every colour transition (shortened to 80ms) and drops all movement and
scaling.

**The Redraw, Don't Rebuild Rule.** Keep drawing elements persistent across steps
so the system's transitions fire. A segment that becomes settled travels from
dashed to solid along its own length, and the active station moves rather than
blinking on and off.

## Do's and Don'ts

### Do:
- **Do** copy `docs/_template/index.html` to start a page, and take chrome, type, colour and motion from `docs/assets/system.css` unchanged.
- **Do** keep every corner square. There is no radius token; do not add one.
- **Do** use a route colour only in its one meaning: red = acting now, blue = settled, green = base case, grey = not yet written.
- **Do** ship a legend for every drawing that uses route colour, naming every colour used and nothing else.
- **Do** separate regions with a rule (3px structural, 2px standard, 1px hair inside a panel).
- **Do** give each page exactly one claim in the inverted ink bar, and one red-filled control.
- **Do** set anything the program computed in Spline Sans Mono, with `tabular-nums` when it changes between steps.
- **Do** cap measure in `ch` (19ch headline, 62ch claim and narration, 66ch prose).
- **Do** keep drawing nodes persistent across steps and animate with transitions in the 100–160ms band.
- **Do** keep colour transitions under `prefers-reduced-motion` and drop only movement.
- **Do** draw icons as inline SVG with square caps and mitred joins at 13px.

### Don't:
- **Don't** add a border radius to any rectangle. The only round element is a station node, and it is a full circle.
- **Don't** add a shadow, blur, glow or gradient. There is no shadow vocabulary and depth comes from rules, tone and ink inversion.
- **Don't** use grey as atmosphere; grey is quiet ink or it means "not yet written".
- **Don't** put a second red fill in a viewport, or colour a non-primary control red.
- **Don't** put a kicker, eyebrow or category label above a heading; wayfinding belongs in the rail.
- **Don't** restyle a button, panel, plate or transport inside a page's `<style>` block — fix the system instead.
- **Don't** introduce a fourth accent hue, or reuse a route colour for branding or emphasis.
- **Don't** use a card grid for an index; use the line-and-stops route index.
- **Don't** use metric cards for numbers; use the bordered readout strip.
- **Don't** use an icon font, glyph characters or raster icons.
- **Don't** rebuild the drawing's DOM between steps; that throws the motion away.
