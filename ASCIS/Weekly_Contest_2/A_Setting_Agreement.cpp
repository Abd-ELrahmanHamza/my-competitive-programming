#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, m, d, cnt = 0;
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
//        cout << x << endl;
        if (i % d == 0 && x % m == 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}
