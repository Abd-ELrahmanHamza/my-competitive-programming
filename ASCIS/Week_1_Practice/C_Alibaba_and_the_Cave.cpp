#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    vector<ll> v(4);
    for (ll &x: v) cin >> x;
    ll a = v[0], b = v[1], c = v[2], d = v[3];
    if (a + b - c == d) {
        cout << "YES";
        return 0;
    }
    else if (a + b * c == d) {
        cout << "YES";
        return 0;
    }
    else if (a - b + c == d) {
        cout << "YES";
        return 0;
    }
    else if (a - b * c == d) {
        cout << "YES";
        return 0;
    }
    else if (a * b + c == d) {
        cout << "YES";
        return 0;
    }
    else if (a * b - c == d) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
