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
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                backtrack(i, cur, candidates, target - candidates[i]);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        backtrack(0, cur, candidates, target);
        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

// Reference, built differently: for each candidate in turn, decide how many
// copies to take (0, 1, 2, ...), as long as the total still fits.
void by_counts(const vector<int>& c, size_t i, int left, vector<int>& cur, set<vector<int>>& out) {
    if (left == 0) { vector<int> s = cur; sort(s.begin(), s.end()); out.insert(s); return; }
    if (i == c.size()) return;
    by_counts(c, i + 1, left, cur, out);                       // no more copies of c[i]
    if (c[i] <= left) {
        cur.push_back(c[i]);
        by_counts(c, i, left - c[i], cur, out);                // one more copy of c[i]
        cur.pop_back();
    }
}

int main() {
    struct Case { vector<int> c; int target; };
    Case cases[] = {
        {{2, 3, 6, 7}, 7},          // LeetCode example 1: [2,2,3] [7]
        {{2, 3, 5}, 8},             // LeetCode example 2
        {{2}, 1},                   // LeetCode example 3: no way
        {{1}, 1},
        {{7, 3, 2}, 18},            // unsorted input
        {{2, 7, 6, 3, 5, 1}, 9},
        {{8, 7, 4, 3}, 11},
        {{2, 3, 5}, 40},            // LeetCode's largest target
    };
    int failed = 0;
    for (auto& [c, target] : cases) {
        vector<vector<int>> got = Solution().combinationSum(c, target);   // a fresh object per call
        set<vector<int>> mine;
        bool sums_ok = true;
        for (auto v : got) {
            int s = 0;
            for (int x : v) s += x;
            if (s != target) sums_ok = false;
            sort(v.begin(), v.end());
            mine.insert(v);
        }
        set<vector<int>> ref;
        vector<int> cur;
        by_counts(c, 0, target, cur, ref);
        bool ok = sums_ok && mine.size() == got.size() && mine == ref;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "target " << target << " -> " << got.size() << " combinations";
        if (got.size() <= 3) {
            cout << ":";
            for (auto& v : got) { cout << " ["; for (size_t i = 0; i < v.size(); ++i) cout << (i ? "," : "") << v[i]; cout << "]"; }
        }
        cout << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
