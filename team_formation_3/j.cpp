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
    ll n, k;
    cin >> n;
    vll a(n), b(n);
    for (ll &x: a)cin >> x;
    for (ll &x: b)cin >> x;
    cin >> k;
    vll c(k);
    for (ll &x: c)cin >> x;
    cout << (ll)(*max_element(a.begin(), a.end())) * k +(ll) accumulate(c.begin(), c.end(), 0);
    return 0;
}
