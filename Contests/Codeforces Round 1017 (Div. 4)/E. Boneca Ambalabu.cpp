#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>bits(31);
        vector<long long> elements(n);
        for(int i=0;i<n;i++) {
            long long x;
            cin>>x;
            elements[i] = x;
            int j = 0;
            while (x) {
                bits[j]+= x&1L == 1;
                x = x>>1;
                j++;
            }
        }

        long long res = 0;
        for (long long x: elements) {
            long long curSum = 0;
            for (int i = 0;i<31;i++) {
                if (x&(1<<i)) {
                    curSum += (1L<<i) * (long long)(n-bits[i]);
                }else {
                    curSum += (1L<<i) * (long long)bits[i];
                }
            }
            res = max(res, curSum);
        }
        cout<<res<<endl;
    }

    return 0;
}
