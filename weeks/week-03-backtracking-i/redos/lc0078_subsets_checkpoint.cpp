// Week 3 checkpoint, timed and from memory: LC 78 Subsets
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int idx, vector<int>& cur, vector<int>& nums) {
        ans.push_back(cur);

        for (int i = idx; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(i + 1, cur, nums);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        backtrack(0, cur, nums);
        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

// Order doesn't matter in LC 78, so compare as a set of sorted subsets.
set<vector<int>> canon(vector<vector<int>> v) {
    for (auto& s : v) sort(s.begin(), s.end());
    return set<vector<int>>(v.begin(), v.end());
}

// Reference: subset k takes nums[i] exactly when bit i of k is set.
vector<vector<int>> by_bitmask(const vector<int>& nums) {
    vector<vector<int>> out;
    for (int k = 0; k < (1 << nums.size()); ++k) {
        vector<int> s;
        for (size_t i = 0; i < nums.size(); ++i) if (k >> i & 1) s.push_back(nums[i]);
        out.push_back(s);
    }
    return out;
}

int main() {
    vector<vector<int>> inputs = {
        {1, 2, 3},                         // LeetCode example 1
        {0},                               // LeetCode example 2
        {-1, 5},
        {4, 1, 0, -3, 9, 2, 7, 6, -5, 8},  // 10 numbers: LeetCode's largest, 1024 subsets
    };
    int failed = 0;
    for (auto& nums : inputs) {
        vector<vector<int>> got = Solution().subsets(nums);   // a fresh object per call, as LeetCode does
        size_t want = size_t(1) << nums.size();
        bool ok = got.size() == want && canon(got).size() == want && canon(got) == canon(by_bitmask(nums));
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << nums.size() << " numbers -> " << got.size() << " subsets" << endl;
    }

    vector<int> ex = {1, 2, 3};
    cout << "order for [1,2,3] (for loop from start):";
    for (auto& s : Solution().subsets(ex)) {
        cout << " [";
        for (size_t i = 0; i < s.size(); ++i) cout << (i ? "," : "") << s[i];
        cout << "]";
    }
    cout << endl;

    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
