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
//    ll t;
//    cin >> t;
//    while (t--) {
//        ll n;
//        cin >> n;
//        // min
//
//        if (n == 5)cout << 2 << " ";
//        else if (n == 4)cout << 4 << " ";
//        else if (n == 3)cout << 7 << " ";
//        else if (n == 2)cout << 1 << " ";
//        else if (n == 7)cout << 8 << " ";
//        else if (n == 6)cout << 14 << " ";
//        else {
//            cout << 1;
//            ll num0 = (n - 2) / 6;
//            ll rem = n - num0 * 6;
//            if (rem == 1) {
//                rem = 7;
//                num0--;
//            }
//            for (int i = 0; i < num0; i++)cout << 0;
//            if (rem == 5)cout << 2 << " ";
//            else if (rem == 4)cout << 4 << " ";
//            else if (rem == 3)cout << 7 << " ";
//            else if (rem == 2)cout << 1 << " ";
//            else if (rem == 7)cout << 8 << " ";
//        }
//
//        // max
//        if (n % 2 == 0) {
//            ll num = n / 2;
//            for (int i = 0; i < num; i++)cout << 1;
//        } else {
//            cout << 7;
//            ll num = (n - 3) / 2;
//            for (int i = 0; i < num; i++)cout << 1;
//        }
//        cout << endl;
//    }
//    return 0;
//}
