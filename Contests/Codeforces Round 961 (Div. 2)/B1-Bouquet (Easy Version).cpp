#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int l = 0, r = 1, sumSoFar = v[0], maxSum = 0;
        set<int> ss;
        unordered_map<int, int> mm;
        mm[v[0]]++;
        ss.insert(v[0]);
        while (r < n) {
            bool exitDueTo2 = false;
            bool exitDueTo3 = false;
            while (r < n) {
                ss.insert(v[r]);
                if ((ss.size() == 2 && abs(*ss.begin() - *next(ss.begin())) != 1)) {
                    exitDueTo2 = true;
                    break;
                } else if (ss.size() > 2) {
                    exitDueTo3 = true;
                    break;
                } else if (sumSoFar + v[r] > m) {
                    break;
                }
                mm[v[r]]++;
                sumSoFar += v[r];
                r++;
            }
            maxSum = max(maxSum, sumSoFar);
            if (exitDueTo2) {
                while (l < r && ss.size() == 2) {
                    sumSoFar -= v[l];
                    mm[v[l]]--;
                    if (mm[v[l]] == 0) {
                        ss.erase(v[l]);
                    }
                    l++;
                }
            } else if (exitDueTo3) {
                while (l < r && ss.size() == 3) {
                    sumSoFar -= v[l];
                    mm[v[l]]--;
                    if (mm[v[l]] == 0) {
                        ss.erase(v[l]);
                    }
                    l++;
                }
            } else {
                while (l < r && sumSoFar > m) {
                    sumSoFar -= v[l];
                    mm[v[l]]--;
                    if (mm[v[l]] == 0) {
                        ss.erase(v[l]);
                    }
                    l++;
                }
            }
        }
        cout << maxSum << endl;
    }
    return 0;
}

//8 20
//4 2 7 5 6 1 1 1
//
//1 1 1 2 4 5 6 7