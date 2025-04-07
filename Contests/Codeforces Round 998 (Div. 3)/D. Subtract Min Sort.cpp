#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) {
            cin>>v[i];
        }
        bool valid = true;
        for(int i=0;i<n-1;i++) {
            if (v[i]<=v[i+1]) {
                v[i+1]-=v[i];
                v[i] = 0;
            }else {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
