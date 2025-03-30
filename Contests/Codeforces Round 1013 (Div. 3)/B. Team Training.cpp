#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;
        priority_queue<int> q;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            q.push(x);
        }
        int curCnt = 0, curMin = INT_MAX, res = 0;
        while(!q.empty()) {
            curMin = min(curMin, q.top());
            curCnt++;
            q.pop();
            if (curCnt*curMin>=x) {
                res++;
                curCnt = 0, curMin = INT_MAX;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
