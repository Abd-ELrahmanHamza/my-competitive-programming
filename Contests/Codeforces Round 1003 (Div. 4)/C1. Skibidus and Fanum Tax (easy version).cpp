#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<m;i++) {
            cin>>b[i];
        }
        bool valid = true;
        a[n-1] = max(a[n-1],b[0]-a[n-1]);
        for(int i=n-2;i>=0;i--) {
            if (a[i]<=a[i+1]&&(b[0]-a[i])<=a[i+1]) {
                a[i] = max(a[i],b[0]-a[i]);
            }else if ((b[0]-a[i])<=a[i+1]) {
                a[i] = b[0]-a[i];
            }else if (a[i]>a[i+1]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}