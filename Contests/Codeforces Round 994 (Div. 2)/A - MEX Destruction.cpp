#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        bool isZero = true, isOne = true;
        for(int i=0;i<n;i++) {
            cin>>v[i];
            if(v[i]!=0) {isZero = false; }
        }
        bool prevNonZero = false;
        for(int i=1;i<n-1;i++) {
            if (v[i-1]!=0)prevNonZero = true;
            if (v[i]==0 && prevNonZero && v[i+1]!=0) {isOne = false; }
        }
        if (isZero) {cout<<0<<endl;}
        else if (isOne) {cout<<1<<endl;}
        else cout<<2<<endl;
    }
    return 0;
}