// Week 6 Thursday: LC 139 Word Break, memoized and then as a table
// Both versions take just (s, wordDict) and return the answer.
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> memo;
    // 1. Memoized: calc(idx) = whether s[0..idx] splits into dictionary words.
    bool calc(int idx, string s, vector<string>& wordDict) {
        if (idx < 0) return true;
        if (memo[idx] != -1) return memo[idx];

        for (string word : wordDict) {
            int wSize = word.length();
            if (idx - wSize + 1 < 0) {
                continue;
            }
            if (s.substr(idx - wSize + 1, wSize) == word && calc(idx - wSize, s, wordDict)) {
                memo[idx] = true;
                return true;
            }
        }

        return memo[idx] = false;
    }
    bool wordBreakMemo(string s, vector<string>& wordDict) {
        memo = vector(s.length(), -1);
        int n = s.length();
        bool ans = calc(n - 1, s, wordDict);
        return ans;
    }

    // 2. Table: memo[i] = whether the first i characters split into dictionary words.
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> memo(s.length() + 1, false);
        int n = s.length();

        memo[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (string word : wordDict) {
                int wSize = word.length();
                if (i >= wSize && memo[i - wSize] && s.substr(i - wSize, wSize) == word) {
                    memo[i] = true;
                    break;
                }
            }
        }

        return memo[n];
    }
};

// Reference: the same question as a set of reachable split points, filled forwards.
bool reference(const string& s, const vector<string>& dict) {
    vector<char> reach(s.size() + 1, 0);
    reach[0] = 1;
    for (size_t i = 0; i < s.size(); ++i)
        if (reach[i])
            for (auto& w : dict)
                if (s.compare(i, w.size(), w) == 0) reach[i + w.size()] = 1;
    return reach[s.size()];
}

int main() {
    struct Case { string s; vector<string> dict; };
    vector<Case> tests = {{"leetcode", {"leet", "code"}}, {"applepenapple", {"apple", "pen"}},
                          {"catsandog", {"cats", "dog", "sand", "and", "cat"}}, {"a", {"a"}}, {"a", {"b"}},
                          {"aaaaaaa", {"aaaa", "aaa"}}, {"cars", {"car", "ca", "rs"}}};
    mt19937 rng(139);
    for (int t = 0; t < 3000; ++t) {                   // random strings of a and b, 1..20 long; 1..5 words of 1..4
        Case c;
        for (int i = 1 + rng() % 20; i > 0; --i) c.s += char('a' + rng() % 2);
        for (int j = 1 + rng() % 5; j > 0; --j) {
            string w;
            for (int i = 1 + rng() % 4; i > 0; --i) w += char('a' + rng() % 2);
            c.dict.push_back(w);
        }
        tests.push_back(c);
    }
    vector<string> as;                                 // LeetCode's limits: 300 characters, a classic worst case
    for (int len = 1; len <= 10; ++len) as.push_back(string(len, 'a'));
    tests.push_back({string(299, 'a') + "b", as});
    tests.push_back({string(300, 'a'), as});
    int failed = 0;
    for (auto& [s, dict] : tests) {
        bool want = reference(s, dict);
        if (Solution().wordBreakMemo(s, dict) != want || Solution().wordBreak(s, dict) != want) {
            ++failed;
            cout << "FAIL on \"" << s << "\"" << endl;
        }
    }
    cout << tests.size() << " cases (7 fixed + 3000 random + 2 at the limit): "
         << (failed ? "some FAILED" : "the memoized and table versions both match the reference") << endl;
    return failed != 0;
}
