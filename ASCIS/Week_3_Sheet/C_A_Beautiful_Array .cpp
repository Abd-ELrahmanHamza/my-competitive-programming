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
    ull t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll v(n);
        for (ll &x: v)cin >> x;
        sort(v.begin(), v.end());
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n / 2; i++)sum1 += v[i];
        for (int i = (int) ceil(n / 2.0); i < n; i++)sum2 += v[i];
        cout << sum2 - sum1 << endl;
    }
    return 0;
}
