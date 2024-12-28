#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long long n,a,b,c;
        cin>>n>>a>>b>>c;
        long long res = (n)/ (a+b+c);
        long long covered = res * (a+b+c);
        res*=3;
        if (covered <n)res++;
        covered+=a;
        if (covered <n)res++;
        covered+=b;
        if (covered<n)res++;
        cout<<res<<endl;
    }
    return 0;
}