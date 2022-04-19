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

#define all(v) ((v).begin()), ((v).end())

#define rep(i, v) for(int i=0;i<v.size();++i)

int main() {
    ll t;
    cin >> t;
    while (t--) {
        vll v(3);
        ll maxElem = INT_MIN;
        for (int i = 0; i < 3; i++) {
            cin >> v[i];
            maxElem = max(maxElem, v[i]);
        }
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            if (v[i] == maxElem)cnt++;
        }
        int dummy = 0;
        if (cnt > 1)dummy = 1;
        for (int i = 0; i < 3; i++) {
            if (v[i] < maxElem)cout << (maxElem - v[i]) + 1 << " ";
            else cout << dummy << " ";
        }
        cout << endl;
    }
    return 0;
}
