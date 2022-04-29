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
//    int n;
//    cin >> n;
//    vi v(n);
//    for (int &x: v)cin >> x;
//    int cnt = 1;
//    int maxCnt = INT_MIN;
//    bool removed = false;
//    vector<ll> startsum(n);
//    startsum[0] = 1;
//    vector<ll> endsum(n);
//    endsum[n - 1] = 1;
//    ll Maxresult = INT_MIN, result = 0;
//    for (int i = 1; i < n; i++) {
//        if (v[i] > v[i - 1]) {
//            startsum[i] = startsum[i - 1] + 1;
//            result++;
//        } else {
//            Maxresult = max(Maxresult, result);
//            result = 1;
//            startsum[i] = 1;
//        }
//    }
//    for (int i = n - 2; i >= 0; i++) {
//        if (v[i + 1] > v[i])
//            endsum[i] = endsum[i + 1] + 1;
//        else
//            endsum[i] = 1;
//    }
//    for (int i = 1; i <= n - 2; i++) {
//        if (v[i - 1] < v[i + 1])
//            Maxresult = max(startsum[i - 1] + endsum[i + 1], Maxresult);
//    }
//    cout << Maxresult;
//    return 0;
//}