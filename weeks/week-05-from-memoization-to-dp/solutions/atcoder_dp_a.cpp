///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
int h[100010], memo[100010];
int calc(int idx, int n) {
    if (idx == n - 1) return 0;
    if (idx > n) return INT_MAX;

    if (memo[idx] != -1) return memo[idx];
    int ans = INT_MAX;
    if (idx + 1 < n) {
        ans = min(ans, abs(h[idx] - h[idx + 1]) + calc(idx + 1, n));
    }
    if (idx + 2 < n) {
        ans = min(ans, abs(h[idx + 2] - h[idx]) + calc(idx + 2, n));
    }

    return memo[idx] = ans;
}
int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int ans = calc(0, n);
    cout << ans << "\n";
    return 0;
}
