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

bool isPrime(ll n) {
    if (n == 2)return true;
    if (n < 2 || n % 2 == 0)return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    unordered_map<int, ll> uMap;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        uMap[x]++;
    }
    ll m = LONG_LONG_MIN;
    int result = -1;
    for (auto p: uMap) {
        if (p.second > m) {
            m = p.second;
            result = p.first;
        } else if (p.second == m) {
            result = min(result, p.first);
        }
    }
    cout << result;
    return 0;
}
