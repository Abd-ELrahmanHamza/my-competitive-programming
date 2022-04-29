#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<string> vs;

vector<char> decimalTobinary(ull num) {
    vector<char> result;
    while (num) {
        if ((num & 1) == 1) result.push_back('1');
        else result.push_back('0');
        num = num >> 1;
    }
//    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ull a, b;
        cin >> a >> b;
        if ((a | b) == a) {
            cout << (a ^ b) << endl;

        } else cout << -1 << endl;
    }
    return 0;
}
