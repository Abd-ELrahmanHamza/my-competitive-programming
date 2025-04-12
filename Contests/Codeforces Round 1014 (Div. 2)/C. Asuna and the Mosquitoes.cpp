#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long res = 0;
        int maxE = INT_MIN;
        bool hasEven = false, hasOdd = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            maxE = max(maxE, x);
            if (x % 2 == 0) {
                hasEven = true;
                res += x;
            } else {
                hasOdd = true;
                res += x-1;
            }
        }
        if (!hasEven || !hasOdd) {
            cout<<maxE<<endl;
        }else {
            cout<<res+1<<endl;
        }

    }
    return 0;
}
