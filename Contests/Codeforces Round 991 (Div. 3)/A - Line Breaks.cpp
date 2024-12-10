#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,res = 0;
        bool stop = false;
        cin>>n>>m;
        string s;
        for(int i=0;i<n;i++) {
            cin>>s;
            if (s.size()<=m && !stop) {
                res++;
                m-=s.size();
            }else {
                stop = true;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
