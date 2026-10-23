#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int x;
        string s;
        cin >> x >> s;
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                q.push_back(i);
            } else if (s[i] == '2') {
                if (!q.empty()) {
                    res.push_back(i);
                    q.pop_back();
                }
            }
        }
        cout << q.size() + res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            if (!q.empty()) {
                if (q.front() < res[i]) {
                    cout << q.front() + 1 << " ";
                    q.pop_front();
                    i--;
                } else {
                    cout << res[i] + 1 << " ";
                }
            } else {
                cout << res[i] + 1 << " ";
            }
        }
        while (!q.empty()) {
            cout << q.front() + 1 << " ";
            q.pop_front();
        }
        cout << endl;
    }
    return 0;
}
