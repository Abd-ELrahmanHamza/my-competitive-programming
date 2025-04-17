#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(2*n+2,-1);
        vector<bool> taken(2*n+2);
        for(int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                int x;
                cin>>x;
                v[i+j]=x;
                taken[x]=true;
            }
        }
        for(int i=1;i<=2*n;i++) {
            if (v[i]==-1) {
                for(int j=1;j<=2*n;j++) {
                    if (!taken[j]) {
                        v[i]=j;
                        taken[j]=true;
                    }
                }
            }
        }
        for(int i=1;i<=2*n;i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
