#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> merge(vector<int>& a, vector<int>& b) {
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }
        int i = 0, j = 0;
        vector<int> ans;

        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                ans.push_back(a[i]);
                ++i;
            } else {
                ans.push_back(b[j]);
                ++j;
            }
        }

        while (i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        while (j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }

    vector<int> mergeSort(vector<int>& nums, int start, int end) {
        if (start == end) {
            return {nums[start]};
        }
        int mid = start + (end - start) / 2;
        vector<int> left = mergeSort(nums, start, mid);
        vector<int> right = mergeSort(nums, mid + 1, end);

        return merge(left, right);
    }
    vector<int> sortArray(vector<int>& nums) { return mergeSort(nums, 0, nums.size() - 1); }
};

// --- local harness (LeetCode supplies these) ---

int main() {
    vector<vector<int>> inputs = {
        {5, 2, 3, 1},                  // LeetCode example 1
        {5, 1, 1, 2, 0, 0},            // LeetCode example 2: duplicates
        {1},                           // one number
        {2, 1},
        {-3, 7, -3, 0, 50000, -50000}, // negatives and the value limits
        {9, 8, 7, 6, 5, 4, 3, 2, 1},   // reversed
        {1, 2, 3, 4, 5, 6},            // already sorted
    };
    mt19937 rng(912);
    for (int t = 0; t < 200; ++t) {
        vector<int> v(1 + rng() % 300);
        for (int& x : v) x = int(rng() % 21) - 10;     // small range: lots of duplicates
        inputs.push_back(v);
    }
    int failed = 0;
    for (auto& in : inputs) {
        vector<int> copy = in, want = in;
        sort(want.begin(), want.end());
        if (Solution().sortArray(copy) != want) ++failed;
    }
    cout << inputs.size() << " arrays (7 fixed + 200 random): " << (failed ? "some FAILED" : "all match std::sort") << endl;

    // LeetCode's largest input: 50,000 numbers in [-50000, 50000].
    vector<int> big(50000);
    for (int& x : big) x = int(rng() % 100001) - 50000;
    vector<int> want = big;
    sort(want.begin(), want.end());
    auto t0 = chrono::steady_clock::now();
    vector<int> got = Solution().sortArray(big);
    auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
    bool ok = got == want;
    if (!ok) ++failed;
    cout << (ok ? "ok   " : "FAIL ") << "50,000 numbers sorted in " << ms << " ms" << endl;

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
