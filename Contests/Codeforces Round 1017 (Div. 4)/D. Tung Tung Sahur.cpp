#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        string s1,s2;
        cin>>s1>>s2;
        int l1 =0,l2=0, r1=0, r2=0;
        bool valid = true;
        while(r1<s1.size() && r2<s2.size()) {
            while (r1<s1.size() && s1[r1] == s1[l1]) {
                r1++;
            }
            while (r2<s2.size() && s2[r2] == s2[l2]) {
                r2++;
            }
            if (s1[l1] != s2[l2]) {
                valid = false;
                break;
            }
            int len1 = r1 - l1;
            int len2 = r2 - l2;
            if (!(len2>=len1 && len2<=2*len1)) {
                valid = false;
                break;
            }
            l1 = r1, l2 = r2;
        }
        if (r1!=s1.size() || r2!=s2.size()) {
            valid = false;
        }
        if (valid) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
