#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<bool> v(n+1);
        int j = 1;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            if (!v[x]) {
                cout<<x<<" ";
                v[x]=true;
            }else {
                while (j<=n && v[j]) {
                    j++;
                }
                cout<<j<<" ";
                v[j] = true;
            }
        }
        cout<<endl;
    }
}