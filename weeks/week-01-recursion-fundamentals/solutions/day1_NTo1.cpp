#include<iostream>
using namespace std;

void func(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    func(n - 1);
}

int main(){
    int n;
    cin >> n;
    func(n);
    return 0;
}