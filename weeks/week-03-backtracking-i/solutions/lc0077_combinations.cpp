#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void func(vector<int> &cur, int idx, int n, int k) {
        if (cur.size() == k) {
            ans.push_back(cur);
            return;
        }

        int need = k - cur.size();
        int remain = n - idx + 1;
        int available = remain - need;

        for (int i = idx; i <= idx + available; ++i) {
            cur.push_back(i);
            func(cur, i + 1, n, k);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        func(cur, 1, n, k);
        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

// Reference: every k-subset of 1..n, from the bits of a mask.
vector<vector<int>> by_bitmask(int n, int k) {
    vector<vector<int>> out;
    for (int m = 0; m < (1 << n); ++m) {
        if (__builtin_popcount(m) != k) continue;
        vector<int> c;
        for (int i = 0; i < n; ++i) if (m >> i & 1) c.push_back(i + 1);
        out.push_back(c);
    }
    return out;
}

long long choose(int n, int k) {
    long long r = 1;
    for (int i = 1; i <= k; ++i) r = r * (n - k + i) / i;
    return r;
}

int main() {
    int tests[][2] = {{4, 2}, {1, 1}, {5, 5}, {5, 1}, {10, 3}, {20, 2}, {20, 10}};
    int failed = 0;
    for (auto& t : tests) {
        int n = t[0], k = t[1];
        vector<vector<int>> got = Solution().combine(n, k);   // a fresh object per call
        set<vector<int>> uniq(got.begin(), got.end());
        vector<vector<int>> ref = by_bitmask(n, k);
        bool ok = (long long)got.size() == choose(n, k) && uniq.size() == got.size()
                  && uniq == set<vector<int>>(ref.begin(), ref.end());
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "n=" << n << ", k=" << k << " -> " << got.size() << " combinations" << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
