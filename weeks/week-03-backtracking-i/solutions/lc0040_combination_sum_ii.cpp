#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int idx, vector<int>& cur, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            if (i != idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                backtrack(i + 1, cur, candidates, target - candidates[i]);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(0, cur, candidates, target);
        return ans;    
    }
};

// --- local harness (LeetCode supplies these) ---

// Reference: every bitmask subset whose sum hits the target, sorted, kept once.
set<vector<int>> by_bitmask(vector<int> c, int target) {
    sort(c.begin(), c.end());
    set<vector<int>> out;
    for (int m = 0; m < (1 << c.size()); ++m) {
        vector<int> s;
        int sum = 0;
        for (size_t i = 0; i < c.size(); ++i) if (m >> i & 1) { s.push_back(c[i]); sum += c[i]; }
        if (sum == target) out.insert(s);
    }
    return out;
}

int main() {
    struct Case { vector<int> c; int target; };
    Case cases[] = {
        {{10, 1, 2, 7, 6, 1, 5}, 8},          // LeetCode example 1
        {{2, 5, 2, 1, 2}, 5},                 // LeetCode example 2
        {{1, 1, 1}, 2},                       // three copies: [1,1] once
        {{1, 1, 1, 1, 1}, 3},                 // five copies: [1,1,1] once
        {{2}, 1},                             // no way
        {{3, 1, 3, 5, 1, 1}, 8},
        {{1, 2, 2, 2, 3, 3, 4, 5, 5, 6}, 10},
    };
    int failed = 0;
    for (auto& [c, target] : cases) {
        vector<int> in = c;
        vector<vector<int>> got = Solution().combinationSum2(in, target);   // a fresh object per call
        set<vector<int>> mine(got.begin(), got.end());
        set<vector<int>> ref = by_bitmask(c, target);
        bool ok = mine.size() == got.size() && mine == ref;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "target " << target << " -> " << got.size() << " combinations";
        if (got.size() <= 4) {
            cout << ":";
            for (auto& v : got) { cout << " ["; for (size_t i = 0; i < v.size(); ++i) cout << (i ? "," : "") << v[i]; cout << "]"; }
        }
        cout << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
