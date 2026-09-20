// Day 0 warm-ups: factorial and sum of digits, both recursive.
//
// Fill in the two functions below, then build and run:
//
//     g++ -std=c++20 -Wall -Wextra -g -o warmup warmup_recursion.cpp
//     ./warmup
//
// Before you write either one, answer the two questions above it.
// Then paste the finished function into https://pythontutor.com (set the
// language to C++) and step through it to watch the call stack unwind.
//
// Note: a missing base case here does not raise a tidy error the way it
// would in a scripting language -- it overflows the stack and the program
// dies outright. Each case prints its name *before* it runs, so if the run
// stops mid-line, the last label printed is the call that blew up.

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Delete this line from a function once you have written it.
#define TODO(n) ((void)(n), throw std::logic_error("not written yet"))

// n! computed recursively.
//
// 1. Base case: which n is small enough to answer with no recursion?
// 2. Leap of faith: if factorial(n - 1) already gave you the right
//    answer, what one operation turns it into the answer for n?
int64_t factorial(int64_t n) {
    TODO(n);
}

// Sum the decimal digits of a non-negative n, recursively.
//
// 1. Base case: which n needs no recursion at all?
// 2. Leap of faith: n % 10 peels off the last digit and n / 10 is
//    everything else. If sum_of_digits(n / 10) is already correct,
//    how do you finish?
int64_t sum_of_digits(int64_t n) {
    TODO(n);
}

struct Case {
    int64_t arg;
    int64_t want;
};

struct Suite {
    std::string name;
    int64_t (*fn)(int64_t);
    std::vector<Case> cases;
};

int main() {
    const std::vector<Suite> suites = {
        {"factorial", factorial, {{0, 1}, {1, 1}, {5, 120}, {10, 3628800}}},
        {"sum_of_digits", sum_of_digits, {{0, 0}, {7, 7}, {123, 6}, {99999, 45}}},
    };

    int failures = 0;
    for (const Suite& s : suites) {
        for (const Case& c : s.cases) {
            const std::string label = s.name + "(" + std::to_string(c.arg) + ")";
            // Flushed before the call so a stack overflow still names the case.
            std::cout << label << " ... " << std::flush;
            int64_t got = 0;
            try {
                got = s.fn(c.arg);
            } catch (const std::logic_error&) {
                std::cout << "not written yet" << std::endl;
                ++failures;
                continue;
            }
            const bool ok = (got == c.want);
            if (!ok) ++failures;
            std::cout << (ok ? "ok" : "FAIL") << " -> " << got
                      << " (want " << c.want << ")" << std::endl;
        }
    }

    std::cout << std::endl;
    if (failures == 0) {
        std::cout << "All green. Now step through both in Python Tutor (C++ mode)." << std::endl;
    } else {
        std::cout << failures << " case(s) still to fix." << std::endl;
    }
    return failures == 0 ? 0 : 1;
}
