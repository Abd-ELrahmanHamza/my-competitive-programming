#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int res = 0;
        int curZCnt = 0;
        bool skip = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (skip) {
                skip = false;
                continue;
            }
            if (x == 0) {
                curZCnt++;
                if (curZCnt == k) {
                    curZCnt = 0;
                    res++;
                    skip = true;
                }
            } else {
                curZCnt = 0;
            }
        }
        cout << res << endl;
    }
    return 0;
}