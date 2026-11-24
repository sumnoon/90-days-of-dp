// Week 7 Tuesday: LC 63 Unique Paths II, as a memoized recursion, a table and a single row
#include <climits>
#include <cstring>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[110][110];
    // Adds two counts, stopping at INT_MAX instead of overflowing.
    int safeAdd(int a, int b) { return (a > INT_MAX - b) ? INT_MAX : a + b; }
    // 1. Memoized: calcRecurse(i, j) = number of paths from (i, j) to the bottom-right corner.
    int calcRecurse(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i == n - 1 && j == m - 1) {
            return grid[i][j] == 0;
        }
        if (i >= n || j >= m) return 0;
        if (grid[i][j] == 1) return 0;

        if (memo[i][j] != -1) return memo[i][j];

        return memo[i][j] =
                   safeAdd(calcRecurse(i + 1, j, n, m, grid), calcRecurse(i, j + 1, n, m, grid));
    }
    // 2. Table: memo[i][j] = number of paths from the top-left corner to (i, j).
    int calcTab(int n, int m, vector<vector<int>>& grid) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1)
                    memo[i][j] = 0;
                else if (i == 0 && j == 0)
                    memo[i][j] = 1;
                else {
                    int top = (i > 0) ? memo[i - 1][j] : 0;
                    int left = (j > 0) ? memo[i][j - 1] : 0;
                    memo[i][j] = safeAdd(top, left);
                }
            }
        }
        return memo[n - 1][m - 1];
    }
    // 3. One row: dp[j] = number of paths to column j of the current row.
    int calc(int n, int m, vector<vector<int>>& grid) {
        vector<int> dp(m + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1)
                    dp[j] = 0;
                else if (i == 0 && j == 0)
                    dp[j] = 1;
                else {
                    int left = (j > 0) ? dp[j - 1] : 0;
                    dp[j] = safeAdd(dp[j], left);
                }
            }
        }

        return dp[m - 1];
    }
    // Each version takes just the grid. uniquePathsWithObstacles uses the memoized version.
    int uniquePathsWithObstaclesTable(vector<vector<int>>& grid) {
        return calcTab(grid.size(), grid[0].size(), grid);
    }
    int uniquePathsWithObstaclesRow(vector<vector<int>>& grid) {
        return calc(grid.size(), grid[0].size(), grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        memset(memo, -1, sizeof(memo));
        int ans = calcRecurse(0, 0, n, m, obstacleGrid);
        return ans;
    }
};

// Reference for small grids: walk every path.
long long brute(const vector<vector<int>>& g, int i, int j) {
    int n = g.size(), m = g[0].size();
    if (i >= n || j >= m || g[i][j]) return 0;
    if (i == n - 1 && j == m - 1) return 1;
    return brute(g, i + 1, j) + brute(g, i, j + 1);
}

// Reference for big grids: paths from each cell to the end, in long long, capped at 4 * 10^18.
long long countFromEnd(const vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    const long long CAP = 4000000000000000000LL;
    vector<vector<long long>> d(n + 1, vector<long long>(m + 1, 0));
    for (int i = n - 1; i >= 0; --i)
        for (int j = m - 1; j >= 0; --j) {
            if (g[i][j]) d[i][j] = 0;
            else if (i == n - 1 && j == m - 1) d[i][j] = 1;
            else d[i][j] = min(CAP, d[i + 1][j] + d[i][j + 1]);
        }
    return d[0][0];
}

int failed = 0, tested = 0;
void check(Solution& s, vector<vector<int>> g, long long want, const char* name) {
    ++tested;
    if (s.uniquePathsWithObstacles(g) != want || s.uniquePathsWithObstaclesTable(g) != want ||
        s.uniquePathsWithObstaclesRow(g) != want) {
        ++failed;
        cout << "FAIL on " << name << " (" << g.size() << " x " << g[0].size() << ")" << endl;
    }
}

int main() {
    auto s = make_unique<Solution>();
    check(*s, {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2, "example 1");
    check(*s, {{0, 1}, {0, 0}}, 1, "example 2");
    check(*s, {{0}}, 1, "1 x 1 open");
    check(*s, {{1}}, 0, "1 x 1 blocked");

    // 100 x 100 grids whose answer is 0 but whose cells hold huge counts: these overflowed an int before safeAdd.
    vector<vector<int>> g(100, vector<int>(100, 0));
    g[99][99] = 1;
    check(*s, g, 0, "only the end blocked");
    g[99][99] = 0, g[98][99] = 1, g[99][98] = 1;
    check(*s, g, 0, "end walled off");
    g[98][99] = 0, g[99][98] = 0, g[0][0] = 1;
    check(*s, g, 0, "only the start blocked");

    mt19937 rng(63);
    for (int t = 0; t < 3000; ++t) {                   // small grids, against every path
        int n = 1 + rng() % 7, m = 1 + rng() % 7;
        vector<vector<int>> h(n, vector<int>(m));
        for (auto& row : h)
            for (int& x : row) x = rng() % 4 == 0;
        check(*s, h, brute(h, 0, 0), "small random grid");
    }
    for (int t = 0; t < 4000; ++t) {                   // up to 100 x 100, various obstacle densities
        int n = 1 + rng() % 100, m = 1 + rng() % 100, p = 2 + rng() % 30;
        vector<vector<int>> h(n, vector<int>(m));
        for (auto& row : h)
            for (int& x : row) x = rng() % p == 0;
        long long want = countFromEnd(h);
        if (want > 2000000000) continue;               // LeetCode guarantees the answer is at most 2 * 10^9
        check(*s, h, want, "large random grid");
    }
    cout << tested << " grids: " << (failed ? "some FAILED" : "all three versions match the reference") << endl;
    return failed != 0;
}
