# Decision mockups — the direction round for the docs/ redesign

These five files are **fixtures, not shipping UI**. They are the hand that was
dealt when the `docs/` site was redesigned on 2026-09-25, each rendering the
*same* first viewport — the LC 206 stepper at step 12, mid-unwind — in a
different visual world, so the comparison was fair.

| File | World | Verdict |
|---|---|---|
| `assigned.html` | The Lecture Board — slate and pressed chalk | the roll's assignment |
| `model-pick.html` | **The Schematic** — enamel wayfinding | **chosen and built** |
| `challenger-cutting-bench.html` | The Select Rail — a film bench flattened | competitive |
| `challenger-orizuru.html` | Thirty-Two Folds — one uncut sheet | competitive |
| `challenger-botanical.html` | The Fixed-Scale Folio — plates at one scale | competitive |

`index.html` stacks them in iframes. It only works over a local server, not
over `file://`.

## Why they are kept

They are the evidence for why The Schematic was chosen over four alternatives.
The reasoning lives in the direction contract at
[`../../surfaces/docs-index-html.md`](../../surfaces/docs-index-html.md); these
are what that reasoning looked like on screen.

## Why the detector ignores them

`.impeccable/config.json` carries `.impeccable/mocks/**` in `ignoreFiles`.
These pages were written fast to compare *worlds*, not to pass a quality bar:
they carry small label text, skipped heading levels and side-tab accent
borders that would be real faults in shipped pages. Fixing them would spend
effort on four worlds that were not built, and leaving them unignored would
mean 28 findings in every future scan drowning out real ones.

**Nothing here is a pattern to copy.** The shipped system is
[`docs/assets/system.css`](../../../docs/assets/system.css), and the rules it
follows are in [`DESIGN.md`](../../../DESIGN.md).
