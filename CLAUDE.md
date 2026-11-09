# Context for Claude Code

This repo is Sumnoon's personal **90 Days of DP** training log (#90DaysOfDP), shared publicly on GitHub and social media.

## The plan
- Full plan: `PLAN.md` (12 weeks, recursion → backtracking → core DP → advanced DP).
- Started **Sun Sep 20, 2026** (Day 0). Week 1 = Sep 21–27 … Week 12 = Dec 7–13. Mastery test Dec 14–20.
- Schedule is built around a Mon–Fri job: weekdays 1–1.5 h, Saturday 3–4 h (hard problems + videos), Sunday 2–3 h (redo, checkpoint, preview).

## Language
- All solutions are written in **C++** (g++ 15.2, MSYS2, on Windows). Use `.cpp` files and modern C++ (C++20).
- Build and run a single file:
  ```bash
  g++ -std=c++20 -Wall -Wextra -g -o warmup warmup_recursion.cpp && ./warmup
  ```
- Don't write solutions in Python. If a snippet is needed for illustration, still use C++.

## Repo layout
- `weeks/week-NN-topic/README.md`: that week's schedule, problem checklist, checkpoint, notes.
- `weeks/week-NN-topic/solutions/`: solution files named `lcXXXX_short_name.cpp`, `cses_name.cpp`, or `atcoder_dp_x.cpp`.
- `weeks/week-NN-topic/notes/`: one note per solved problem, named after its solution file (`lc0206_reverse_linked_list.md`), plus a `README.md` index. Each note covers what the call returns / state, the recursive case or transition, the base case, complexity, and the key insight — following `templates/problem-notes.md`.
- `redo-list.md`: problems that needed a hint or solution; re-solved on Sundays.
- `templates/problem-notes.md`: notes template (state, transition, base case, complexity, key insight).
- `README.md`: overview and progress table.
- `docs/`: the GitHub Pages site (https://sumnoon.github.io/90-days-of-dp/) holding interactive visualizations. One folder per page with a standalone `index.html`; add a card to `docs/index.html` when adding one. These are public, so never put a private link in a note.

## How to help
- When a problem is solved: add the solution file, tick it in the week's README, and add notes if asked.
- Don't reveal full solutions unless asked. Give hints first, following the "When you're stuck" steps in `PLAN.md`.
- When a week's checkpoint passes, mark that week ☑ in the README progress table.
- Commit messages: `Day N: <what was done>`. N is the **plan day** the work belongs to, not the calendar date: Day 0 is the Sep 20 kickoff, Week 1 Mon = Day 1, Week 1 Sun = Day 7, Week 2 Mon = Day 8. Work done late keeps its plan day (Week 1 Monday's problems are Day 1 even if solved on Tuesday).
