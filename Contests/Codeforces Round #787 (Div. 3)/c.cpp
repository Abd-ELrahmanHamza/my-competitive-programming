#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define rep(i, v) for(int i=0;i<v.size();++i)


int main() {
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool found0 = false, found1 = false;
        int first0 = -1;
        int last1 = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' && !found0) {
                first0 = i;
                found0 = true;
            }
            if (s[i] == '1') {
                last1 = i;
                found1 = true;
            }
        }
//        cout<<first0<<endl;
        int cnt = 1;
        if (!found0 && !found1) {
            cout << s.size() << endl;
        } else if (found0) {
            for (int i = first0 - 1; i >= 0; i--) {
                cnt++;
                if (s[i] == '1')
                    break;
            }
            cout << cnt << endl;
        } else {
            cout << s.size() - last1 << endl;
        }
    }
    return 0;
}
