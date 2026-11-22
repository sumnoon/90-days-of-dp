// Week 6 Sunday stretch: LC 354 Russian Doll Envelopes (sort, then LIS on heights in O(n log n))
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });

        vector<int> memo;

        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(memo.begin(), memo.end(), envelopes[i][1]);
            if (it == memo.end()) {
                memo.push_back(envelopes[i][1]);
            } else {
                *it = envelopes[i][1];
            }
        }

        return memo.size();
    }
};

// Reference: O(n^2) table over envelopes sorted by width, checking both dimensions directly.
int reference(vector<vector<int>> e) {
    sort(e.begin(), e.end());
    vector<int> best(e.size(), 1);
    int ans = 0;
    for (size_t i = 0; i < e.size(); ++i) {
        for (size_t j = 0; j < i; ++j)
            if (e[j][0] < e[i][0] && e[j][1] < e[i][1]) best[i] = max(best[i], best[j] + 1);
        ans = max(ans, best[i]);
    }
    return ans;
}

int main() {
    vector<vector<vector<int>>> tests = {{{5, 4}, {6, 4}, {6, 7}, {2, 3}}, {{1, 1}, {1, 1}, {1, 1}}, {{1, 1}},
                                         {{1, 2}, {1, 3}, {1, 4}}, {{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}},
                                         {{1, 3}, {3, 5}, {6, 7}, {6, 8}, {8, 4}, {9, 5}}};
    mt19937 rng(354);
    for (int t = 0; t < 3000; ++t) {                   // random, 1..30 envelopes with sides 1..8 (many equal widths)
        vector<vector<int>> e(1 + rng() % 30);
        for (auto& v : e) v = {1 + (int)(rng() % 8), 1 + (int)(rng() % 8)};
        tests.push_back(e);
    }
    int failed = 0;
    for (auto& e : tests) {
        auto copy = e;                                 // maxEnvelopes sorts its input
        if (Solution().maxEnvelopes(copy) != reference(e)) { ++failed; cout << "FAIL on " << e.size() << " envelopes" << endl; }
    }
    vector<vector<int>> big(100000);                   // LeetCode's limits: 100,000 envelopes; the O(n^2) reference would take too long
    for (int i = 0; i < 100000; ++i) big[i] = {i + 1, i + 1};
    shuffle(big.begin(), big.end(), rng);
    auto t0 = chrono::steady_clock::now();
    int got = Solution().maxEnvelopes(big);
    auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
    if (got != 100000) { ++failed; cout << "FAIL on 100,000 nested envelopes" << endl; }
    cout << tests.size() << " cases (6 fixed + 3000 random): " << (failed ? "some FAILED" : "all match the reference")
         << "; 100,000 nested envelopes in " << ms << " ms" << endl;
    return failed != 0;
}
