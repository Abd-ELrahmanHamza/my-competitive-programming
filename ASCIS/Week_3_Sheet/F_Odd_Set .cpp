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
#define rep(i, v) for(int i=0;i<v.size();++i)

ull fact(ull n) {
    ull result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

ull ncr(ull n, ull r) {
    ull result = 1;
    for (ull i = n; i >= n - r + 1; i--)
        result *= i;
    ull result2 = fact(r);
    return result / result2;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll even = 0, odd = 0;
        for (ll i = 0; i < 2 * n; i++) {
            ll x;
            cin >> x;
            if (x % 2 == 0)even++;
            else odd++;
        }
        cout << (odd == even ? "Yes" : "No") << endl;
    }
    return 0;
}
