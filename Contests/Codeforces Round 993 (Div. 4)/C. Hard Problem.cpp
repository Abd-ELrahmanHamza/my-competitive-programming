#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        int res = 0;
        res +=min(m,a);
        res +=min(m,b);
        int rc = min(max(m-a,0),c);
        res+=rc;
        c-=rc;
        res+= min(max(m-b,0),c);
        cout<<res<<endl;
    }
}