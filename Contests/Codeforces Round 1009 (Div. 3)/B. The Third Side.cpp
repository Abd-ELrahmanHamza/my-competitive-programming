#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        priority_queue<int,vector<int>, greater<>> q;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            q.push(x);
        }
        while(q.size()>1) {
            int a=q.top();
            q.pop();
            int b = q.top();
            q.pop();
            q.push(a+b-1);
        }
        cout<<q.top()<<endl;
    }

    return 0;
}

