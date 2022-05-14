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
    ll result = 1;
    ll mode = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        result = ((result % mode) * (4 % mode)) % mode;
    }
    cout << result << endl;
    return 0;
}
