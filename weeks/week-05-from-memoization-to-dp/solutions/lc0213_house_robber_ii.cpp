// Week 5 Saturday: LC 213 House Robber II (houses in a circle)
#include <algorithm>
#include <cstring>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[101];
    int calc(int st, int en, vector<int>& nums) {
        if (st > en) {
            return 0;
        }

        if (memo[st] != -1) {
            return memo[st];
        }

        return memo[st] = max(calc(st + 2, en, nums) + nums[st], calc(st + 1, en, nums));
    }
    int calcMemo(int st, int en, vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return calc(st, en, nums);
    }

    int calcConst(int st, int en, vector<int>& nums) {
        int prev = 0;
        int cur = nums[st];
        int next = 0;

        for (int i = st + 1; i < en; ++i) {
            next = max(prev + nums[i], cur);
            prev = cur;
            cur = next;
        }

        return cur;
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int n = nums.size();

        int first = calcConst(0, n - 1, nums);

        int second = calcConst(1, n, nums);

        return max(first, second);
    }
};

// Reference: every set of houses with no two next to each other, first and last counting as neighbours.
int brute(const vector<int>& a) {
    int n = a.size(), best = 0;
    for (int m = 0; m < (1 << n); ++m) {
        if (m & (m >> 1)) continue;
        if (n > 1 && (m & 1) && (m >> (n - 1) & 1)) continue;
        int s = 0;
        for (int i = 0; i < n; ++i) if (m >> i & 1) s += a[i];
        best = max(best, s);
    }
    return best;
}

int main() {
    vector<vector<int>> tests = {{2, 3, 2}, {1, 2, 3, 1}, {1, 2, 3}, {5}, {0}, {1, 2}, {2, 1}, {9, 1, 1, 9}, {200, 3, 140, 20, 10}};
    mt19937 rng(213);
    for (int t = 0; t < 500; ++t) {                    // random, 1..16 houses, 0..1000 each
        vector<int> a(1 + rng() % 16);
        for (int& x : a) x = rng() % 1001;
        tests.push_back(a);
    }
    int failed = 0;
    for (auto& a : tests) {
        int n = a.size(), want = brute(a);
        int got = Solution().rob(a);
        Solution s;                                    // the memoized version, same two ranges (inclusive ends)
        int memo = n == 1 ? a[0] : max(s.calcMemo(0, n - 2, a), s.calcMemo(1, n - 1, a));
        if (got != want || memo != want) { ++failed; cout << "FAIL on " << n << " houses" << endl; }
    }
    cout << tests.size() << " arrays (9 fixed + 500 random): "
         << (failed ? "some FAILED" : "rob() and the memoized version both match the brute force") << endl;
    return failed != 0;
}
