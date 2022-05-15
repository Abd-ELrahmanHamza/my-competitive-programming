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

int main() {
    ll n, q;
    cin >> n >> q;
    unordered_map<ll, ll> m;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        m[x]++;
    }
    ll tn = n;
    while (q--) {
        ll group, jl;
        cin >> group >> jl;
        if (m[group] + jl < 0) {
            cout << "Invalid operation\n";
        } else {
            m[group] += jl;
            tn += jl;
            cout << m[group] << " " << tn << endl;
        }
    }
    return 0;
}
