#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,p;
        cin>>n>>k>>p;
        k = abs(k), p = abs(p);
        int res = ceil((double)k/(double)p);
        if ( res<= n) {
            cout<<res<<endl;
        } else {
            cout<<-1<<endl;
        }
    }

    return 0;
}