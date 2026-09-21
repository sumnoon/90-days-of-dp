#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    void func(vector<char>& s, int l, int r) {
        if (r <= l) {
            return;
        }
        swap(s[l], s[r]);

        func(s, l + 1, r - 1);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        func(s, 0, n - 1);
    }
};

int main() {
    string word;
    cin >> word;

    vector<char> s(word.begin(), word.end());
    Solution().reverseString(s);

    cout << string(s.begin(), s.end()) << endl;
    return 0;
}
