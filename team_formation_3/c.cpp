#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<string> vs;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        if (n <= x + y && y >= n / 2 && x >= ceil(n / 2.0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
