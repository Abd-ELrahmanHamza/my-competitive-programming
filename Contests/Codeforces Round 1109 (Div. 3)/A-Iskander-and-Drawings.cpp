#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0, res = 0;

    for (char c : s) {
      if (c == '#') {
        cnt++;
      } else {
        res = max(res, (cnt + 1) / 2);
        cnt = 0;
      }
    }

    res = max(res, (cnt + 1) / 2);

    cout << res << '\n';
  }
}
