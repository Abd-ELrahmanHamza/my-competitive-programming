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
//vector<ll> factorize(ll n) {
//    vector<ll> v;
//    int i = 1;
//    for (i = 1; i * i < n; i++) {
//        if (n % i == 0) {
//            v.push_back(i);
//            v.push_back(n / i);
//        }
//    }
//    return v;
//}
//
//int main() {
//    ll n;
//    cin>>n;
//    vll v(n);
//    for (ll &x: v)cin >> x;
//    vll result;
//    for(int i=1;i<n;i++){
//        if(v[i]==1)
//            result.push_back(v[i-1]);
//    }
//    result.push_back(v[n-1]);
//    cout<<result.size()<<endl;
//    for(ll x:result)cout<<x<<" ";
//    return 0;
//}
