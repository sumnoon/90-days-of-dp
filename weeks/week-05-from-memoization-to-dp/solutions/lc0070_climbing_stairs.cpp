// Week 5 Tuesday: LC 70 Climbing Stairs (memoized, top-down)
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
   public:
    int memo[46];
    int func(int idx, int n) {
        if (idx == n) {
            return 1;
        }

        if (idx > n) {
            return 0;
        }

        if (memo[idx] != -1) return memo[idx];

        return memo[idx] = func(idx + 1, n) + func(idx + 2, n);
    }
    int climbStairs(int n) {
        memset(memo, -1, sizeof(memo));
        return func(0, n);
    }
};


// Reference: plain recursion with no cache, the same choice at every step.
long long plain(int left) { return left < 0 ? 0 : left == 0 ? 1 : plain(left - 1) + plain(left - 2); }

int main() {
    long long a = 1, b = 1;                     // ways(0), ways(1): Fibonacci shifted by one
    int failed = 0;
    for (int n = 1; n <= 45; ++n) {             // LeetCode: 1 <= n <= 45
        long long want = b;
        if (n <= 30 && plain(n) != want) want = -1;
        int got = Solution().climbStairs(n);    // a fresh object per call
        if (got != want) { ++failed; cout << "FAIL n = " << n << ": " << got << " vs " << want << endl; }
        if (n <= 5 || n == 45) cout << "n = " << n << " -> " << got << endl;
        long long c = a + b; a = b; b = c;
    }
    cout << "n = 1..45: " << (failed ? "some FAILED" : "all match (plain recursion up to 30, Fibonacci after)") << endl;
    return failed != 0;
}
