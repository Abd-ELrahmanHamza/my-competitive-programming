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
    vector<char> v(1);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
//        cout<<"front:"<<v.back()<<endl;
        if (c != v.back()) {
            v.push_back(c);
        }
    }
    int q;
    cin >> q;
//    for(char c:v)cout<<c<<" ";
    while (q--) {
        char c;
        cin >> c;
        if (c != v.back())
            v.push_back(c);
        cout<<v.size()-1<<endl;
    }
    return 0;
}
