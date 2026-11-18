// Week 6 Saturday: LC 1048 Longest String Chain (LIS over words, sorted by length)
#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> memo;
        sort(words.begin(), words.end(),
             [](const string& a, const string& b) { return a.length() < b.length(); });

        for (const string word : words) {
            memo[word] = 1;

            for (int i = 0; i < word.length(); ++i) {
                string brokenWord = word.substr(0, i) + word.substr(i + 1);
                if (memo.find(brokenWord) != memo.end()) {
                    memo[word] = max(memo[word], memo[brokenWord] + 1);
                }
            }
        }

        int ans = 0;
        for (auto value : memo) {
            ans = max(ans, value.second);
        }

        return ans;
    }
};

// Reference: LIS-style table over words sorted by length, checking every pair directly.
bool isPredecessor(const string& a, const string& b) {   // b is a with one letter inserted
    if (a.size() + 1 != b.size()) return false;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) ++i;
        ++j;
    }
    return i == a.size();
}
int reference(vector<string> w) {
    sort(w.begin(), w.end(), [](const string& a, const string& b) { return a.size() < b.size(); });
    vector<int> best(w.size(), 1);
    int ans = 0;
    for (size_t i = 0; i < w.size(); ++i) {
        for (size_t j = 0; j < i; ++j)
            if (isPredecessor(w[j], w[i])) best[i] = max(best[i], best[j] + 1);
        ans = max(ans, best[i]);
    }
    return ans;
}

int main() {
    vector<vector<string>> tests = {{"a", "b", "ba", "bca", "bda", "bdca"}, {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"},
                                    {"abcd", "dbqca"}, {"a"}, {"a", "a", "aa"}, {"ab", "a", "abc", "b"}};
    mt19937 rng(1048);
    for (int t = 0; t < 2000; ++t) {                   // random words over {a, b, c}, 1..6 letters, 1..30 words
        vector<string> w(1 + rng() % 30);
        for (auto& s : w) {
            s.assign(1 + rng() % 6, 'a');
            for (char& c : s) c = 'a' + rng() % 3;
        }
        tests.push_back(w);
    }
    vector<string> big;                                // LeetCode's limits: 1,000 words of up to 16 letters
    string chain;
    for (int k = 0; k < 16; ++k) chain += char('a' + k), big.push_back(chain);   // a chain of 16
    while (big.size() < 1000) {
        string s(1 + rng() % 16, 'a');
        for (char& c : s) c = 'a' + rng() % 26;
        big.push_back(s);
    }
    tests.push_back(big);
    int failed = 0;
    for (auto& w : tests) {
        auto copy = w;                                 // longestStrChain sorts its input
        if (Solution().longestStrChain(copy) != reference(w)) { ++failed; cout << "FAIL on " << w.size() << " words" << endl; }
    }
    cout << tests.size() << " word lists (6 fixed + 2000 random + one of 1,000): "
         << (failed ? "some FAILED" : "all match the reference") << endl;
    return failed != 0;
}
