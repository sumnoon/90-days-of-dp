///*BISMILLAHIR RAHMANIR RAHIM*///
#include <bits/stdc++.h>
using namespace std;
int h[100010], memo[100010];
int calc(int idx, int k, int n) {
    if (idx == n - 1) return 0;
    if (idx > n) return INT_MAX;

    if (memo[idx] != -1) return memo[idx];
    int ans = INT_MAX;
    for (int i = idx + 1; i < min(idx + k + 1, n); ++i) {
        ans = min(ans, abs(h[idx] - h[i]) + calc(i, k, n));
    }

    return memo[idx] = ans;
}
int main() {
    memset(memo, -1, sizeof(memo));
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int ans = calc(0, k, n);
    cout << ans << "\n";
    return 0;
}
