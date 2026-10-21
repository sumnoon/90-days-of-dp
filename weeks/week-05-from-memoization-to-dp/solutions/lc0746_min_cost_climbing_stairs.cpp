// Week 5 Wednesday: LC 746 Min Cost Climbing Stairs (memoized, top-down)
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> memo;
    int func(int idx, vector<int>& cost) {
        if (idx >= cost.size()) return 0;

        if (memo[idx] != -1) return memo[idx];

        return memo[idx] = cost[idx] + min(func(idx + 1, cost), func(idx + 2, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memo.resize(n + 1, -1);
        return min(func(0, cost), func(1, cost));
    }
};

// Reference: try every path with no cache (exponential, small inputs only).
int brute(const vector<int>& c, int i) {
    if (i >= (int)c.size()) return 0;
    return c[i] + min(brute(c, i + 1), brute(c, i + 2));
}

int main() {
    vector<vector<int>> fixed = {{10, 15, 20}, {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, {0, 0}, {5, 3}, {999, 999}, {0, 0, 0, 0}};
    vector<int> want = {15, 6, 0, 3, 999, 0};
    int failed = 0;
    for (size_t t = 0; t < fixed.size(); ++t) {
        int got = Solution().minCostClimbingStairs(fixed[t]);
        cout << (got == want[t] ? "ok   " : "FAIL ") << "example " << t << " -> " << got << endl;
        failed += got != want[t];
    }
    mt19937 rng(746);
    for (int t = 0; t < 500; ++t) {                     // random, 2..22 steps, costs 0..999
        vector<int> c(2 + rng() % 21);
        for (int& x : c) x = rng() % 1000;
        int w = min(brute(c, 0), brute(c, 1));
        if (Solution().minCostClimbingStairs(c) != w) { ++failed; cout << "FAIL random " << t << endl; }
    }
    cout << "500 random arrays: " << (failed ? "some FAILED" : "all match the brute force") << endl;

    vector<int> big(1000, 999);                         // LeetCode's limit: 1000 steps
    auto t0 = chrono::steady_clock::now();
    int r = Solution().minCostClimbingStairs(big);
    auto us = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - t0).count();
    cout << "1000 steps of cost 999: " << r << " in " << us << " us" << endl;
    return failed != 0;
}
