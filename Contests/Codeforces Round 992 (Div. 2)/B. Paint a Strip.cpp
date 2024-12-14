#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int s = 1;
        int res = 1;
        while (s < n) {
            s =(s+1)*2;
            res++;
        }
        cout<<res<<endl;
    }
    return 0;
}