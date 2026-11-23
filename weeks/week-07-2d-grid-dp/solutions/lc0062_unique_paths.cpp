// Week 7 Monday: LC 62 Unique Paths, as a memoized recursion, a table and a single row
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[110][110];
    // 1. Memoized: calcRecurse(i, j) = number of paths from (i, j) to the bottom-right corner.
    int calcRecurse(int i, int j, int n, int m) {
        if (i == n - 1 && j == m - 1) return 1;
        if (i >= n || j >= m) return 0;

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        return memo[i][j] = calcRecurse(i + 1, j, n, m) + calcRecurse(i, j + 1, n, m);
    }
    // 2. Table: memo[i][j] = number of paths from the top-left corner to (i, j).
    int calcTab(int n, int m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0)
                    memo[i][j] = 1;
                else {
                    memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
                }
            }
        }

        return memo[n - 1][m - 1];
    }
    // 3. One row: dp[j] = number of paths to column j of the current row.
    int calc(int n, int m) {
        vector<int> dp(m + 1);
        for (int i = 0; i < m; ++i) {
            dp[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[m - 1];
    }
    // Each version takes just (m, n). uniquePaths uses the one-row version.
    int uniquePathsMemo(int m, int n) {
        memset(memo, -1, sizeof(memo));
        return calcRecurse(0, 0, n, m);
    }
    int uniquePathsTable(int m, int n) { return calcTab(n, m); }
    int uniquePaths(int m, int n) {
        int ans = calc(n, m);
        return ans;
    }
};

// Reference: the exact count C(m + n - 2, m - 1), since every path is m - 1 downs and n - 1 rights in some order.
// Stops early once it passes 2 * 10^9, so it never overflows.
long long choose(int a, int b) {
    long long r = 1;
    for (int i = 1; i <= b && r <= 2000000000; ++i) r = r * (a - b + i) / i;
    return r;
}

int main() {
    Solution s;                                        // memo is 110 x 110 ints (48 KB), fine on the stack
    int failed = 0, tested = 0;
    for (int m = 1; m <= 100; ++m)
        for (int n = 1; n <= 100; ++n) {
            long long want = choose(m + n - 2, min(m, n) - 1);
            if (want > 2000000000) continue;           // LeetCode guarantees the answer is at most 2 * 10^9
            ++tested;
            if (s.uniquePathsMemo(m, n) != want || s.uniquePathsTable(m, n) != want || s.uniquePaths(m, n) != want) {
                ++failed;
                cout << "FAIL on m = " << m << ", n = " << n << endl;
            }
        }
    cout << tested << " grids up to 100 x 100: "
         << (failed ? "some FAILED" : "all three versions match C(m + n - 2, m - 1)") << endl;
    return failed != 0;
}
