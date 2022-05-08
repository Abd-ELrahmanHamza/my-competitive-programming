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
    ll n, x;
    cin >> n >> x;
    vll v(n);
    unordered_map<ll, ll> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s[v[i]]++;
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll rem = x - v[i];
        if (rem == v[i]) {
            cnt += s[rem] - 1;
//            cout<<s[rem]-1<<" "<<v[i]<<" "<<rem<<endl;
        }
        else {
            cnt += s[rem];
//            cout<<s[rem]<<" "<<v[i]<<" "<<rem<<endl;
        }
        s[v[i]]--;
    }
    cout << cnt;
    return 0;
}
