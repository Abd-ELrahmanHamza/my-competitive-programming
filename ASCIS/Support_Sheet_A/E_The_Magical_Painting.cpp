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

int n, m, q;

bool valid(int i, int j) {
    return i < n && i >= 0 && j < m && j >= 0;
}

int main() {
    cin >> n >> m >> q;
    vector<vector<bool>> v(n, vector<bool>(m));
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        v[r][c].flip();
        if (valid(r - 1, c))
            v[r - 1][c].flip();
        if (valid(r, c - 1))
            v[r][c - 1].flip();
        if (valid(r + 1, c))
            v[r + 1][c].flip();
        if (valid(r, c))
            v[r][c + 1].flip();
    }
    for(auto a:v){
        for(auto x:a){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
