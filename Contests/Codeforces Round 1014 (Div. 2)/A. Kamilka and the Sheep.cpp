#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int minE = INT_MAX, maxE = INT_MIN;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            minE = min(minE,x);
            maxE = max(maxE,x);
        }
        cout<<maxE-minE<<endl;
    }
    return 0;
}
