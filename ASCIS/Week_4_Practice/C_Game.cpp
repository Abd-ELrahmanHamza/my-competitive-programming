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

vll prime_factors(ll n) {
    vll primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        primes.push_back(n);
    return primes;
}

ll binary_search(ll s, ll e, ll k) {
    ll middle = (s + e) / 2;
    if (k == middle)
        return 1;
    else if (k < middle)
        return 1 + binary_search(s, middle - 1, k);
    else
        return 1 + binary_search(middle + 1, e, k);
}

int main() {
    ll n, q;
    cin >> n >> q;
    vll v(n);
    for (ll &x: v)cin >> x;
    while (q--) {
        ll x;
        cin >> x;
        auto it = upper_bound(v.begin(), v.end(), x);
        if (it != v.end())
            cout << *(it) << endl;
        else cout << -1 << endl;
    }
    return 0;
}
