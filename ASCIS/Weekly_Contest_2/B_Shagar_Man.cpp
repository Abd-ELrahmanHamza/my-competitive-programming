#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, m, p, a;
    bool result = true;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p;
        ll power = 0;
        result = true;
        for (int j = 0; j < m; j++) {
            power += p;
            cin >> a;
            if (power < a) {
                result = false;
            }
//            cout << "Power = " << power << " A = " << a << endl;
            power -= a;
        }
        if (!result)cout << "Upset ";
        else cout << "Happy ";
    }
    return 0;
}
