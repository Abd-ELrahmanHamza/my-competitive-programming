#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<((n-1)/2) *2 +!(n&1)<<endl;
    }
}