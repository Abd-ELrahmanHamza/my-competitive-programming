#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long result=0,totalSum = 0;
    cin>>n;
    vector<int>v(n);
    for(int &x:v){
        cin>>x;
        result+=x;
    }
    totalSum = result;
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++){
        totalSum-=v[i];
        result+=totalSum+v[i];
    }
    cout<<result;
    return 0;
}
