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
        cin>>n;
        vi v(n);
        for (int &x: v)cin >> x;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) even += v[i] % 2;
            else odd += v[i] % 2;
        }
        if ((odd == 0 || odd == n / 2) && (even == 0 || even == ceil(n / 2.0)))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
