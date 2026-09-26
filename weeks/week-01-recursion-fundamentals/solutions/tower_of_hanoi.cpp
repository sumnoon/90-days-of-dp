#include <iostream>
using namespace std;

class Solution {
public:
    void towerOfHanoi(int n, string source, string destination, string temporary) {
        if (n == 0) {
            return;
        }
        towerOfHanoi(n - 1, source, temporary, destination);
        cout << "Move from " << source << " to " << destination << endl;
        towerOfHanoi(n - 1, temporary, destination, source);
    }
};

int main() {
    int n;
    cin >> n;

    Solution().towerOfHanoi(n, "A", "C", "B");

    return 0;
}
