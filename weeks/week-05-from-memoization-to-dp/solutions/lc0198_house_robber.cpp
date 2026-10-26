// Week 5 Thursday: LC 198 House Robber in four versions
// (plain recursion, memoized, table, O(1) space; rob() is the one submitted)
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> memo;
    int func(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            return 0;
        }

        return max(func(nums, idx + 2) + nums[idx], func(nums, idx + 1));
    }

    int func_memo(vector<int>& nums, int idx) {
        if (idx >= nums.size()) {
            return 0;
        }

        if (memo[idx] != -1) return memo[idx];

        return memo[idx] = max(func_memo(nums, idx + 2) + nums[idx], func_memo(nums, idx + 1));
    }

    int bottomO_up(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n + 1);
        memo[0] = 0;
        memo[1] = nums[0];

        for (int i = 1; i < n; ++i) {
            memo[i + 1] = max(memo[i - 1] + nums[i], memo[i]);
        }

        return memo[n];
    }
    int rob(vector<int>& nums) {
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
};


// Reference: try every set of houses with no two next to each other.
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
    mt19937 rng(198);
    for (int t = 0; t < 500; ++t) {                    // random, 1..16 houses, 0..400 each
        vector<int> a(1 + rng() % 16);
        for (int& x : a) x = rng() % 401;
        tests.push_back(a);
    }
    int failed = 0;
    for (auto& a : tests) {
        int want = brute(a);
        Solution s;
        s.memo.assign(a.size(), -1);                   // func_memo needs the cache set up first
        int got[4] = {s.func(a, 0), s.func_memo(a, 0), Solution().bottomO_up(a), Solution().rob(a)};
        for (int v = 0; v < 4; ++v)
            if (got[v] != want) { ++failed; cout << "FAIL version " << v + 1 << " on " << a.size() << " houses" << endl; }
    }
    cout << tests.size() << " arrays (8 fixed + 500 random), all four versions: "
         << (failed ? "some FAILED" : "all match the brute force") << endl;

    vector<int> big(100, 400);                         // LeetCode's limit: 100 houses
    for (int n : {30, 40}) {
        vector<int> a(big.begin(), big.begin() + n);
        auto t0 = chrono::steady_clock::now();
        int r = Solution().func(a, 0);
        auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
        cout << "plain recursion, " << n << " houses: " << r << " in " << ms << " ms" << endl;
    }
    cout << "rob(), 100 houses: " << Solution().rob(big) << endl;
    return failed != 0;
}
