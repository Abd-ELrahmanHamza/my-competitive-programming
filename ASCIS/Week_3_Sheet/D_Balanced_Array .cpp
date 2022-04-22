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
        vll even, odd;

        if ((n / 2) % 2 != 0) {
            cout << "NO" << endl;
        } else {
            for (int i = 1; i <= n / 2; i++) {
                if (i % 2 == 0) {
                    even.push_back(i);
                    even.push_back(n + 2 - i);
                } else {
                    odd.push_back(i);
                    odd.push_back(n + 2 - i);
                }
            }
            cout << "Yes" << endl;
            for (ll x: even)cout << x << " ";
            for (ll x: odd)cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}
