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
        char s[n + 1];
        cin >> s;
        int b = 0, r = 0;
        bool result = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B')b++;
            else if (s[i] == 'R')r++;
            else if ((b == 0 && r != 0) || (b != 0 && r == 0)) {
                result = false;
                break;
            } else {
                b = 0;
                r = 0;
            }
        }
        if ((b == 0 && r != 0) || (b != 0 && r == 0)) {
            result = false;
        }
        if (!result) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
