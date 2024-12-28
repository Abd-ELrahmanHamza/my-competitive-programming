#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n), b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        int res = a.back();
        for(int i=n-2;i>=0;i--) {
            if (a[i]>b[i+1]) {
                res+=a[i]-b[i+1];
            }
        }
        cout<<res<<endl;

    }
    return 0;
}