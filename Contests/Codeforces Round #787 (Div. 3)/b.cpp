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
        int n;
        cin >> n;
        vi v(n);
        for (int &x: v)cin >> x;
        int cnt = 0;
        bool result = true;
        for (int i = n - 2; i >= 0; i--) {
            if (v[i + 1] == 0) {
                result = false;
                break;
            }
            if (v[i] == 2 * v[i + 1]) {
                cnt += 2;
                v[i] = v[i]/4;
            } else if (v[i] >= v[i + 1]) {
                int a= 0;
                while(v[i]>=v[i+1]){
                    v[i]/=2;
                    a++;
                }
                cnt += a ;
            }
        }
        if (result)cout << cnt << endl;
        else cout << -1 << endl;
    }
    return 0;
}
