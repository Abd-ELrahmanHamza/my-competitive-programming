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
//    ll t;
//    cin >> t;
//    while (t--) {
//        string str1, str2;
//        cin >> str1 >> str2;
//        unordered_map<char, int> uMap;
//        for (char c: str1) {
//            uMap[c]++;
//        }
//        for (char c: str2) {
//            uMap[c]--;
//        }
//        int f = 0, s = 0;
//        for (auto p: uMap) {
//            if (p.second <= -1)f+=abs(p.second);
//            else if (p.second >= 1)s+= abs(p.second);
//        }
//        cout << min(f, s)*2 + abs(f - s) << endl;
//    }
//    return 0;
//}
