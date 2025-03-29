#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        if ((x & (x - 1)) == 0 || ((x+1) &x ) ==0 ) {
            cout<<-1<<endl;
            continue;
        }
        int l = (int)log2(x) ;
        cout<<(1<<l)-1<<endl;
    }

    return 0;
}

