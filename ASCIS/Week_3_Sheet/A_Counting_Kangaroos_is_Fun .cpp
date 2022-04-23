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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x: v)cin >> x;
    sort(v.begin(), v.end());
    int j = 0;
    for (int i = n / 2; i < n; i++) {
        if (v[i] >= 2 * v[j]) {
            j++;
        }
    }
    cout << n - min(j, n / 2);
    return 0;
}
