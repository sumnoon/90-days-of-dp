#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string mapper[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(int idx, string cur, string digits) {
        if (cur.size() == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for (auto c : mapper[digits[idx] - '2']) {
            cur.push_back(c);
            backtrack(idx + 1, cur, digits);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return {};
        }
        string cur = "";
        backtrack(0, cur, digits);

        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

// Reference: build the answers one digit at a time, extending every string so far.
vector<string> iterative(const string& digits) {
    if (digits.empty()) return {};
    const string keys[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> out = {""};
    for (char d : digits) {
        vector<string> next;
        for (const string& s : out)
            for (char c : keys[d - '2']) next.push_back(s + c);
        out = next;
    }
    return out;
}

int main() {
    string inputs[] = {"23", "", "2", "79", "7", "234", "9999", "2345"};
    int failed = 0;
    for (const string& d : inputs) {
        vector<string> got = Solution().letterCombinations(d);   // a fresh object per call
        vector<string> want = iterative(d);
        bool ok = got == want && set<string>(got.begin(), got.end()).size() == got.size();
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "\"" << d << "\" -> " << got.size() << " strings";
        if (got.size() <= 9) { cout << ":"; for (auto& s : got) cout << " " << s; }
        cout << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
