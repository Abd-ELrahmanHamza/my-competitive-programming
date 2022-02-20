#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long result = n * (n + 1) / 2;
        long long temp = 0;
        long long pow2 = 1;
        while (pow2 <= n) {
            temp += pow2;
            pow2 *= 2;
        }
        cout << result - 2 * temp<<endl;
    }
    return 0;
}
