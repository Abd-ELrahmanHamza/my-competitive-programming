#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int h, m;
    char x, y;
    cin >> h >> m >> x >> y;
    if (h == 12)h = 0;
    cout << setw(2) << setfill('0') << (x == 'A' ? h : h + 12) << ":" << setw(2) << setfill('0') << m;
    return 0;
}