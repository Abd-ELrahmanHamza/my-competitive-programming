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
    int n;
    cin >> n;
    vll v(25);
    while (n--) {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; i++)
            v[i]++;
    }
    cout << *max_element(v.begin(), v.end());
    return 0;
}
