// Week 1 redo 2, from memory (Mon Nov 16): Tower of Hanoi, printing every move
#include <iostream>
using namespace std;

void calc(int n, char src, char dest, char temp) {
    if (n <= 0) {
        return;
    }
    calc(n - 1, src, temp, dest);
    cout << "Move " << n << "th disk from " << src << " to " << dest << endl;
    calc(n - 1, temp, dest, src);
}
int main() {
    int n;
    cin >> n;
    calc(n, 'A', 'C', 'B');
    return 0;
}
