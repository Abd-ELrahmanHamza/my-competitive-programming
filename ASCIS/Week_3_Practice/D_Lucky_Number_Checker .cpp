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
    char x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (x != '9' && x != '6' && x != '3') {
            cout << "NO";
            return 0;
        }
        if (n == 0 && x != '6') {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
