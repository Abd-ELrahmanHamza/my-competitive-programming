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
    ll n, m;
    cin >> n >> m;
    vll a(n), b(n);
    for (ll &x: a)cin >> x;
    for (ll &x: b)cin >> x;
    ll cnt = 0;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((b[i] + b[j]) % m == a[k])
                    cnt++;
            }
        }
        cout << cnt << " ";
        cnt = 0;
    }
    return 0;
}
