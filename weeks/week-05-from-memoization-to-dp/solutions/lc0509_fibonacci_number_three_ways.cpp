// Week 5 Monday: LC 509 three ways (plain recursion, memoized, table)
#include <chrono>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
   public:
    int dp[31];
    int recursive(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return recursive(n - 1) + recursive(n - 2);
    }
    int memorization(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = memorization(n - 1) + memorization(n - 2);
    }
    int tabulation(int n) {
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int fib(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = tabulation(n);
        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

int main() {
    // Each version on LeetCode's range, 0..30 (the table holds 31 entries).
    long long want[31] = {0, 1};
    for (int i = 2; i <= 30; ++i) want[i] = want[i - 1] + want[i - 2];
    int failed = 0;
    for (int n = 0; n <= 30; ++n) {
        Solution s;
        bool ok = s.fib(n) == want[n];                              // fib() uses the table
        memset(s.dp, -1, sizeof(s.dp));
        ok = ok && s.memorization(n) == want[n];
        ok = ok && (n > 27 || s.recursive(n) == want[n]);           // plain recursion: skip the slow top end here
        if (!ok) { ++failed; cout << "FAIL n=" << n << endl; }
    }
    cout << "n = 0..30, all three versions: " << (failed ? "some FAILED" : "all match") << endl;

    // Timings at n = 30, LeetCode's maximum.
    Solution s;
    auto t = [](auto f) { auto a = chrono::steady_clock::now(); long long v = f(); auto b = chrono::steady_clock::now();
                          return make_pair(v, chrono::duration<double, micro>(b - a).count()); };
    auto r = t([&] { return (long long)s.recursive(30); });
    memset(s.dp, -1, sizeof(s.dp));
    auto m = t([&] { return (long long)s.memorization(30); });
    auto b = t([&] { return (long long)s.tabulation(30); });
    cout << "n = 30: recursive " << r.second << " us, memoized " << m.second << " us, table " << b.second << " us (all = " << r.first << ")" << endl;
    return failed != 0;
}
