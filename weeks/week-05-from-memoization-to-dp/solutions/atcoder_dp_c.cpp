///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
int act[100010][3], memo[100010][3];
int calc(int idx, int type, int n) {
    if (idx == n) {
        return 0;
    }

    if (memo[idx][type] != -1) {
        return memo[idx][type];
    }

    int ans = INT_MIN;

    for (int i = 0; i < 3; ++i) {
        if (i == type) continue;
        ans = max(ans, act[idx][i] + calc(idx + 1, i, n));
    }

    return memo[idx][type] = ans;
}
int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> act[i][0] >> act[i][1] >> act[i][2];
    }
    int ans = max(calc(0, 0, n), calc(0, 1, n));
    ans = max(ans, calc(0, 2, n));
    cout << ans << "\n";
    return 0;
}
