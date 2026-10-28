// Week 6 Monday: LC 53 Maximum Subarray (Kadane's algorithm as a DP, plus divide and conquer)
// Every version takes just `nums` and returns the answer: no setup needed by the caller.
#include <algorithm>
#include <chrono>
#include <climits>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> memo;
    vector<int> visited;
    int global_max;

    // 1. Plain recursion: calcRecurse(idx) = best sum ending at idx; global_max = best anywhere.
    int calcRecurse(int idx, vector<int>& nums) {
        if (idx == 0) {
            global_max = max(global_max, nums[0]);
            return nums[0];
        }

        int best = max(nums[idx], nums[idx] + calcRecurse(idx - 1, nums));

        global_max = max(global_max, best);

        return best;
    }
    int recurse(vector<int>& nums) {
        global_max = INT_MIN;
        calcRecurse(nums.size() - 1, nums);
        return global_max;
    }

    // 2. Memoized: same state; the answer is the best over every idx.
    int calcMemo(int idx, vector<int>& nums) {
        if (idx == 0) {
            return nums[0];
        }
        if (visited[idx]) return memo[idx];
        visited[idx] = true;
        return memo[idx] = max(nums[idx], nums[idx] + calcMemo(idx - 1, nums));
    }
    int memoized(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, 0);
        visited.assign(n, 0);
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) ans = max(ans, calcMemo(i, nums));
        return ans;
    }

    // 3. Table: memo[i] = max(nums[i], nums[i] + memo[i - 1]).
    int calcTab(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, 0);
        memo[0] = nums[0];
        int ans = memo[0];

        for (int i = 1; i < n; ++i) {
            memo[i] = max(nums[i], nums[i] + memo[i - 1]);
            ans = max(ans, memo[i]);
        }
        return ans;
    }

    // 4. Kadane: the table kept in one variable.
    int kadane(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;

        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }

        return ans;
    }

    // 5. Divide and conquer: best in the left half, the right half, or crossing mid.
    int divideAndConquire(int left, int right, vector<int>& nums) {
        if (left == right) {
            return nums[left];
        }
        int mid = left + (right - left) / 2;
        int leftVal = divideAndConquire(left, mid, nums);
        int rightVal = divideAndConquire(mid + 1, right, nums);

        int leftPrefixVal = INT_MIN, sum = 0;

        for (int i = mid; i >= left; --i) {
            sum += nums[i];
            leftPrefixVal = max(leftPrefixVal, sum);
        }

        int rightPrefixVal = INT_MIN;
        sum = 0;

        for (int i = mid + 1; i <= right; ++i) {
            sum += nums[i];
            rightPrefixVal = max(rightPrefixVal, sum);
        }

        int cross_max = leftPrefixVal + rightPrefixVal;
        return max({cross_max, leftVal, rightVal});
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = divideAndConquire(0, n - 1, nums);
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
    Solution s;
    int failed = 0;
    for (auto& a : tests) {
        int want = brute(a);
        if (s.recurse(a) != want || s.memoized(a) != want || s.calcTab(a) != want || s.kadane(a) != want ||
            s.maxSubArray(a) != want) {
            ++failed;
            cout << "FAIL on " << a.size() << " numbers" << endl;
        }
    }
    // LeetCode's limits. recurse and memoized are left out: 100,000 calls deep overflows Windows' 1 MB stack.
    vector<int> neg(100000, -10000), mixed(100000);
    for (int& x : mixed) x = (int)(rng() % 20001) - 10000;
    for (auto* a : {&neg, &mixed}) {
        int want = s.kadane(*a);
        auto t0 = chrono::steady_clock::now();
        int dc = s.maxSubArray(*a);
        auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
        if (s.calcTab(*a) != want || dc != want) { ++failed; cout << "FAIL on 100,000 numbers" << endl; }
        cout << "100,000 numbers: answer " << want << ", divide and conquer took " << ms << " ms" << endl;
    }
    cout << tests.size() << " arrays (7 fixed + 2000 random): "
         << (failed ? "some FAILED" : "all five versions match the brute force") << endl;
    return failed != 0;
}
