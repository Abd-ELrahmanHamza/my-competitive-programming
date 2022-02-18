#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>k>>n>>m;
        vector<int>result,a(n),b(m);
        int linesCnt = k;
        int i=0,j=0;
        for(int &x:a)cin>>x;
        for(int &x:b)cin>>x;
        bool done = false;
        while(i<n||j<m){
            bool changed1 = false,changed2=false;
            while(i<n){
                if(a[i]==0)
                    linesCnt++;
                else{
                    if(a[i]>linesCnt)
                        break;
                }
                result.push_back(a[i]);
                changed1=true;
                i++;
            }
            while(j<m){
                if(b[j]==0)
                    linesCnt++;
                else{
                    if(b[j]>linesCnt)
                        break;
                }
                result.push_back(b[j]);
                changed2=true;
                j++;
            }
            if(!changed1&&!changed2){
                cout<<-1;
                done =  true;
                break;
            }
        }
        if(!done){
            for(int x:result)
                cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
