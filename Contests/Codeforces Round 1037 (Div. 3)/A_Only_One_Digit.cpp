#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int minD = 9;
        while (x)
        {
            minD = min(minD, x % 10);
            x /= 10;
        }
        cout << minD << endl;
    }
    return 0;
}