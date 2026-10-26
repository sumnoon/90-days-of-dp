// Week 5 Friday: LC 1137 N-th Tribonacci Number
// (plain recursion, memoized, and a table; tribonacci() submits the table)
#include <chrono>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
   public:
    int memo[41];
    int calcMemo(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        if (memo[n] != -1) return memo[n];
        return memo[n] = calcMemo(n - 1) + calcMemo(n - 2) + calcMemo(n - 3);
    }
    int calcRecurse(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        return calcRecurse(n - 1) + calcRecurse(n - 2) + calcRecurse(n - 3);
    }
    int tribonacci(int n) {
        memset(memo, -1, sizeof(memo));
        memo[0] = 0, memo[1] = 1, memo[2] = 1;
        for (int i = 3; i <= n; ++i) {
            memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
        }

        return memo[n];
    }
};

int main() {
    long long t[38] = {0, 1, 1};
    for (int i = 3; i <= 37; ++i) t[i] = t[i - 1] + t[i - 2] + t[i - 3];
    int failed = 0;
    for (int n = 0; n <= 37; ++n) {                    // LeetCode: 0 <= n <= 37
        Solution a, b, c;
        memset(b.memo, -1, sizeof(b.memo));           // calcMemo needs the cache cleared first
        int table = a.tribonacci(n), memo = b.calcMemo(n);
        int plain = n <= 25 ? c.calcRecurse(n) : table; // plain recursion only where it's quick
        if (table != t[n] || memo != t[n] || plain != t[n]) { ++failed; cout << "FAIL n = " << n << endl; }
    }
    cout << "n = 0..37: " << (failed ? "some FAILED" : "table and memoized all correct (plain recursion up to 25)") << endl;

    for (int v = 0; v < 2; ++v) {
        Solution s;
        memset(s.memo, -1, sizeof(s.memo));
        auto t0 = chrono::steady_clock::now();
        int r = v == 0 ? s.calcMemo(37) : s.tribonacci(37);
        auto us = chrono::duration<double, micro>(chrono::steady_clock::now() - t0).count();
        cout << (v == 0 ? "memoized" : "table   ") << " n = 37: " << r << " in " << us << " us" << endl;
    }
    return failed != 0;
}
