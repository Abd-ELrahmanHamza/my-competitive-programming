#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<char>> grid(n, vector<char>(n)), reduced(n / k, vector<char>(n / k));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n; i += k) {
            for (int j = 0; j < n; j += k) {
                reduced[i / k][j / k] = grid[i][j];
            }
        }
        for (int i = 0; i < n / k; ++i) {
            for (int j = 0; j < n / k; ++j) {
                cout << reduced[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}