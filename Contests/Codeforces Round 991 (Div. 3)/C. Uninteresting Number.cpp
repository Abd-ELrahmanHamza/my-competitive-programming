#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        long long total = 0;
        int cnt2 = 0, cnt3 = 0;
        bool res = false;
        for (int i = 0; i < s.length(); i++)
        {
            total += s[i] - '0';
            if (s[i] == '2')
                cnt2++;
            else if (s[i] == '3')
                cnt3++;
        }
        for (int i = 0; i <= cnt2; i++)
        {
            int md = (total + 2 * i) % 9;
            if (md == 0 || (md == 3 && cnt3 >= 1) || (md == 6 && cnt3 >= 2))
            {
                res = true;
                break;
            }
        }
        if (res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
