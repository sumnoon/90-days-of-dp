// Week 6 Sunday: LC 983 Minimum Cost For Tickets (memoized on the index of the next travel day)
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> memo;
    int calc(int idx, int n, vector<int>& costs, vector<int>& days) {
        if (idx >= n) {
            return 0;
        }

        if (memo[idx] != -1) {
            return memo[idx];
        }

        int first = costs[0] + calc(idx + 1, n, costs, days);

        int j = idx;
        while (j < n && days[j] < days[idx] + 7) {
            ++j;
        }

        int second = costs[1] + calc(j, n, costs, days);

        int k = idx;
        while (k < n && days[k] < days[idx] + 30) {
            ++k;
        }

        int third = costs[2] + calc(k, n, costs, days);

        return memo[idx] = min({first, second, third});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        memo.resize(n, -1);
        int ans = calc(0, n, costs, days);
        return ans;
    }
};

// Reference: a table over calendar days 1..365, going backwards.
int reference(const vector<int>& days, const vector<int>& costs) {
    vector<char> travel(366, 0);
    for (int d : days) travel[d] = 1;
    vector<int> best(366 + 30, 0);                      // best[d] = cheapest cover for every travel day >= d
    for (int d = 365; d >= 1; --d)
        best[d] = !travel[d] ? best[d + 1]
                             : min({costs[0] + best[d + 1], costs[1] + best[d + 7], costs[2] + best[d + 30]});
    return best[1];
}

int main() {
    struct Case { vector<int> days, costs; };
    vector<Case> tests = {{{1, 4, 6, 7, 8, 20}, {2, 7, 15}}, {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, {2, 7, 15}},
                          {{1}, {5, 2, 3}}, {{365}, {1, 1, 1}}, {{1, 365}, {7, 2, 15}}, {{1, 2, 3}, {1, 100, 100}}};
    mt19937 rng(983);
    for (int t = 0; t < 3000; ++t) {                   // random: 1..365 distinct sorted days, costs 1..1000 in any order
        vector<int> all(365);
        for (int i = 0; i < 365; ++i) all[i] = i + 1;
        shuffle(all.begin(), all.end(), rng);
        vector<int> days(all.begin(), all.begin() + 1 + rng() % 365);
        sort(days.begin(), days.end());
        vector<int> costs = {1 + (int)(rng() % 1000), 1 + (int)(rng() % 1000), 1 + (int)(rng() % 1000)};
        tests.push_back({days, costs});
    }
    int failed = 0;
    for (auto& [days, costs] : tests) {
        if (Solution().mincostTickets(days, costs) != reference(days, costs)) { ++failed; cout << "FAIL on " << days.size() << " days" << endl; }
    }
    cout << tests.size() << " cases (6 fixed + 3000 random): " << (failed ? "some FAILED" : "all match the reference") << endl;
    return failed != 0;
}
