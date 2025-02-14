#include<bits/stdc++.h>
using namespace std;

int closestFromLeft(vector<int>& b, int ai1,int ai) {
    int left = -1, right = b.size();
    while (left < right-1) {
        int mid = left + (right - left) / 2;
        int x = b[mid] - ai;
        if (x<=ai1) {
            left = mid;
        }else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(m);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<m;i++) {
            cin>>b[i];
        }
        sort(b.begin(),b.end());
        bool valid = true;
        a[n-1] = max(a[n-1],b[m-1]-a[n-1]);
        for(int i=n-2;i>=0;i--) {
            int bleft = closestFromLeft(b,a[i+1],a[i]);
            if (bleft ==-1) {
                if (a[i]>a[i+1]) {
                    valid = false;
                    break;
                }
                continue;
            }
            if (a[i]<=a[i+1]&&(b[bleft]-a[i])<=a[i+1]) {
                a[i] = max(a[i],b[bleft]-a[i]);
            }else if ((b[bleft]-a[i])<=a[i+1]) {
                a[i] = b[bleft]-a[i];
            }else if (a[i]>a[i+1]) {
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