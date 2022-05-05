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
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        int rem1 = (x - a <= 0 ? 0 : x - a);
        int rem2 = (y - b <= 0 ? 0 : y - b);
        if (rem1 + rem2 <= c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
