// Week 6 Tuesday: LC 152 Maximum Product Subarray (prefix and suffix products)
#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int l = 1, r = 1;
        int n = nums.size();
        int res = nums[0];
        for (int i = 0; i < n; ++i) {
            l *= nums[i];
            r *= nums[n - i - 1];
            res = max(res, max(l, r));
            if (l == 0) l = 1;
            if (r == 0) r = 1;
        }
        return res;
    }
};

// Reference: try every subarray, in long long.
long long brute(const vector<int>& a) {
    long long best = LLONG_MIN;
    for (size_t i = 0; i < a.size(); ++i) {
        long long p = 1;
        for (size_t j = i; j < a.size(); ++j) best = max(best, p *= a[j]);
    }
    return best;
}

int main() {
    vector<vector<int>> tests = {{2, 3, -2, 4}, {-2, 0, -1}, {-2}, {0}, {-2, 3, -4}, {-1, -1}, {0, 2},
                                 {2, -5, -2, -4, 3}, {-3, 0, -2, 0, -1}, {3, -1, 4}};
    mt19937 rng(152);
    for (int t = 0; t < 5000; ++t) {                   // random, 1..12 numbers, -4..4 each
        vector<int> a(1 + rng() % 12);
        for (int& x : a) x = (int)(rng() % 9) - 4;
        tests.push_back(a);
    }
    vector<int> big(20000, 1);                         // LeetCode's limits: 20,000 numbers
    for (int i = 0; i < 20000; i += 7) big[i] = -1;
    big[100] = 10, big[5000] = 0, big[12345] = -10;
    tests.push_back(big);
    int failed = 0;
    for (auto& a : tests) {
        long long want = brute(a);
        if (Solution().maxProduct(a) != want) { ++failed; cout << "FAIL on " << a.size() << " numbers" << endl; }
    }
    cout << tests.size() << " arrays (10 fixed + 5000 random + one of 20,000): "
         << (failed ? "some FAILED" : "all match the brute force") << endl;
    return failed != 0;
}
