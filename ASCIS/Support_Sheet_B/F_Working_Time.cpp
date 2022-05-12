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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string start, end;
        ll result = 0;
        ll totalMin = 0;
        for (int i = 0; i < n; ++i) {
            cin >> start >> end;
            int startH = stoi(start.substr(0, 2));
            int startM = stoi(start.substr(3, 2));
            int endH = stoi(end.substr(0, 2));
            int endM = stoi(end.substr(3, 2));
            result += endH - startH;
            if (startM > endM) {
                result--;
                totalMin += (endM + 60) - startM;
            } else
                totalMin += endM - startM;
        }
        result += totalMin / 60;
        if (result >= m)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
