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
    ll n;
    cin >> n;
    vll v(n);
    ll sum = 0;
    rep(i, v) {
        cin >> v[i];
        sum += v[i];
    }
    bool result = true;
    rep(i, v) {
        if (sum % v[i] != 0) {
            result = false;
            break;
        }
    }
    if (result)cout << "YES";
    else cout << "NO";
    return 0;
}
