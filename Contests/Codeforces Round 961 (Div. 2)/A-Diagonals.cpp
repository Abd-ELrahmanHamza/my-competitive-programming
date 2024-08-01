#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int d = 0;
        if (k != 0) {
            k -= (n--);
            d++;
        }
        while (k > 0) {
            d++;
            k -= n;
            if (k > 0) {
                d++;
                k -= n;
            }
            n--;
        }
        cout << d << endl;
    }
    return 0;
}
