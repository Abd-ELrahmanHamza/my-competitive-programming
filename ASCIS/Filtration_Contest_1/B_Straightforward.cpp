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
    int result = 0;
    for (char c: s) {
        result += ((c - '0') % 2);
    }
    cout<<result;
    return 0;
}
