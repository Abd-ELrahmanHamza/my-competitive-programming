#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x: v)cin >> x;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] < v[i + 1])
            cnt++;
        else break;
    }
    cout << cnt;
    return 0;
}
