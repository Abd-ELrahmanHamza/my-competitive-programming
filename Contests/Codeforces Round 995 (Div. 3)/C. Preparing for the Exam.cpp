#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> lists(m);
        vector<bool> knows(n+1);
        for(int i=0;i<m;i++) {
            cin>>lists[i];
        }
        for(int i=0;i<k;i++) {
            int x;
            cin>>x;
            knows[x] = true;
        }
        if (k<n-1) {
            for(int i=0;i<m;i++) {
                cout<<"0";
            }
            cout<<endl;
            continue;
        }
        int notKnows = -1;
        for(int i=1;i<=n;i++) {
            if(!knows[i]) {
                notKnows = i;
                break;
            }
        }
        for(int i=0;i<m;i++) {
            if (lists[i]==notKnows || notKnows == -1) {
                cout<<"1";
            }
            else {
                cout<<"0";
            }
        }
        cout<<endl;
    }
    return 0;
}