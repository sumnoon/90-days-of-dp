// Week 6 Monday: LC 53 Maximum Subarray (Kadane's algorithm as a DP)
#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[100010];
    vector<int> visited;
    int global_max;
    int calcRecurse(int idx, vector<int>& nums) {
        if (idx == 0) {
            global_max = max(global_max, nums[0]);
            return nums[0];
        }

        int best = max(nums[idx], nums[idx] + calcRecurse(idx - 1, nums));

        global_max = max(global_max, best);

        return best;
    }
    int calcMemo(int idx, vector<int>& nums) {
        if (idx == 0) {
            return nums[0];
        }
        if (visited[idx]) return memo[idx];
        visited[idx] = true;
        return memo[idx] = max(nums[idx], nums[idx] + calcMemo(idx - 1, nums));
    }
    int calcTab(vector<int>& nums) {
        int n = nums.size();
        memo[0] = nums[0];
        int ans = memo[0];

        for (int i = 1; i < n; ++i) {
            memo[i] = max(nums[i], nums[i] + memo[i - 1]);
            ans = max(ans, memo[i]);
        }
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
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
    auto s = make_unique<Solution>();                  // 400 KB of memo: keep it off the stack
    int failed = 0;
    for (auto& a : tests) {
        int n = a.size(), want = brute(a);
        s->global_max = INT_MIN;
        s->calcRecurse(n - 1, a);
        int rec = s->global_max;
        s->visited.assign(n, 0);                       // calcMemo returns the best ending at idx, so try every idx
        int memo = INT_MIN;
        for (int i = 0; i < n; ++i) memo = max(memo, s->calcMemo(i, a));
        int tab = s->calcTab(a), kadane = s->maxSubArray(a);
        if (rec != want || memo != want || tab != want || kadane != want) { ++failed; cout << "FAIL on " << n << " numbers" << endl; }
    }
    vector<int> big(100000, -10000);                   // LeetCode's limits, every number negative
    if (s->maxSubArray(big) != -10000 || s->calcTab(big) != -10000) { ++failed; cout << "FAIL on 100,000 negatives" << endl; }
    cout << tests.size() << " arrays (7 fixed + 2000 random) and 100,000 negatives: "
         << (failed ? "some FAILED" : "all four versions match the brute force") << endl;
    return failed != 0;
}
