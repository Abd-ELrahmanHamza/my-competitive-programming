#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt = 0;
        string s;
        cin >> s;
        for (char& c : s) {
            cnt += c == s.back();
        }
        cout << (int)s.size() - cnt << endl;
    }
    return 0;
}