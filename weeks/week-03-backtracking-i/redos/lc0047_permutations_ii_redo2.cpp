// Week 3 redo 2, from memory (Wed Nov 11, a month after redo 1): LC 47 Permutations II, with used[i - 1]
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> ans;
    vector<bool> used;
    void backtrack(int n, vector<int>& nums, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1]) continue;
            if (used[i] == false) {
                used[i] = true;
                cur.push_back(nums[i]);
                backtrack(n, nums, cur);
                cur.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        used.resize(n + 1, false);
        vector<int> cur;
        sort(nums.begin(), nums.end());

        backtrack(n, nums, cur);

        return ans;
    }
};

void print(const vector<vector<int>>& v) {
    for (auto& p : v) { cout << " ["; for (size_t i = 0; i < p.size(); ++i) cout << (i ? "," : "") << p[i]; cout << "]"; }
}

// Reference: std::next_permutation from the sorted order visits each distinct ordering once.
vector<vector<int>> by_next_permutation(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> out;
    do out.push_back(nums); while (next_permutation(nums.begin(), nums.end()));
    return out;
}

int main() {
    vector<vector<int>> inputs = {
        {1, 1, 2},                  // LeetCode example 1
        {1, 2, 3},                  // LeetCode example 2: no duplicates
        {1, 1, 1},
        {2, 1, 2, 1},
        {3, 3, 0, 3},
        {1, 1, 2, 2, 3, 3, 1, 2},   // LeetCode's largest length: 8 numbers
    };
    int failed = 0;
    for (auto nums : inputs) {
        vector<vector<int>> got = Solution().permuteUnique(nums);   // a fresh object per call
        set<vector<int>> uniq(got.begin(), got.end());
        vector<vector<int>> ref = by_next_permutation(nums);
        bool ok = got.size() == ref.size() && uniq.size() == got.size() && uniq == set<vector<int>>(ref.begin(), ref.end());
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << nums.size() << " numbers -> " << got.size() << " permutations";
        if (got.size() <= 6) { cout << ":"; print(got); }
        cout << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
