//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//typedef unsigned long long ull;
//typedef long double ld;
//
//typedef vector<int> vi;
//typedef vector<long long> vll;
//typedef vector<double> vd;
//typedef vector<vi> vvi;
//typedef vector<string> vs;
//
//
//int main() {
//    ll t;
//    cin>>t;
//    while(t--) {
//        ll n, m;
//        cin >> n >> m;
//        vll v(n), v2(n), result(n);
//        for (ll &x: v)cin >> x;
//        for (int i = 0; i < m; i++) {
//            ll a, b;
//            cin >> a >> b;
//            v2[a - 1] += b;
//        }
////        for(ll x:v)cout<<x<<" ";
//        ll overflow = 0;
//        for (int i = 0; i < n; i++) {
//            v2[i] += overflow;
//            result[i] = min(v[i], v2[i]);
//            overflow = v2[i] - result[i];
//        }
//        cout << overflow << endl;
//        for (int i=0;i<n;i++){
//            cout << result[i] << (i!=n-1?" ":"");
//        }
//        cout << endl;
//    }
//    return 0;
//}
