#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    vector<pair<ull, string>> v(3);
    v[0].second = "Bedo";
    v[1].second = "Omar";
    v[2].second = "Tarek";
    cin >> v[0].first >> v[1].first >> v[2].first;
    sort(v.begin(), v.end());
    cout << v[1].second;
    return 0;
}
