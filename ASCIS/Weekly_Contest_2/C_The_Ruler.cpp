#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

struct rect {
    ll x1, x2, y1, y2;

    rect(ll x1, ll y1, ll x2, ll y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }

    void print() const {
        printf("(%d,%d) , (%d,%d)\n", x1, y1, x2, y2);
    }
};

int main() {
    int n;
    cin >> n;
    ll x1 = INT_MAX, x2 = INT_MAX, y1 = INT_MAX, y2 = INT_MAX;
    ll rx1 = INT_MIN, rx2 = INT_MAX, ry1 = INT_MAX, ry2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        rx1 = max(x1, rx1);
        rx2 = min(x2, rx2);
        ry1 = min(y1, ry1);
        ry2 = max(y2, ry2);
    }
    if (rx1 > rx2 || ry2 > ry1) {
        cout << 0;
        return 0;
    }
    ll result = (abs(rx2 - rx1) + 1) * (abs(ry2 - ry1) + 1);
    cout << result;
    return 0;
}
