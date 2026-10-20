// Month 1 checkpoint: LC 241 with a cache on (start, end)
#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> memo[20][20];
    vector<int> func(const string& expression, int start, int end) {
        if (!memo[start][end].empty()) {
            return memo[start][end];
        }

        vector<int> results;

        for (int i = start; i <= end; ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                const vector<int>& left = func(expression, start, i - 1);
                const vector<int>& right = func(expression, i + 1, end);

                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        if (c == '+')
                            results.push_back(left[j] + right[k]);
                        else if (c == '-')
                            results.push_back(left[j] - right[k]);
                        else if (c == '*')
                            results.push_back(left[j] * right[k]);
                    }
                }
            }
        }

        if (results.empty()) {
            int ret = 0;
            for (int i = start; i <= end; ++i) {
                ret = ret * 10 + (expression[i] - '0');
            }
            results.push_back(ret);
        }

        return memo[start][end] = move(results);
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j].clear();
            }
        }

        return func(expression, 0, n - 1);
    }
};

// --- local harness (LeetCode supplies these) ---

// Reference, built a different way: split into numbers and operators, then
// combine token ranges bottom-up (every way to place the last operator).
vector<int> by_ranges(const string& e) {
    vector<int> nums;
    vector<char> ops;
    int x = 0;
    for (char c : e) {
        if (isdigit(c)) x = x * 10 + (c - '0');
        else { nums.push_back(x); ops.push_back(c); x = 0; }
    }
    nums.push_back(x);
    int n = nums.size();
    vector<vector<vector<int>>> r(n, vector<vector<int>>(n));
    for (int i = 0; i < n; ++i) r[i][i] = {nums[i]};
    for (int len = 2; len <= n; ++len)
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k)
                for (int a : r[i][k]) for (int b : r[k + 1][j])
                    r[i][j].push_back(ops[k] == '+' ? a + b : ops[k] == '-' ? a - b : a * b);
        }
    return r[0][n - 1];
}

int main() {
    vector<string> inputs = {"2-1-1", "2*3-4*5", "7", "99", "1+2", "2*3*4", "10-5-2-1", "11*2-3+4*5-6"};
    mt19937 rng(241);
    for (int t = 0; t < 200; ++t) {          // random expressions, up to 20 characters as LeetCode allows
        string e = to_string(rng() % 100);
        while (true) {
            string next = string(1, "+-*"[rng() % 3]) + to_string(rng() % 100);
            if (e.size() + next.size() > 20 || rng() % 5 == 0) break;
            e += next;
        }
        inputs.push_back(e);
    }
    int failed = 0, shown = 0;
    for (auto& e : inputs) {
        vector<int> got = Solution().diffWaysToCompute(e), want = by_ranges(e);
        sort(got.begin(), got.end());
        sort(want.begin(), want.end());
        bool ok = got == want;
        if (!ok) { ++failed; cout << "FAIL " << e << endl; }
        else if (shown++ < 6) {
            cout << "ok   " << e << " -> " << got.size() << " results:";
            if (got.size() <= 6) for (int v : got) cout << " " << v;
            cout << endl;
        }
    }
    cout << inputs.size() << " expressions (8 fixed + 200 random): " << (failed ? "some FAILED" : "all match, as multisets") << endl;
    return failed != 0;
}
