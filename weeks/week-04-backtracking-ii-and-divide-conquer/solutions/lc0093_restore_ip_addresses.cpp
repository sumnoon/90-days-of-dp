#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> ans;
    bool valid(string cur) {
        if (cur.empty() || cur.length() > 3) return false;
        if (cur.length() > 1 && cur[0] == '0') return false;
        int val = stoi(cur);
        return val >= 0 && val <= 255;
    }
    void backtrack(int idx, int dot_cnts, string s, string cur) {
        // base case: if already 3 dots are placed than rest of 's' is fourth segment. So check and
        // add to cur
        if (dot_cnts == 3) {
            string segment = s.substr(idx);
            if (valid(segment)) {
                ans.push_back(cur + segment);
            }
            return;
        }

        for (int i = 1; i <= 3 && idx + i < s.length(); ++i) {
            string segment = s.substr(idx, i);
            if (valid(segment)) {
                backtrack(idx + i, dot_cnts + 1, s, cur + segment + ".");
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12) return {};
        backtrack(0, 0, s, "");
        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

// Reference: try every way to put 3 dots between the digits, keep the valid ones.
bool part_ok(const string& p) {
    if (p.empty() || p.size() > 3) return false;
    if (p.size() > 1 && p[0] == '0') return false;
    return stoi(p) <= 255;
}
set<string> brute(const string& s) {
    set<string> out;
    int n = s.size();
    for (int a = 1; a < n; ++a)
        for (int b = a + 1; b < n; ++b)
            for (int c = b + 1; c < n; ++c) {
                string p1 = s.substr(0, a), p2 = s.substr(a, b - a), p3 = s.substr(b, c - b), p4 = s.substr(c);
                if (part_ok(p1) && part_ok(p2) && part_ok(p3) && part_ok(p4))
                    out.insert(p1 + "." + p2 + "." + p3 + "." + p4);
            }
    return out;
}

int main() {
    vector<string> inputs = {
        "25525511135",      // LeetCode example 1
        "0000",             // LeetCode example 2
        "101023",           // LeetCode example 3
        "1111", "010010", "255255255255", "256256256256",
        "123", "1234567890123",   // too short, too long
        "1", "",
    };
    mt19937 rng(93);
    for (int t = 0; t < 300; ++t) {            // random digit strings of every allowed length
        string s;
        int len = 1 + rng() % 20;
        for (int i = 0; i < len; ++i) s += char('0' + rng() % 10);
        inputs.push_back(s);
    }
    int failed = 0, shown = 0;
    for (auto& s : inputs) {
        vector<string> got = Solution().restoreIpAddresses(s);   // a fresh object per call
        set<string> mine(got.begin(), got.end());
        bool ok = mine.size() == got.size() && mine == brute(s);
        if (!ok) { ++failed; cout << "FAIL \"" << s << "\"" << endl; }
        else if (shown < 11) {
            ++shown;
            cout << "ok   \"" << s << "\" -> " << got.size();
            if (got.size() <= 5) for (auto& a : got) cout << " " << a;
            cout << endl;
        }
    }
    cout << inputs.size() << " inputs (11 fixed + 300 random); " << (failed ? "some failed" : "all match the brute force") << endl;
    return failed != 0;
}
