#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        long long a = 0,b= 0;
        for(int i=0;i<n;i++) {
            char c;
            cin>>c;
            if(c=='-') a++;
            else b++;
        }
        cout<<(long long)ceil((double)a/(double)2) * b* (a/2)<<endl;
    }

    return 0;
}