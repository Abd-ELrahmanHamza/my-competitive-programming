#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, x;
    unordered_map<long long, long long> mp;
    cin >> n;
    while (n--) {
        cin >> x;
        mp[x]++;
    }
    long long result = (mp[0] * (mp[0] - 1)) / 2;
    for (int i = 1; i <= 10; i++) {
        result += mp[i] * mp[-1 * i];
    }
    cout << result;
    return 0;
}
