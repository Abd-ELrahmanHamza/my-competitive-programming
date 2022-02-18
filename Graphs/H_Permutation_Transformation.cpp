//#include <bits/stdc++.h>
//
//using namespace std;
//int maxD = INT_MIN;
//
//void solve(const vector<int> &v, vector<int>& result, vector<int>::iterator l, vector<int>::iterator r, int cnt) {
//    if (r == v.begin() - 1 || l == v.end())
//        return;
//    if (l > r)
//        return;
//    cnt++;
//    auto it = max_element(l, r + 1);
//    int x = it - v.begin();
//    result[x] = cnt - 1;
//    if (l == r) {
//        maxD = max(maxD, cnt);
//        return;
//    }
//
//    solve(v, result, it + 1, r, cnt);
//    solve(v, result, l, it - 1, cnt);
//}
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> v(n);
//        vector<int> result(n, -1);
//        for (int &x: v)cin >> x;
//        maxD = INT_MIN;
//        solve(v, result, v.begin(), v.end() - 1, 0);
//        for (int &x: result)cout << x << " ";
//        cout << endl;
//    }
//    return 0;
//}