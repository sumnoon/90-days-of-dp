#include <bits/stdc++.h>
using namespace std;

vector<int> memo;
const int mod = 1e9 + 7;
int calc(int n) {
    if (n < 0) {
        return 0;
    }

    if (n == 0) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    int ret = 0;

    for (int i = 1; i <= 6; ++i) {
        if (n - i < 0) continue;
        ret = (ret % mod + calc(n - i) % mod) % mod;
    }

    return memo[n] = ret;
}

int calcTab(int n) {
    memo[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j < 0) continue;
            memo[i] = (memo[i] + memo[i - j]) % mod;
        }
    }
    return memo[n];
}

int calcConst(int n) {
    int ret[6] = {1, 0, 0, 0, 0, 0};
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 0; j < 6; ++j) {
            sum = (sum + ret[j]) % mod;
        }
        ret[i % 6] = sum;
    }
    return ret[n % 6];
}

int main() {
    int n, ans;
    cin >> n;
    memo.resize(n + 1);
    ans = calcConst(n);
    cout << ans << endl;
    return 0;
}
