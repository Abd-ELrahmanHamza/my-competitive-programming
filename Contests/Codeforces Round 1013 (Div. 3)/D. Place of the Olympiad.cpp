#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        long long l = 0, r = m;
        while(l<r-1) {
            long long mid = l + (r-l)/2;
            long long cntMid = m / (mid+1);
            long long rem = m - cntMid * (mid + 1);

            if (cntMid*mid*n + rem*n >= k) {
                r = mid;
            }else {
                l = mid;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}
