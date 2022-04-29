//#include <bits/stdc++.h>
//
//using namespace std;
//typedef long long ll;
//typedef unsigned long long ull;
//typedef long double ld;
//
//typedef vector<iAnt> vi;
//typedef vector<long long> vll;
//typedef vector<double> vd;
//typedef vector<vi> vvi;
//typedef vector<string> vs;
//
//ull gcd(ull a, ull  b)
//{
//    if (b == 0)
//        return a;
//    return gcd(b, a % b);
//}
//
//ull lcm(ull a, ull b) {
//    return (a / gcd(a, b)) * b;
//}
//
//int main() {
//    ull n;
//    cin >> n;
//    ull limit = sqrt(n);
//    ull result = ULONG_LONG_MAX;
//    for (ull i = 1; i <= limit; i++) {
//        if (n % i == 0 && lcm(i, n / i) == n) {
//            result = min(result, max(i, n / i));
//        }
//    }
//    cout << n / result << " " << result;
//    return 0;
//}