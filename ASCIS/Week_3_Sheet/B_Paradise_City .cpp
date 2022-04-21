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

ull fact(ull n) {
    ull result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

ull ncr(ull n, ull r) {
    ull result = 1;
    for (ull i = n; i >= n - r + 1; i--)
        result *= i;
    ull result2 = fact(r);
    return result / result2;
}

int main() {
    ull t;
    cin >> t;
    while (t--) {
        ull n;
        cin >> n;
        vector<vector<char>> v(3, vector<char>(3 * n));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3 * n; j++) {
                cin >> v[i][j];
            }
        }
        int maxCnt = INT_MIN;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
//            cout << " k = " << i * n << " to k = " << (i * n + 3) << endl;
            for (int j = 0; j < 3; j++) {
                for (int k = i * 3; k < (i + 1) * 3; k++) {
                    if (v[j][k] == '*')cnt++;
                }
            }
            maxCnt = max(maxCnt, cnt);
        }
        cout << maxCnt * 4 << endl;
    }
    return 0;
}
