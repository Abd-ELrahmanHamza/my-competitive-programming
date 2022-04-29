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
//int product(int x) {
//    int prod = 1;
//    while (x) {
//        prod *= (x % 10);
//        x /= 10;
//    }
//    return prod;
//}
//
//int findNumber(int r) {
//    string n = to_string(r);
//    int ans = r;
//    for (int i = 0; i < n.size(); i++) {
//        if (n[i] == '0')
//            continue;
//        string curr = n;
//        curr[i] = ((curr[i] - '0') - 1) + '0';
//        for (int j = i + 1; j < curr.size(); j++)
//            curr[j] = '9';
//        int num = 0;
//        for (auto c: curr)
//            num = num * 10 + (c - '0');
//        if (product(ans) < product(num))
//            ans = num;
//    }
//
//    return product(ans);
//}
//
//int main() {
//    int n2;
//    cin >> n2;
//    cout << findNumber(n2) << endl;
//    return 0;
//}