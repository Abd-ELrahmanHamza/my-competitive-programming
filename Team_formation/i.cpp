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
//    ll a, b, a1, b1, a2, b2;
//    cin >> a >> b >> a1 >> b1 >> a2 >> b2;
//    if (a1 + a2 <= a && b1 <= b && b2 <= b) cout<<"YES";
//    else if (a1 + a2 <= b && b1 <= a && b2 <= a) cout<<"YES";
//    else if (b1 + b2 <= a && a1 <= b && a2 <= b) cout<<"YES";
//    else if (b1 + b2 <= b && a1 <= a && a2 <= a) cout<<"YES";
//    else if (a1 + b2 <= a && b1 <= b && a2 <= b) cout<<"YES";
//    else if (a1 + b2 <= b && b1 <= a && a2 <= a) cout<<"YES";
//    else if (b1 + a2 <= a && a1 <= b && b2 <= b) cout<<"YES";
//    else if (b1 + a2 <= b && a1 <= a && b2 <= a) cout<<"YES";
//    else cout<<"NO";
//
//        return 0;
//}