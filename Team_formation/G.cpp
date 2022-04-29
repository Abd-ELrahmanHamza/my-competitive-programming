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
        ll a, b;
        cin >> a >> b;
        vector<int> v, v2;
        int mul = 1;
        while (a != 0) {
            v.push_back((a % 10) * mul);
            a /= 10;
            mul *= 10;
        }
        mul = 1;
        while (b != 0) {
            v2.push_back((b % 10) * mul);
            b /= 10;
            mul *= 10;
        }
        bool first = true;
        for (ll x: v) {
            for (ll y: v2) {
                if (x != 0 && y != 0) {
                    if (!first)cout << " + ";
                    cout << x << " x " << y;
                    first = false;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
