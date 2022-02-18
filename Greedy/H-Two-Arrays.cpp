//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, t;
//        cin >> n >> t;
//        vector<int> v(n);
//        for (int &x: v)cin >> x;
//        unordered_map<int, int> mp;
//        int hcnt = 0;
//        for (int i = 0; i < n; i++) {
//            if (v[i] * 2 == t)
//                hcnt++;
//            else if (v[i] > t) {
//                mp[v[i]] = 1;
//            } else if (mp[v[i]] == 0) {
//                mp[v[i]] = 1;
//                mp[t - v[i]] = 2;
//            }
//        }
//        hcnt = ceil(hcnt / 2.0);
//        for (int i = 0; i < n; i++) {
//            if (v[i] * 2 == t) {
//                if (hcnt != 0) {
//                    cout << 1 << " ";
//                    hcnt--;
//                }
//                else
//                    cout << 0 << " ";
//            } else {
//                cout << mp[v[i]]-1 << " ";
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}
