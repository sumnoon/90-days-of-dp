#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int calc(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return calc(n - 1) + calc(n - 2);
    }
    int fib(int n) {
        int ans = calc(n);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    int ans = Solution().fib(n);

    cout << ans << endl;
    return 0;
}
