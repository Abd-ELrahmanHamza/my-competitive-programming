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
    string s;
    cin >> s;
    ll cnt = 0, maxS = LONG_LONG_MIN;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-')
            cnt++;
        else {
            maxS = max(maxS, cnt);
            cnt = 0;
            i++;
        }
    }
    maxS = max(maxS, cnt);
    cout << maxS;
    return 0;
}
