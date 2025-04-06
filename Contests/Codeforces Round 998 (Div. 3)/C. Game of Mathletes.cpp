#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int l = 0, r = n-1, cnt = 0;
        while (l < r) {
            if (v[l]+v[r] == k) {
                cnt++;
                l++;
                r--;
            }else if (v[l]+v[r]<k) {
                l++;
            }else {
                r--;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
