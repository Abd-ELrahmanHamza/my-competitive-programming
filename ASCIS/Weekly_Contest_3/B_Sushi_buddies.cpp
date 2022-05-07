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
    ll result = 1;
    cin>>n;
    set<ll>s;
    while (n--){
        ll x;
        cin>>x;
        s.insert(x);
    }
    for(auto x:s)
        result*=x;
    cout<<result;
    return 0;
}
