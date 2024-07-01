#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x1, x2, x3, minC = 1, minDist = INT_MAX;
        cin >> x1 >> x2 >> x3;
        for (int i = 1; i <= 10; ++i) {
            if (abs(x1 - i) + abs(x2 - i) + abs(x3 - i) < minDist) {
                minDist = abs(x1 - i) + abs(x2 - i) + abs(x3 - i);
                minC = i;
            }
        }
        cout << minDist << endl;
    }
    return 0;
}
