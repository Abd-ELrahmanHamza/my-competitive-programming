//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, k;
//        cin >> n >> k;
//        vector<int> a(n), b(n);
//        for (int &x: a)cin >> x;
//        for (int &x: b)cin >> x;
//        sort(a.begin(), a.end());
//        sort(b.begin(), b.end(), greater<int>());
//        long long sum = 0;
//        for (int i = 0; i < k; i++)sum += max(b[i],a[i]);
//        for (int i = k; i < n; i++)sum += a[i];
//        cout << sum << endl;
//    }
//    return 0;
//}
