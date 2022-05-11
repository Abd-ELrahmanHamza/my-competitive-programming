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
    int a, b, c;
    cin >> a >> b >> c;
    bool cond1 = pow(a, 2) + pow(b, 2) == pow(c, 2);
    bool cond2 = pow(a, 2) + pow(c, 2) == pow(b, 2);
    bool cond3 = pow(c, 2) + pow(b, 2) == pow(a, 2);
    if (cond1 || cond2 || cond3) cout << "YES";
    else cout << "NO";
    return 0;
}
