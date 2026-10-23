#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x0, y0, r, y;
    cin >> x0 >> y0 >> r;
    y = y0;
    while ((y0 - y) * (y0 - y) < r * r) {
      y++;
    }
    cout << x0 << " " << y << endl;
  }
  return 0;
}
