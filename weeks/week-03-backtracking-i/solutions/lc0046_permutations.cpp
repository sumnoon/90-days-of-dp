#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> used;
    void backtrack(int idx, vector<int>& cur, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            backtrack(i, cur, nums);
            used[i] = false;
            cur.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        used.resize(nums.size(), false);
        backtrack(0, cur, nums);

        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

// Reference: std::next_permutation from the sorted order visits every ordering once.
vector<vector<int>> by_next_permutation(vector<int> nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> out;
    do out.push_back(nums); while (next_permutation(nums.begin(), nums.end()));
    return out;
}

int main() {
    vector<vector<int>> inputs = {
        {1, 2, 3},                     // LeetCode example 1
        {0, 1},                        // LeetCode example 2
        {1},                           // LeetCode example 3
        {3, -1, 7, 0},
        {6, 5, 4, 3, 2, 1},            // LeetCode's largest: 6 numbers, 720 permutations
    };
    int failed = 0;
    for (auto& nums : inputs) {
        vector<vector<int>> got = Solution().permute(nums);   // a fresh object per call
        set<vector<int>> uniq(got.begin(), got.end());
        vector<vector<int>> ref = by_next_permutation(nums);
        bool ok = got.size() == ref.size() && uniq.size() == got.size() && uniq == set<vector<int>>(ref.begin(), ref.end());
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << nums.size() << " numbers -> " << got.size() << " permutations";
        if (got.size() <= 6) {
            cout << ":";
            for (auto& p : got) { cout << " ["; for (size_t i = 0; i < p.size(); ++i) cout << (i ? "," : "") << p[i]; cout << "]"; }
        }
        cout << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
