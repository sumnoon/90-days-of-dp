// Week 6 Saturday: LC 300 Longest Increasing Subsequence, two O(n^2) versions and O(n log n)
// Every version takes just nums and return the answer.
#include <algorithm>
#include <cstring>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[2510][2510];
    // 1. Memoized: calc(idx, prev) = longest increasing subsequence of nums[idx..] whose
    //    elements are all above nums[prev] (prev = -1: no element taken yet).
    int calc(int idx, int prev, int n, const vector<int>& nums) {
        if (idx == nums.size()) {
            return 0;
        }

        if (memo[idx][prev + 1] != -1) return memo[idx][prev + 1];

        int exclude = calc(idx + 1, prev, n, nums);
        int include = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            include = 1 + calc(idx + 1, idx, n, nums);
        }

        return memo[idx][prev + 1] = max(include, exclude);
    }
    int lengthOfLISMemo(vector<int>& nums) {
        int n = nums.size();
        memset(memo, -1, sizeof(memo));
        int ans = calc(0, -1, n, nums);
        return ans;
    }

    // 2. Table: memo[i] = length of the longest increasing subsequence that ends at i.
    int lengthOfLISTable(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> memo(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
            ans = max(ans, memo[i]);
        }
        return ans;
    }

    // 3. O(n log n): memo[k] = the smallest value that can end an increasing subsequence of length k + 1.
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> memo;
        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(memo.begin(), memo.end(), nums[i]) - memo.begin();
            if (pos == memo.size()) {
                memo.push_back(nums[i]);
            } else {
                memo[pos] = nums[i];
            }
        }
        return memo.size();
    }
};

// Reference: try every subsequence (n <= 16).
int brute(const vector<int>& a) {
    int n = a.size(), best = 0;
    for (int m = 1; m < (1 << n); ++m) {
        int len = 0, last = 0;
        bool ok = true;
        for (int i = 0; i < n && ok; ++i)
            if (m >> i & 1) {
                if (len && a[i] <= last) ok = false;
                last = a[i], ++len;
            }
        if (ok) best = max(best, len);
    }
    return best;
}

int main() {
    vector<vector<int>> tests = {{10, 9, 2, 5, 3, 7, 101, 18},
                                 {0, 1, 0, 3, 2, 3},
                                 {7, 7, 7, 7, 7, 7, 7},
                                 {5},
                                 {1, 2, 3, 4},
                                 {4, 3, 2, 1},
                                 {-10000, 10000},
                                 {3, 1, 2, 1, 2, 3}};
    mt19937 rng(300);
    for (int t = 0; t < 300; ++t) {  // random, 1..16 numbers from -5..5 (many repeats)
        vector<int> a(1 + rng() % 16);
        for (int& x : a) x = (int)(rng() % 11) - 5;
        tests.push_back(a);
    }
    auto s = make_unique<Solution>();  // memo is 2510 x 2510 ints (25 MB): keep it off the stack
    int failed = 0;
    for (auto& a : tests) {
        int want = brute(a);
        if (s->lengthOfLISMemo(a) != want || s->lengthOfLISTable(a) != want ||
            s->lengthOfLIS(a) != want) {
            ++failed;
            cout << "FAIL on " << a.size() << " numbers" << endl;
        }
    }
    // LeetCode's limits: 2,500 numbers. Too long for the brute force, so the three versions
    // check each other.
    vector<int> up(2500), rnd(2500);
    for (int i = 0; i < 2500; ++i) up[i] = i - 1250, rnd[i] = (int)(rng() % 20001) - 10000;
    if (s->lengthOfLISMemo(up) != 2500 || s->lengthOfLISTable(up) != 2500 ||
        s->lengthOfLIS(up) != 2500) {
        ++failed;
        cout << "FAIL on 2,500 increasing" << endl;
    }
    int a = s->lengthOfLISMemo(rnd), t = s->lengthOfLISTable(rnd), b = s->lengthOfLIS(rnd);
    if (a != b || t != b) {
        ++failed;
        cout << "FAIL: versions disagree on 2,500 random" << endl;
    }
    cout << tests.size() << " arrays (8 fixed + 300 random) and 2 of 2,500 (random LIS " << b
         << "): " << (failed ? "some FAILED" : "all three versions match") << endl;
    return failed != 0;
}
