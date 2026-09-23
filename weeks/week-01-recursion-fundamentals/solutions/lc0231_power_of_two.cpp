#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        return ((n == 1) || (n % 2 == 0 && isPowerOfTwo(n / 2)));
    }
};

int main() {
    int n;
    cin >> n;

    bool ans = Solution().isPowerOfTwo(n);

    cout << boolalpha << ans << endl;
    return 0;
}
