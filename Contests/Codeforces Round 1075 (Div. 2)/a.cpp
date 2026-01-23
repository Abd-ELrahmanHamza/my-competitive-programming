#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (arr[right] <= h && arr[left] <= l) {
                ans++;
                left++;
                right--;
            } else if (arr[right] <= l && arr[left] <= h) {
                ans++;
                left++;
                right--;
            } else {
                right--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}