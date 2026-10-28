// Week 5 checkpoint: LC 198 House Robber, all four versions from memory (Wed 28 Oct)
#include <algorithm>
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[101];
    int calcRecurse(int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            return 0;
        }

        return max(calcRecurse(idx + 2, nums) + nums[idx], calcRecurse(idx + 1, nums));
    }
    int calcMemo(int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            return 0;
        }

        if (memo[idx] != -1) {
            return memo[idx];
        }

        return memo[idx] = max(calcMemo(idx + 2, nums) + nums[idx], calcMemo(idx + 1, nums));
    }

    int calcTab(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }

        return memo[n - 1];
    }
    int constMemo(vector<int>& nums) {
        int n = nums.size();

        int prev = 0;
        int cur = nums[0];
        int next = 0;

        for (int i = 1; i < n; ++i) {
            next = max(prev + nums[i], cur);
            prev = cur;
            cur = next;
        }

        return cur;
    }
    int rob(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return calcTab(nums);
    }
};

// Reference: every set of houses with no two next to each other.
int brute(const vector<int>& a) {
    int n = a.size(), best = 0;
    for (int m = 0; m < (1 << n); ++m) {
        if (m & (m >> 1)) continue;
        int s = 0;
        for (int i = 0; i < n; ++i) if (m >> i & 1) s += a[i];
        best = max(best, s);
    }
    return best;
}

int main() {
    vector<vector<int>> tests = {{1, 2, 3, 1}, {2, 7, 9, 3, 1}, {5}, {0}, {2, 1}, {1, 2}, {2, 1, 1, 2}, {400, 0, 0, 400}};
    mt19937 rng(5);
    for (int t = 0; t < 500; ++t) {                    // random, 1..16 houses, 0..400 each
        vector<int> a(1 + rng() % 16);
        for (int& x : a) x = rng() % 401;
        tests.push_back(a);
    }
    int failed = 0;
    for (auto& a : tests) {
        int want = brute(a);
        Solution s;
        memset(s.memo, -1, sizeof(s.memo));            // calcMemo needs the cache cleared first
        int got[4] = {s.calcRecurse(0, a), s.calcMemo(0, a), Solution().rob(a), Solution().constMemo(a)};
        for (int v = 0; v < 4; ++v)
            if (got[v] != want) { ++failed; cout << "FAIL version " << v + 1 << " on " << a.size() << " houses" << endl; }
    }
    cout << tests.size() << " arrays (8 fixed + 500 random), all four versions: "
         << (failed ? "some FAILED" : "all match the brute force") << endl;

    for (int n : {40, 100}) {                          // the cache is what makes this instant
        vector<int> a(n, 400);
        Solution s;
        memset(s.memo, -1, sizeof(s.memo));
        auto t0 = chrono::steady_clock::now();
        int r = s.calcMemo(0, a);
        auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
        cout << "calcMemo, " << n << " houses: " << r << " in " << ms << " ms" << endl;
    }
    return failed != 0;
}
