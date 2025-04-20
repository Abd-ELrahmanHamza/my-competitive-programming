#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int l = 0, r = n - 1;
        bool flag = false;
        while (l < n) {
            if (s[l] < s[r]) {
                flag = true;
                break;
            }
            if (s[l]>s[r]) {
                break;
            }
            l++;
            r--;
        }
        if (flag) {
            cout<<"YES"<<endl;
        }else {
            if (k==0) {
                cout<<"NO"<<endl;
            }else {
                vector<bool>v(26);
                int cnt = 0;
                for (char c:s) {
                    if (!v[c-'a'])cnt++;
                    v[c-'a'] = true;
                }
                if (cnt>1) {
                    cout<<"YES"<<endl;
                }else {
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    return 0;
}
