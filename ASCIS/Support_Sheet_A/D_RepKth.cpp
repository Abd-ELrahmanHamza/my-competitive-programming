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
    int n, k, m;
    cin >> n >> k >> m;
    vector<ull> v(n);
    vector<ull> v2(n);
    for (ull &x: v)cin >> x;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            ull sum = 0;
            for (int l = 0; l < n; ++l) {
                sum += v[l];
            }
            v2[j] = sum - v[j];
        }
        v = v2;
    }
    cout << v2[m - 1];
    return 0;
}
