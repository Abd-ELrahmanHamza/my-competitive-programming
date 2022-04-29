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
//    ll n, k;
//    cin >> n >> k;
//    string s;
//    cin >> s;
//    int i = 0;
//    if (n == 1 && k != 0) {
//        cout << 0;
//        return 0;
//    }
//    while (i < n && k != 0) {
//        if (i == 0 && s[i] != '1') {
//            s[i] = '1';
//            k--;
//        } else if (i != 0 && s[i] != '0') {
//            s[i] = '0';
//            k--;
//        }
//        i++;
//    }
//    cout << s;
//    return 0;
//}
