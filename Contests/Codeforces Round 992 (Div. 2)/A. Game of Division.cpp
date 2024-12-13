#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        int res = -1;
        for(int i=0;i<n;i++) {
            bool valid = true;
            for(int j=0;j<n;j++) {
                if (i!=j&&abs(v[i] - v[j])%k == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res = i;
                break;
            }
        }
        if (res!=-1) {
            cout<<"YES"<<endl;
            cout<<res+1<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}