#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int cnt01 = 0, cnt02 = 0;

        for (int i = 0; i < n; i++) {
            if (i %2==0) {
                cnt01 += s1[i] == '0';
                cnt02 += s2[i] == '0';
            } else {
                cnt01 += s2[i] == '0';
                cnt02 += s1[i] == '0';
            }
        }

        if (cnt01>=(n+1)/2 && cnt02>=(n)/2) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
