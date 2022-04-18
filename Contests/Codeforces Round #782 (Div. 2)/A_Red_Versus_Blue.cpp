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

vll primeFactors(ll n) {
    vll primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0)
            primes.push_back(i), n /= i;
    }
    if (n > 1)
        primes.push_back(n);
    return primes;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, r, b;
        cin >> n >> r >> b;
        int minseq = r / (b + 1);
        int rem = r % (b + 1);
//        cout << "Min seq:" << minseq << " rem: " << rem << endl;
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < minseq; j++) {
                cout << "R";
                r--;
            }
            if (rem > 0) {
                cout << "R";
                r--;
                rem--;
            }
            cout << "B";
        }
        for (int i = 0; i < r; ++i) {
            cout << "R";
        }
        cout << endl;
    }
    return 0;
}
