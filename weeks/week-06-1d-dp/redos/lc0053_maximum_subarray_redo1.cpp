// Week 6 redo 1, from memory (Tue Nov 17): LC 53 Maximum Subarray, the recursion with calc(idx) = best ending at idx
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[100010];
    bool visited[100010];

    // Recursion: calc(idx) = the largest sum of a subarray that ends exactly at idx.
    int calc(int idx, vector<int>& nums) {
        if (idx == 0) {
            return nums[0];
        }
        if (visited[idx] == true) return memo[idx];

        visited[idx] = true;

        return memo[idx] = max(nums[idx], nums[idx] + calc(idx - 1, nums));
    }
    int maxSubArray(vector<int>& nums) {
        memset(visited, false, sizeof(visited));
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, calc(i, nums));
        }
        return ans;
    }

    // Table, the same state filled left to right.
    int maxSubArrayTable(vector<int>& nums) {
        int sum = 0, ans = 0;
        memo[0] = nums[0];
        ans = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            memo[i] = max(nums[i], nums[i] + memo[i - 1]);
            ans = max(ans, memo[i]);
        }

        return ans;
    }
};

// Reference: try every subarray.
int brute(const vector<int>& a) {
    int best = INT_MIN;
    for (size_t i = 0; i < a.size(); ++i) {
        int s = 0;
        for (size_t j = i; j < a.size(); ++j) best = max(best, s += a[j]);
    }
    return best;
}

int main() {
    vector<vector<int>> tests = {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, {1}, {5, 4, -1, 7, 8}, {-1}, {-3, -1, -2}, {5, -10, 1}, {0, 0}};
    mt19937 rng(53);
    for (int t = 0; t < 2000; ++t) {                   // random, 1..12 numbers, -10..10 each
        vector<int> a(1 + rng() % 12);
        for (int& x : a) x = (int)(rng() % 21) - 10;
        tests.push_back(a);
    }
    vector<int> neg(100000, -10000), mixed(100000);    // LeetCode's limits
    for (int& x : mixed) x = (int)(rng() % 20001) - 10000;
    auto s = make_unique<Solution>();                  // memo and visited are 500 KB: keep them off the stack
    int failed = 0;
    for (auto& a : tests) {
        int want = brute(a);
        if (s->maxSubArray(a) != want || s->maxSubArrayTable(a) != want) { ++failed; cout << "FAIL on " << a.size() << " numbers" << endl; }
    }
    for (auto* a : {&neg, &mixed}) {                   // too long for the brute force: the two versions check each other
        int r = s->maxSubArray(*a);
        if (r != s->maxSubArrayTable(*a) || (a == &neg && r != -10000)) { ++failed; cout << "FAIL on 100,000 numbers" << endl; }
    }
    cout << tests.size() << " arrays (7 fixed + 2000 random) and 2 of 100,000: "
         << (failed ? "some FAILED" : "the recursion and the table both match") << endl;
    return failed != 0;
}
