#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(const string& s, int l, int r) {
    if (r <= l) {
        return true;
    }

    if (s[l] == s[r]) {
        return checkPalindrome(s, l + 1, r - 1);
    }

    return false;
}

int main(){
    string s;
    bool isPalindrome;
    cin >> s;

    isPalindrome = checkPalindrome(s, 0, s.length() - 1);

    cout << isPalindrome << endl;
    return 0;
}