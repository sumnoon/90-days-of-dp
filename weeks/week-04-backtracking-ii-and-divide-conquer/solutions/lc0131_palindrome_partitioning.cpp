#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> ans;
    bool checkPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void backtrack(int idx, const string& s, vector<string>& cur) {
        if (idx == s.length()) {
            ans.push_back(cur);
            return;
        }

        for (int i = idx; i < s.length(); ++i) {
            if (checkPalindrome(s, idx, i)) {
                cur.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, s, cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        backtrack(0, s, cur);
        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

// Reference: every way to cut the string is a bitmask over its n - 1 gaps;
// keep the cuttings whose pieces are all palindromes.
set<vector<string>> brute(const string& s) {
    set<vector<string>> out;
    int n = s.size();
    for (int m = 0; m < (1 << (n - 1)); ++m) {
        vector<string> parts;
        int start = 0;
        for (int g = 0; g < n; ++g) {
            if (g == n - 1 || (m >> g & 1)) {
                parts.push_back(s.substr(start, g - start + 1));
                start = g + 1;
            }
        }
        bool ok = true;
        for (auto& p : parts) if (p != string(p.rbegin(), p.rend())) ok = false;
        if (ok) out.insert(parts);
    }
    return out;
}

int main() {
    vector<string> inputs = {"aab", "a", "ab", "aaa", "racecar", "abba", "abcba", "aaaaaaaaaaaaaaaa"};
    mt19937 rng(131);
    for (int t = 0; t < 300; ++t) {               // random strings over "ab" and "abc", up to 16 letters
        string s;
        int len = 1 + rng() % 16, k = 2 + rng() % 2;
        for (int i = 0; i < len; ++i) s += char('a' + rng() % k);
        inputs.push_back(s);
    }
    int failed = 0, shown = 0;
    for (auto& s : inputs) {
        vector<vector<string>> got = Solution().partition(s);   // a fresh object per call
        set<vector<string>> mine(got.begin(), got.end());
        bool ok = mine.size() == got.size() && mine == brute(s);
        if (!ok) { ++failed; cout << "FAIL \"" << s << "\"" << endl; }
        else if (shown++ < 8) {
            cout << "ok   \"" << s << "\" -> " << got.size() << " partitions";
            if (got.size() <= 4) for (auto& v : got) { cout << " ["; for (size_t i = 0; i < v.size(); ++i) cout << (i ? "," : "") << v[i]; cout << "]"; }
            cout << endl;
        }
    }
    cout << inputs.size() << " strings (8 fixed + 300 random): " << (failed ? "some FAILED" : "all match the brute force") << endl;

    // Worst case at LeetCode's limit: 16 identical letters, where every cutting works.
    auto t0 = chrono::steady_clock::now();
    size_t count = Solution().partition(string(16, 'a')).size();
    auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - t0).count();
    cout << "16 x 'a': " << count << " partitions in " << ms << " ms" << endl;
    return failed != 0;
}
