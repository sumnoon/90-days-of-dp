// Week 5 redo 1, from memory (Tue Nov 17): CSES Dice Combinations in O(1) space, a running sum of the last six
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll calcConst(ll n) {
    ll ret[6] = {1, 0, 0, 0, 0, 0};
    ll sum = 1;

    for (ll i = 1; i <= n; ++i) {
        ll idx = i % 6;
        ll oldest = ret[idx];
        ret[idx] = sum;
        sum = (sum + ret[idx] - oldest + MOD) % MOD;
    }

    return ret[n % 6];
}
int main() {
    ll n, ans;
    cin >> n;
    ans = calcConst(n);
    cout << ans << endl;
    return 0;
}
