#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<int>v;
    while(n--){
        int x;
        cin>>x;
        if(x<0)
            v.push_back(x);
    }
    sort(v.begin(),v.end());
    int result = 0;
    int j=0;
    while(j<m && j<v.size()){
        result+=v[j];
        j++;
    }
    cout<<-1*result;
    return 0;
}
