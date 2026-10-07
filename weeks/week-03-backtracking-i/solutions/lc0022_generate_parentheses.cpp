#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void backtrack(int idx, string cur, int lPar, int rPar) { // lPar and rPar is how many left and right parentheses remains to add in the string
        if (lPar == 0 && rPar == 0) {
            ans.push_back(cur);
            return;
        }

        if (lPar) // IF there is any left parentheses remains
        {
            cur.push_back('(');
            backtrack(idx + 1, cur, lPar - 1, rPar);
            cur.pop_back();
        }
        if (lPar < rPar) { // IF there are more right parentheses remain than left parentheses
            cur.push_back(')');
            backtrack(idx + 1, cur, lPar, rPar - 1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0, "", n, n);
        return ans;
    }
};

// --- local harness (LeetCode supplies these) ---

bool balanced(const string& s) {
    int open = 0;
    for (char c : s) {
        open += c == '(' ? 1 : -1;
        if (open < 0) return false;     // a ')' with nothing to close
    }
    return open == 0;
}

int main() {
    const long long catalan[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430};   // C(0) .. C(8)
    int failed = 0;
    for (int n = 1; n <= 8; ++n) {
        vector<string> got = Solution().generateParenthesis(n);   // a fresh object per call
        set<string> uniq(got.begin(), got.end());
        bool ok = (long long)got.size() == catalan[n] && uniq.size() == got.size();
        for (auto& s : got) if ((int)s.size() != 2 * n || !balanced(s)) ok = false;
        if (!ok) ++failed;
        cout << (ok ? "ok   " : "FAIL ") << "n=" << n << " -> " << got.size() << " strings";
        if (n == 3) { cout << ":"; for (auto& s : got) cout << " " << s; }
        cout << endl;
    }
    cout << (failed ? "some cases failed" : "all cases pass") << endl;
    return failed != 0;
}
