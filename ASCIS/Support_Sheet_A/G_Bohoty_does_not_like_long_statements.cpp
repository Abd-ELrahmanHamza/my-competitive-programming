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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[j][i];
        }
    }

    for (int i = 0; i < m; ++i) {
        sort(v[i].begin(), v[i].end(),greater<int>());
        cout << accumulate(v[i].begin(), v[i].begin() + k, 0) << endl;
    }
    return 0;
}
