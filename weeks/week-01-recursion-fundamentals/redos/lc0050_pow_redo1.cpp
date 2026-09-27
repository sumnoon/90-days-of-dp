// Week 1 Sunday redo, from memory: LC 50 Pow(x, n)
#include <climits>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    double func(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) {
            return 1. / func(x, -1 * n);
        }

        if (n & 1) {
            return x * func(x * x, (n - 1) / 2);
        }
        else {
            return func(x * x, n / 2);
        }
    }
    double myPow(double x, int n) {
        return func(x, n);
    }
};

int main() {
    struct Case { double x; int n; };
    Case cases[] = {
        {2.0, 10}, {2.1, 3}, {2.0, -2}, {1.0, INT_MIN}, {2.0, INT_MIN},
        {-1.0, INT_MIN}, {-2.0, 3}, {-2.0, 4}, {0.0, 0}, {5.0, 0},
        {0.5, INT_MAX}, {1.0000001, 90000000},  // last one is about e^9, inside |x^n| <= 1e4
    };
    int failed = 0;
    for (auto [x, n] : cases) {
        double got = Solution().myPow(x, n);
        double want = pow(x, static_cast<double>(n));
        bool ok = got == want || fabs(got - want) <= 1e-6 * max(1.0, fabs(want));
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "myPow(" << x << ", " << n << ") = " << got << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
