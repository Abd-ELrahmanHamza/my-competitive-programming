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
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll v(n);
        for (ll &x: v)cin >> x;
        int i = 0, j = n - 1, cnt = 0;
        while (i < n - 1 && j > 0 && i < j) {
            if (v[i] == v[j]) {
                i++;
                j--;
            } else if (v[i] < v[j]) {
                v[i + 1] += v[i];
                i++;
                cnt++;
            } else {
                v[j - 1] += v[j];
                j--;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
