#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> AB, BA;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'B')
            AB.push_back(i);
        else if (s[i] == 'B' && s[i + 1] == 'A')
            BA.push_back(i);
    }
    for (int i = 0; i < AB.size(); i++) {
        for (int j = 0; j < BA.size(); j++) {
            if (abs(AB[i] - BA[j]) != 1) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
