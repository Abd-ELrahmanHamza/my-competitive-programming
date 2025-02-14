#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long long n,x,y,s=0;
        cin>>n>>x>>y;
        vector<long long> v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
            s += v[i];
        }
        long long x2 = s - x;
        long long y2 = s - y;
        cout<<"Pairs are: "<<x2<<" "<<y2<<endl;
        sort(v.begin(),v.end());
        long long res = 0;
        for(int i=0;i<n;i++) {
            if (x2 - v[i] < v.front() || y2 - v[i] > v.back()) {
                continue;
            }
            cout<<"here\n";
            auto u = upper_bound(v.begin(),v.end(),x2 - v[i]);
            auto l = lower_bound(v.begin(),v.end(),y2 - v[i] );
            long long toAdd = u - l;
            if (x2 - v[i] >= v[i] && y2 - v[i] <= v[i]) {
                toAdd--;
            }
            res +=toAdd;
        }
        cout<<(int)ceil(res/2.0)<<endl;
    }
    return 0;
}