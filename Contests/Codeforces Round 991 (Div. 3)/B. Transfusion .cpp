#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long long so = 0,se=0,n;
        cin>>n;
        long long ce = ceil(n/2.0), co = n/2;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            if (i&1)so+=x;
            else se+=x;
        }
        if ((so%co !=0) || (se%ce!=0)) {
            cout<<"NO"<<endl;
        }else {
            cout<< (so/co == se/ce?"YES":"NO")<<endl;
        }
    }
    return 0;
}
