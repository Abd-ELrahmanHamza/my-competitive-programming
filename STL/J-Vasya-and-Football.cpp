#include <bits/stdc++.h>

using namespace std;

int main() {
    string t1, t2;
    cin >> t1 >> t2;
    unordered_map<int, int> pt1, pt2;
    int n;
    cin >> n;
    while (n--) {
        int num, t;
        char ha, c;
        cin >> t >> ha >> num >> c;
        int tempNum = 0;
        if (c == 'y') {
            if (ha == 'h') {
                tempNum = ++pt1[num];
            } else {
                tempNum = ++pt2[num];
            }
        }
        if (c == 'r') {
            if (ha == 'h') {
                tempNum = pt1[num]+=2;
            } else {
                tempNum = pt2[num]+=2;
            }
        }
        if (tempNum >= 2) {
            if (ha == 'h') {
                cout << t1 << " ";
                pt1[num] = INT_MIN;
            } else {
                cout << t2 << " ";
                pt2[num] = INT_MIN;
            }
            cout << num << " " << t << endl;
        }
    }
    return 0;
}
