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
    /*
     *
For Division 1: 1900≤rating
For Division 2: 1600≤rating≤1899
For Division 3: 1400≤rating≤1599
For Division 4: rating≤1399*/
    ll t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n;
        unordered_map<int, int> uMap;
        bool found = false;
        while (n--) {
            cin >> x;
            uMap[x]++;
            if (uMap[x] >= 3 && !found) {
                cout << x << endl;
                found = true;
            }
        }
        if (!found)cout << -1 << endl;
    }
    return 0;
}
