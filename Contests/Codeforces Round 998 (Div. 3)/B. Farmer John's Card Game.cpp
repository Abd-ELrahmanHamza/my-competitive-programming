#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        bool valid = true;
        set<pair<int,int> > s;
        for(int i=0;i<n;i++) {
            vector<int>v(m);
            for(int j=0;j<m;j++) {
                cin>>v[j];
            }
            sort(v.begin(),v.end());
            for(int j=1;j<m;j++) {
                if (v[j]-v[j-1]!=n) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                s.insert(make_pair(v[0],i+1));
            }
        }
        if (!valid) {
            cout<<-1<<endl;
        }else {
            for (auto p:s) {
                cout<<p.second<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
