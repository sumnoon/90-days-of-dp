// Week 6 Saturday: LC 673 Number of Longest Increasing Subsequence (LIS ending at i, plus a count)
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[2010], count[2010];
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, cnt = 0;

        for (int i = 0; i <= n; ++i) {
            memo[i] = 1;
            count[i] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (memo[j] + 1 > memo[i]) {
                        memo[i] = memo[j] + 1;
                        count[i] = count[j];
                    } else if (memo[j] + 1 == memo[i]) {
                        memo[i] = memo[i];
                        count[i] += count[j];
                    }
                }
            }
            ans = max(ans, memo[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (memo[i] == ans) {
                cnt += count[i];
            }
        }

        return cnt;
    }
};

// Reference: try every subsequence (n <= 16) and count the increasing ones of the greatest length.
int brute(const vector<int>& a) {
    int n = a.size(), best = 0, count = 0;
    for (int m = 1; m < (1 << n); ++m) {
        int len = 0, last = 0;
        bool ok = true;
        for (int i = 0; i < n && ok; ++i)
            if (m >> i & 1) {
                if (len && a[i] <= last) ok = false;
                last = a[i], ++len;
            }
        if (!ok) continue;
        if (len > best) best = len, count = 0;
        if (len == best) ++count;
    }
    return count;
}

int main() {
    vector<vector<int>> tests = {{1, 3, 5, 4, 7}, {2, 2, 2, 2, 2}, {1}, {1, 2}, {2, 1}, {1, 2, 4, 3, 5, 4, 7, 2},
                                 {3, 1, 2}, {1, 1, 2, 2}};
    mt19937 rng(673);
    for (int t = 0; t < 2000; ++t) {                   // random, 1..16 numbers from -4..4 (many repeats)
        vector<int> a(1 + rng() % 16);
        for (int& x : a) x = (int)(rng() % 9) - 4;
        tests.push_back(a);
    }
    int failed = 0;
    for (auto& a : tests) {
        if (Solution().findNumberOfLIS(a) != brute(a)) { ++failed; cout << "FAIL on " << a.size() << " numbers" << endl; }
    }
    // LeetCode's limits: 2,000 numbers. Pairs (2k, 2k - 1) give 2^1000 longest ones, far past int, so
    // this uses 30 pairs (2^30 of length 30) followed by 1,940 decreasing numbers that add nothing longer.
    vector<int> big;
    for (int k = 1; k <= 30; ++k) big.push_back(2 * k), big.push_back(2 * k - 1);
    for (int v = 0; big.size() < 2000; --v) big.push_back(v);
    if (Solution().findNumberOfLIS(big) != (1 << 30)) { ++failed; cout << "FAIL on 2,000 numbers" << endl; }
    cout << tests.size() << " arrays (8 fixed + 2000 random) and one of 2,000: "
         << (failed ? "some FAILED" : "all match the brute force") << endl;
    return failed != 0;
}
