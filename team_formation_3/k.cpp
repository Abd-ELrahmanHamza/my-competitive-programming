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
//    ll n;
//    cin >> n;
//    vector<pair<pair<int, int>, int>> v(n);
//    for (int i = 0; i < n; i++) {
//        v[i].second = i;
//        cin >> v[i].first.first >> v[i].first.second;
//    }
//    sort(v.begin(), v.end());
//    for (int i = 1; i < n; i++) {
//        if (v[i].first.second <= v[i - 1].first.second) {
//            cout << v[i].second+1;
//            return 0;
//        }
//        if (v[i - 1].first.first >= v[i].first.first) {
//            cout << v[i - 1].second+1;
//            return 0;
//        }
//        v[i].first.first = max(v[i].first.first, v[i - 1].first.second + 1);
//    }
//    cout<<-1;
//
//    return 0;
//}
