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
////    if(i*i == n)
////        v.push_back(i);
//    return v;
//}
//
//int main() {
//    ll n;
//    string s;
//    cin >> n >> s;
//    for(int i=1;i<=n;++i){
//        if(n%i==0) {
////            cout<<i<<endl;
//            reverse(s.begin(), s.begin() + i);
//        }
//    }
//    cout<<s;
//
//    return 0;
//}
