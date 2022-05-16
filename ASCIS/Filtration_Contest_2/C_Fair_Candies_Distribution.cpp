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
    ll n, a, b;
    cin >> n >> a >> b;
    if ((n % 2 == 0 && a >= n / 2 && b >= n / 2) || (n % 2 != 0 && a >= n / 2 && b >= n / 2 + 1) ||
        (n % 2 != 0 && a >= n / 2 + 1 && b >= n / 2))
        cout << "YES";
    else cout << "NO";
    return 0;
}
