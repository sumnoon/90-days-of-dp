///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
int coins[110], memo[1000010];

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    for (int i = 0; i <= x; ++i) {
        memo[i] = INT_MAX - 1;
    }

    memo[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= x; ++j) {
            memo[j] = min(memo[j], 1 + memo[j - coins[i]]);
        }
    }

    cout << ((memo[x] == INT_MAX - 1) ? -1 : memo[x]) << endl;

    return 0;
}
