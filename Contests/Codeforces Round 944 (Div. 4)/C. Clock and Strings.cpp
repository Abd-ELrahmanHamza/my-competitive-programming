#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> v = {{0, 0},
                                    {0, 0},
                                    {0, 1},
                                    {0, 1}};
        for (int i = 0; i < 4; ++i) {
            cin >> v[i].first;
        }
        sort(v.begin(), v.end());
        if (v[0].second == v[1].second || v[1].second == v[2].second) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
