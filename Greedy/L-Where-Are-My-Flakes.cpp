//#include <bits/stdc++.h>
//
//using namespace std;
//
//int convertToNum(string s) {
//    int result = s.front() - '0';
//    for (int i = 1; i < s.size(); i++) {
//        result = result * 10 + (s[i] - '0');
//    }
//    return result;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    int l = 1, r = n;
//    string s;
//    cin.get();
//    for (int i = 0; i < m; i++) {
//        getline(cin, s);
////        cout<<s<<endl;
//        int x;
//        if (s.find("right") != string::npos) {
//            x = convertToNum(s.substr(16));
//            l = max(x + 1,l);
//        } else {
//            x = convertToNum(s.substr(15));
//            r = min(x - 1,r);
//        }
//        if (l == n+1 || r == 0 || l > r) {
//            cout << -1;
//            return 0;
//        }
//    }
//    cout << r - l + 1;
//    return 0;
//}
