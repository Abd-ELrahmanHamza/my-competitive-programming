#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> freq(10);
        int res =  0;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            freq[x]++;
            if (res==0 && freq[0]>=3 && freq[1]>=1 && freq[2]>=2 && freq[3]>=1 && freq[5] >= 1) {
                res = i+1;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
