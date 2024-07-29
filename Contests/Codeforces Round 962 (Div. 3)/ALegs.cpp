#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << x / 4 + (x - 4 * (x / 4)) / 2 << endl;
    }
    return 0;
}