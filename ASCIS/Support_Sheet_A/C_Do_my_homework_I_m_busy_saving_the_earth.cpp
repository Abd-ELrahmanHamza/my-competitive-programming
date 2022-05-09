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


int main() {
    int n;
    cin >> n;
    vll v(n);
    for (ll &x: v)cin >> x;
    vll vSorted(v);
    sort(vSorted.begin(), vSorted.end());
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vSorted[i] == v[i])cnt++;
    }
    cout << cnt;
    return 0;
}
