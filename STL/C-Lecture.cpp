#include <bits/stdc++.h>

using namespace std;
int main() {
    unordered_map<string,string>mp;
    int n,m;
    cin>>n>>m;
    string s1,s2;

    for(int i=0;i<m;i++){
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    for(int i=0;i<n;i++){
        cin>>s1;
        if(mp[s1].size()<s1.size()){
            cout<<mp[s1]<<" ";
        }else{
            cout<<s1<<" ";
        }
    }
    return 0;
}
