// Week 6 Friday: LC 91 Decode Ways (memoized on the start index)
#include <cstring>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[110];
    int calc(int idx, int n, string s) {
        if (idx >= n) {
            return 1;
        }

        if (memo[idx] != -1) return memo[idx];
        int first = 0;
        if (s[idx] != '0') {
            first = calc(idx + 1, n, s);
        }

        int second = 0;
        if (idx + 1 < n) {
            int ones = s[idx + 1] - '0';
            int tens = s[idx] - '0';
            if (tens > 0 && tens < 3 && (10 * tens + ones <= 26)) {
                second = calc(idx + 2, n, s);
            }
        }

        return memo[idx] = first + second;
    }
    int numDecodings(string s) {
        memset(memo, -1, sizeof(memo));
        int n = s.length();
        int ans = calc(0, n, s);
        return ans;
    }
};

// Reference: try every way to cut s into pieces of length 1 or 2, and count the valid ones.
long long brute(const string& s, size_t i = 0) {
    if (i == s.size()) return 1;
    long long ways = 0;
    if (s[i] != '0') ways += brute(s, i + 1);
    if (i + 1 < s.size() && s[i] != '0' && stoi(s.substr(i, 2)) <= 26) ways += brute(s, i + 2);
    return ways;
}

int main() {
    vector<string> tests = {"12", "226", "06", "0", "1", "10", "27", "100", "101", "230", "2101", "1201234", "11106"};
    mt19937 rng(91);
    for (int t = 0; t < 5000; ++t) {                   // random, 1..20 digits, weighted towards 0, 1, 2
        string s(1 + rng() % 20, '0');
        for (char& c : s) c = "0112223456789"[rng() % 13];
        tests.push_back(s);
    }
    int failed = 0;
    Solution sol;                                      // numDecodings resets memo, so one object is enough
    for (auto& s : tests) {
        if (sol.numDecodings(s) != brute(s)) { ++failed; cout << "FAIL on " << s << endl; }
    }
    struct Big { string s; int want; };
    string tens;
    for (int i = 0; i < 50; ++i) tens += "10";
    vector<Big> big = {{string(40, '1'), 165580141}, {string(100, '9'), 1}, {tens, 1}};
    for (auto& b : big) {
        if (sol.numDecodings(b.s) != b.want) { ++failed; cout << "FAIL on " << b.s.size() << " digits" << endl; }
    }
    cout << tests.size() << " strings (13 fixed + 5000 random) and " << big.size() << " long ones: "
         << (failed ? "some FAILED" : "all match the brute force") << endl;
    return failed != 0;
}
