//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> v(2 * n);
//        for (int &x: v)cin >> x;
//        vector<bool> a(n + 1);
//        vector<int> result;
//        for (int i = 0; i < 2 * n; i++) {
//            if (!a[v[i]]) {
//                a[v[i]] = true;
//                result.push_back(v[i]);
//            }
//        }
//        for (int x: result)cout << x << " ";
//        cout << endl;
//    }
//    return 0;
//}
