#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cs = 0, cp =0;
        for(int i=0;i<n;i++) {
            if (s[i]=='p')cp++;
            else if (s[i]=='s' ) {
                cs++;
            }
        }
        if (cs==0 || cp==0) {
            cout<<"YES"<<endl;
        }else if ((s.front()=='s' && cs == 1)|| (s.back()=='p' && cp==1)) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}