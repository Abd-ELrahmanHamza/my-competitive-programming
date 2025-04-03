#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        set<int> s;
        s.insert(a1 + a2);
        s.insert(a4 - a2);
        s.insert(a5 - a4);
        cout << 4 - s.size() << endl;
    }
    return 0;
}
