#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int i = s.length()-1;
        while (s[i]=='0')i--;
        int nonZeros = 0;
        for (int j = 0; j < i; j++) {
            if (s[j]!='0')nonZeros++;
        }
        cout<<(s.size()-i-1) + nonZeros<<endl;
    }
    return 0;
}

