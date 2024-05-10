#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int l = 0, r = 0;
        vector<int> v;
        while (l < s.size()) {
            while (r < s.size() && s[r] == s[l]) {
                r++;
            }
            v.push_back(s[l]);
            l = r;
        }
        int found = 0;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i - 1] == '0' && v[i] == '1') {
                found = 1;
                break;
            }
        }
        cout << v.size() - found << endl;

    }
    return 0;
}
