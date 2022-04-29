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
//int main() {
//    ll n;
//    cin >> n;
//    n = 2*n;
//    vll v(n);
//    for (ll &x: v)cin >> x;
//    sort(v.begin(), v.end());
//    ll sum1 = 0, sum2 = 0;
//    for (int i = 0; i < n / 2; i++) {
//        sum1 += v[i];
//    }
//    for (int i = n / 2; i < n; i++) {
//        sum2 += v[i];
//    }
//    if (sum1 == sum2)cout << -1;
//    else {
//        for (ll x: v)cout << x << " ";
//    }
//    return 0;
//}
