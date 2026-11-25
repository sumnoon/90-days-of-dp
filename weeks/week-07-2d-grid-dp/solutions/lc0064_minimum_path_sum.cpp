// Week 7 Wednesday: LC 64 Minimum Path Sum, in one row
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
public:
    // One row: memo[j] = the smallest sum of a path from the top-left corner to column j of the current row.
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> memo(m + 1);

        memo[0] = grid[0][0];

        for (int i = 1; i < m; ++i) {
            memo[i] = memo[i - 1] + grid[0][i];
        }

        for (int i = 1; i < n; ++i) {
            memo[0] += grid[i][0];
            for (int j = 1; j < m; ++j) {
                memo[j] = grid[i][j] + min(memo[j], memo[j - 1]);
            }
        }

        return memo[m - 1];
    }
};

// Reference for small grids: try every path.
int brute(const vector<vector<int>>& g, int i, int j) {
    int n = g.size(), m = g[0].size();
    if (i == n - 1 && j == m - 1) return g[i][j];
    int best = INT_MAX;
    if (i + 1 < n) best = min(best, brute(g, i + 1, j));
    if (j + 1 < m) best = min(best, brute(g, i, j + 1));
    return g[i][j] + best;
}

int failed = 0, tested = 0;
void check(Solution& s, vector<vector<int>> g, int want, const char* name) {
    ++tested;
    if (s.minPathSum(g) != want) {
        ++failed;
        cout << "FAIL on " << name << " (" << g.size() << " x " << g[0].size() << ")" << endl;
    }
}

int main() {
    Solution s;
    check(s, {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7, "example 1");
    check(s, {{1, 2, 3}, {4, 5, 6}}, 12, "example 2");
    check(s, {{5}}, 5, "1 x 1");
    // LeetCode's limits: up to 200 x 200, values 0..200. The largest sum is 399 * 200 = 79,800.
    check(s, vector<vector<int>>(200, vector<int>(200, 200)), 399 * 200, "200 x 200 all 200");
    check(s, vector<vector<int>>(1, vector<int>(200, 200)), 200 * 200, "one row");
    check(s, vector<vector<int>>(200, vector<int>(1, 200)), 200 * 200, "one column");

    mt19937 rng(64);
    for (int t = 0; t < 5000; ++t) {                   // small grids, against every path; a third are all zeros
        int n = 1 + rng() % 8, m = 1 + rng() % 8, hi = (t % 3 == 0) ? 1 : 201;
        vector<vector<int>> g(n, vector<int>(m));
        for (auto& row : g)
            for (int& x : row) x = rng() % hi;
        check(s, g, brute(g, 0, 0), "small random grid");
    }
    cout << tested << " grids: " << (failed ? "some FAILED" : "all match the reference") << endl;
    return failed != 0;
}
