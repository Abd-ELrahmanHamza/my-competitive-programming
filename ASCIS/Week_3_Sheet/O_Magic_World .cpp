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
    vi bronze(n);
    vi bronzeToGold(n);
    vi silver(n);
    for (int &x: bronze)cin >> x;
    for (int &x: bronzeToGold)cin >> x;
    for (int &x: silver)cin >> x;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        silver[i] *= x;
    }
    int maxV = INT_MIN;
    int maxI = 0;
    for (int i = 0; i < n; ++i) {
        int v = bronze[i] / min(bronzeToGold[i], silver[i]);
        if (v > maxV) {
            maxV = v;
            maxI = i + 1;
        }
    }
    cout << maxI;
    return 0;
}
