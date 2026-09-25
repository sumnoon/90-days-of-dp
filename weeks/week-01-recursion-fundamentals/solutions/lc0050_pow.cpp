#include <iomanip>
#include <iostream>
using namespace std;

class Solution {
public:
    double helper (double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1.0 / helper(x, -1 * n);
        }
        if (n & 1) {
            return x * helper(x * x, (n - 1) / 2);
        }
        else {
            return helper(x * x, n / 2);
        }
    }
    double myPow(double x, int n) {
        double res = helper(x, n);
        return res;
    }
};

int main() {
    double x;
    int n;
    cin >> x >> n;

    double ans = Solution().myPow(x, n);

    cout << setprecision(10) << ans << endl;
    return 0;
}
