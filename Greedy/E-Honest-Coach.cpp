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
//        vector<int> v(n);
//        for (int &x: v)cin >> x;
//        sort(v.begin(), v.end());
//        int minDiff = INT_MAX;
//        for (int i = 0; i < n - 1; i++) {
//            minDiff = min(minDiff, abs(v[i] - v[i + 1]));
//        }
//        cout << minDiff << endl;
//    }
//    return 0;
//}
