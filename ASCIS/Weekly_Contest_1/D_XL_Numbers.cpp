#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    long long a, b;
    cin >> a >> b;
    long long c = a + b;

    if ((a > 0 && b > 0 && c < 0) || (a < 0 && b < 0 && c > 0))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}