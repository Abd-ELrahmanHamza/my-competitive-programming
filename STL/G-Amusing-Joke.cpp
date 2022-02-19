#include <bits/stdc++.h>

using namespace std;
int main() {
    string s1,s2,chs;
    cin>>s1>>s2>>chs;
    vector<int>v(26);
    if(s1.size()+s2.size() !=chs.size()){
        cout<<"NO";
        return 0;
    }
    for(auto c:s1) v[c-'A']++;
    for(auto c:s2) v[c-'A']++;
    for(auto c:chs){
        if(v[c-'A']==0){
            cout<<"NO";
            return 0;
        }
        v[c-'A']--;
    }
    cout<<"YES";
    return 0;
}
