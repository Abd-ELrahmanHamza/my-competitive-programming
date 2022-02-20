#include <bits/stdc++.h>

using namespace std;

bool isSuffix(const string &s1, const string &s2) {
    if (s1.size() < s2.size() || s1.size() == 0 || s2.size() == 0) return false;
    return s1.compare(s1.size() - s2.size(), s2.size(), s2) == 0;
}

int main() {
    string s;
    int t, n;
    string number;
    cin >> t;
    unordered_map<string, vector<string>> mp;
    while (t--) {
        cin >> s;
        cin >> n;
        while (n--) {
            cin >> number;
            mp[s].push_back(number);
        }
    }
    cout << mp.size() << endl;
    int cnt = 0;
    for (auto p: mp) {
        cnt = 0;
        for (int i = 0; i < p.second.size(); i++) {
            for (int j = 0; j < p.second.size(); j++) {
                if (i != j && isSuffix(p.second[i], p.second[j])) {
                    p.second[j] = "";
                    cnt++;
                }
            }
        }
        cout << p.first << " " << (int) p.second.size() - cnt << " ";
        for (auto &tempS: p.second)
            if (tempS != "")
                cout << tempS << " ";
        cout << endl;
    }
    return 0;
}
