// Week 6 Wednesday: LC 322 Coin Change, the recursion with a cache and then the table
// Both versions take just (coins, amount) and return the answer.
#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
using namespace std;

class Solution {
   public:
    int memo[13][10010];

    // 1. Memoized: calc(idx, amount) = fewest coins from coins[idx..] that make amount.
    int calc(int idx, vector<int>& coins, int amount) {
        if (idx == coins.size() || amount <= 0) {
            return (amount == 0) ? 0 : INT_MAX - 1;
        }

        if (memo[idx][amount] != -1) return memo[idx][amount];
        int res = -1;
        if (coins[idx] > amount) {
            res = 0 + calc(idx + 1, coins, amount);
        } else {
            int take = 1 + calc(idx, coins, amount - coins[idx]);
            int notTake = 0 + calc(idx + 1, coins, amount);
            res = min(take, notTake);
        }
        return memo[idx][amount] = res;
    }
    int coinChangeMemo(vector<int>& coins, int amount) {
        memset(memo, -1, sizeof(memo));
        int ans = calc(0, coins, amount);
        return (ans == INT_MAX - 1) ? -1 : ans;
    }

    // 2. Table: memo[i][j] = fewest coins from the first i coins that make j.
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= amount; ++j) {
                memo[i][j] = INT_MAX - 1;
            }
        }
        for (int i = 0; i <= n; ++i) {
            memo[i][0] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (coins[i - 1] > j) {
                    memo[i][j] = memo[i - 1][j];
                } else {
                    memo[i][j] = min(memo[i - 1][j], 1 + memo[i][j - coins[i - 1]]);
                }
            }
        }
        return (memo[n][amount] == INT_MAX - 1) ? -1 : memo[n][amount];
    }
};

// Reference: one row over amounts, trying every coin as the last one.
int reference(const vector<int>& coins, int amount) {
    vector<int> best(amount + 1, INT_MAX);
    best[0] = 0;
    for (int a = 1; a <= amount; ++a)
        for (int c : coins)
            if (c <= a && best[a - c] != INT_MAX) best[a] = min(best[a], best[a - c] + 1);
    return best[amount] == INT_MAX ? -1 : best[amount];
}

int main() {
    struct Case { vector<int> coins; int amount; };
    vector<Case> tests = {{{1, 2, 5}, 11}, {{2}, 3}, {{1}, 0}, {{2, 5, 10, 1}, 27}, {{186, 419, 83, 408}, 6249},
                          {{2147483647}, 2}, {{3, 7}, 11}, {{1}, 10000}, {{7, 13}, 10000}};
    mt19937 rng(322);
    for (int t = 0; t < 3000; ++t) {                   // random, 1..12 coins of 1..40, amounts 0..300
        vector<int> coins(1 + rng() % 12);
        for (int& c : coins) c = 1 + rng() % 40;
        tests.push_back({coins, (int)(rng() % 301)});
    }
    auto s = make_unique<Solution>();                  // memo is 13 x 10,010 ints: keep it off the stack
    int failed = 0;
    for (auto& [coins, amount] : tests) {
        int want = reference(coins, amount);
        if (s->coinChangeMemo(coins, amount) != want || s->coinChange(coins, amount) != want) {
            ++failed;
            cout << "FAIL on " << coins.size() << " coins, amount " << amount << endl;
        }
    }
    cout << tests.size() << " cases (9 fixed + 3000 random): "
         << (failed ? "some FAILED" : "the memoized and table versions both match the reference") << endl;
    return failed != 0;
}
