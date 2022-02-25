#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.size() % 2 != 0) {
        cout << -1;
        return 0;
    }
    int l = count(s.begin(), s.end(), 'L');
    int r = count(s.begin(), s.end(), 'R');
    int u = count(s.begin(), s.end(), 'U');
    int d = s.size() - (l + r + u);
    int abslr = abs(r - l);
    int absud = abs(u - d);
    cout << min(abslr, absud) + abs(abslr - absud)/2;
    return 0;
}
