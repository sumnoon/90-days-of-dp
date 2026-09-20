"""Day 0 warm-ups: factorial and sum of digits, both recursive.

Fill in the two functions below, then run this file:

    python weeks/week-01-recursion-fundamentals/solutions/warmup_recursion.py

Before you write either one, answer the two questions in the docstring.
Then paste the finished function into https://pythontutor.com and step
through it so you can watch the call stack grow and unwind.
"""


def factorial(n: int) -> int:
    """n! computed recursively.

    1. Base case: which n is small enough to answer with no recursion?
    2. Leap of faith: if factorial(n - 1) already gave you the right
       answer, what one operation turns it into the answer for n?
    """
    raise NotImplementedError


def sum_of_digits(n: int) -> int:
    """Sum the decimal digits of a non-negative n, recursively.

    1. Base case: which n needs no recursion at all?
    2. Leap of faith: n % 10 peels off the last digit and n // 10 is
       everything else. If sum_of_digits(n // 10) is already correct,
       how do you finish?
    """
    raise NotImplementedError


CASES = [
    ("factorial", factorial, [(0, 1), (1, 1), (5, 120), (10, 3628800)]),
    ("sum_of_digits", sum_of_digits, [(0, 0), (7, 7), (123, 6), (99999, 45)]),
]


def main() -> None:
    failures = 0
    for name, fn, cases in CASES:
        for arg, want in cases:
            try:
                got = fn(arg)
            except NotImplementedError:
                print(f"--  {name}({arg}) -> not written yet")
                failures += 1
                continue
            except RecursionError:
                print(f"!!  {name}({arg}) -> RecursionError: check your base case")
                failures += 1
                continue
            mark = "ok " if got == want else "FAIL"
            if got != want:
                failures += 1
            print(f"{mark} {name}({arg}) -> {got} (want {want})")
    print()
    print("All green. Now step through both in Python Tutor." if not failures
          else f"{failures} case(s) still to fix.")


if __name__ == "__main__":
    main()
