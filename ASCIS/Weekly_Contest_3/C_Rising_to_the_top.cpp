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
    vll v(n), summm(n + 1);
    for (int i = 0; i < n; i++)cin >> v[i];
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++) {
        summm[i] += summm[i - 1] + v[i - 1];
    }
    while (q--) {
        int op;
        cin >> op;
        switch (op) {
            case 1:
                int l, r;
                cin >> l >> r;
                cout << summm[r] - summm[l - 1] << endl;
                break;
            case 2:
                ll x;
                cin >> x;
                summm.push_back(x);
                summm[summm.size() - 1] = summm[summm.size() - 1] + summm[summm.size() - 2];
                break;
            case 3:
                summm.pop_back();
                break;
        }
    }
    return 0;
}
