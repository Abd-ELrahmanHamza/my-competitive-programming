#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, string> mp;
    int n, m;
    cin >> n >> m;
    string s1, s2;
    while (n--) {
        cin >> s1 >> s2;
        mp[s2+";"] = s1;
    }
    while (m--) {
        cin >> s1 >> s2;
        cout << s1 << " " << s2 << " #" << mp[s2] << endl;
    }
    return 0;
}
