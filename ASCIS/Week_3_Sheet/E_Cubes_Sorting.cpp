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
        int prev, cur;
        cin >> prev;
        bool result = false;
        for (int i = 0; i < n - 1; i++) {
            cin >> cur;
            if (cur >= prev) {
                result = true;
            }
            prev = cur;
        }
        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
