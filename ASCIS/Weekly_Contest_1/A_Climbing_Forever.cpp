#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll n, a, b, y;
    cin >> n >> a >> b;
    y = n / a;
    cout << (n * (n + 1) / 2) - (a * (y * (y + 1) / 2)) + (y * b) + (y * (y - 1) / 2);
    return 0;
}
