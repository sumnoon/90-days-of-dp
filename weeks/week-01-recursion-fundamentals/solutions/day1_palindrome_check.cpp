#include<iostream>
#include<string>
using namespace std;

bool check_palindrom(const string& s, int l, int r) {
    if (r <= l) {
        return true;
    }
    
    if (s[l] == s[r]) {
        return check_palindrom(s, l + 1, r - 1);
    }
    else {
        return false;
    }
}

int main(){
    string s;
    int n;

    cin >> s;
    n = s.size();

    bool flag = check_palindrom(s, 0, n - 1);

    cout << boolalpha;
    cout << flag << endl;
    return 0;
}