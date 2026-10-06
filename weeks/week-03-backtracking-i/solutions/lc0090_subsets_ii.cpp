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
            if (i != idx && nums[i] == nums[i - 1]) {
                continue;
            }
            cur.push_back(nums[i]);
            backtrack(i + 1, cur, nums);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(), nums.end());
        backtrack(0, cur, nums);
        return ans;
    }
};

void print(const vector<vector<int>>& v) {
    for (auto& p : v) { cout << " ["; for (size_t i = 0; i < p.size(); ++i) cout << (i ? "," : "") << p[i]; cout << "]"; }
}

// Reference: every bitmask subset, sorted, kept once.
set<vector<int>> by_bitmask(vector<int> nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> out;
    for (int m = 0; m < (1 << nums.size()); ++m) {
        vector<int> s;
        for (size_t i = 0; i < nums.size(); ++i) if (m >> i & 1) s.push_back(nums[i]);
        out.insert(s);
    }
    return out;
}

int main() {
    vector<vector<int>> inputs = {
        {1, 2, 2},                          // LeetCode example 1
        {0},                                // LeetCode example 2
        {2, 2, 2},
        {4, 4, 4, 1, 4},                    // unsorted, with a run of four
        {3, 1, 3, 2, 1, 3, 2, 1, 2, 3},     // 10 numbers, three values repeated
    };
    int failed = 0;
    for (auto nums : inputs) {
        vector<vector<int>> got = Solution().subsetsWithDup(nums);   // a fresh object per call
        set<vector<int>> uniq;
        for (auto s : got) { sort(s.begin(), s.end()); uniq.insert(s); }
        set<vector<int>> ref = by_bitmask(nums);
        bool ok = uniq.size() == got.size() && uniq == ref;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << nums.size() << " numbers -> " << got.size() << " subsets";
        if (got.size() <= 8) { cout << ":"; print(got); }
        cout << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
