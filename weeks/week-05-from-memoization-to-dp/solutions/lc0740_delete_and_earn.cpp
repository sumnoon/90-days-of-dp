// Week 5 Friday: LC 740 Delete and Earn (sort, then memoized take / skip)
// The recursion goes up to 20,000 calls deep, more than Windows' 1 MB default
// stack holds at -O0. To run the LeetCode-size tests, build with a bigger stack:
//   g++ -std=c++20 -Wl,--stack,8388608 -o t lc0740_delete_and_earn.cpp && ./t --limits
#include <algorithm>
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[20001];
    int calcMemo(int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            return 0;
        }

        if (memo[idx] != -1) {
            return memo[idx];
        }

        int cur = nums[idx];
        int sum = nums[idx];
        int ind = idx + 1;

        while (ind < nums.size() && nums[ind] == cur) {
            sum += nums[idx];
            ind++;
        }

        while (ind < nums.size() && nums[ind] == cur + 1) {
            ind++;
        }

        return memo[idx] = max(sum + calcMemo(ind, nums), calcMemo(idx + 1, nums));
    }
    int calcRecurse(int idx, vector<int>& nums) {
        if (idx >= nums.size()) {
            return 0;
        }

        int cur = nums[idx];
        int sum = nums[idx];
        int ind = idx + 1;

        while (ind < nums.size() && nums[ind] == cur) {
            sum += nums[idx];
            ind++;
        }

        while (ind < nums.size() && nums[ind] == cur + 1) {
            ind++;
        }

        return max(sum + calcRecurse(ind, nums), calcRecurse(idx + 1, nums));
    }
    int deleteAndEarn(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        sort(nums.begin(), nums.end());
        return calcMemo(0, nums);
    }
};


// Reference: House Robber over the values. points[v] = v * (how many v's).
int reference(const vector<int>& nums) {
    vector<int> pts(10001, 0);
    for (int x : nums) pts[x] += x;
    int prev = 0, cur = 0;
    for (int v = 1; v <= 10000; ++v) { int nx = max(cur, prev + pts[v]); prev = cur; cur = nx; }
    return cur;
}

int main(int argc, char** argv) {
    vector<vector<int>> tests = {{3, 4, 2}, {2, 2, 3, 3, 3, 4}, {1}, {1, 1, 1}, {1, 2}, {1, 3}, {8, 10, 4, 9, 1, 3, 5, 9, 4, 10}};
    mt19937 rng(740);
    for (int t = 0; t < 500; ++t) {                    // random, up to 30 numbers from a small range
        vector<int> a(1 + rng() % 30);
        int hi = 2 + rng() % 12;
        for (int& x : a) x = 1 + rng() % hi;
        tests.push_back(a);
    }
    int failed = 0;
    for (auto a : tests) {
        int want = reference(a);
        int got = Solution().deleteAndEarn(a);
        vector<int> b = a;
        sort(b.begin(), b.end());
        int plain = b.size() <= 20 ? Solution().calcRecurse(0, b) : want;
        if (got != want || plain != want) { ++failed; cout << "FAIL on " << a.size() << " numbers" << endl; }
    }
    cout << tests.size() << " arrays (7 fixed + 500 random): " << (failed ? "some FAILED" : "memoized and plain both match the reference") << endl;

    if (argc < 2 || string(argv[1]) != "--limits") return failed != 0;
    for (int kind = 0; kind < 2; ++kind) {             // LeetCode's limits: 20,000 numbers, each up to 10,000
        vector<int> a(20000);
        for (int i = 0; i < 20000; ++i) a[i] = kind == 0 ? 1 + rng() % 10000 : 10000;
        int want = reference(a);
        auto t0 = chrono::steady_clock::now();
        int got = Solution().deleteAndEarn(a);
        auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
        cout << (kind == 0 ? "20,000 random numbers: " : "20,000 copies of 10,000: ") << got
             << (got == want ? " (correct)" : " WRONG") << " in " << ms << " ms" << endl;
        failed += got != want;
    }
    return failed != 0;
}
