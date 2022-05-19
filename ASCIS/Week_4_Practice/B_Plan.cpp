#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define rep(i, v) for(int i=0;i<v.size();++i)

vll prime_factors(ll n) {
    vll primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        primes.push_back(n);
    return primes;
}

set<ll> prime_factors_set(ll n) {
    set<ll> primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes.insert(i);
            n /= i;
        }
    }
    if (n > 1)
        primes.insert(n);
    return primes;
}

ll binary_search_n(ll s, ll e, ll k) {
    ll middle = (s + e) / 2;
    if (k == middle)
        return 1;
    else if (k < middle)
        return 1 + binary_search_n(s, middle - 1, k);
    else
        return 1 + binary_search_n(middle + 1, e, k);
}

vll prefix_sum(vll v) {
    v.insert(v.begin(), 0);
    vll s(v.size());
    for (int i = 1; i < v.size(); ++i) {
        s[i] += v[i] + s[i - 1];
    }
    return s;
}

ll sum_range(int s, int e, vll &preSum) {
    return preSum[e] - preSum[s - 1];
}

ll binary_search_increasing(ll s, ll e, ll k, const vll &v) {
    if (e < s)
        return -1;

    ll middle = s + (e - s) / 2;
    if (k == v[middle])
        return middle;
    else if (k < v[middle])
        return binary_search_increasing(s, middle - 1, k, v);
    else
        return binary_search_increasing(middle + 1, e, k, v);
}

ll binary_search_decreasing(ll s, ll e, ll k, const vll &v) {
    if (e < s)
        return -1;

    ll middle = s + (e - s) / 2;
    if (k == v[middle])
        return middle;
    else if (k > v[middle])
        return binary_search_decreasing(s, middle - 1, k, v);
    else
        return binary_search_decreasing(middle + 1, e, k, v);
}

int main() {
    ll n, q;
    cin >> n >> q;
    vll v, v1(n), v2;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (v1[i] <= v1[i + 1]) {
            v.push_back(v1[i]);
            if (i == n - 2)
                v.push_back(v1[v1.size() - 1]);
        } else {
            v2.push_back(v1[i]);
            if (i == n - 2)
                v2.push_back(v1[v1.size() - 1]);
        }
    }
    while (q--) {
        ll x;
        cin >> x;

        ll result = binary_search_increasing(0, (int)v.size() - 1, x, v);
        if (result == -1 && !v2.empty()) {
            result = binary_search_decreasing(0, (int)v2.size() - 1, x, v2);
            if (result != -1)
                result += v.size();
        }

        if (result != -1) cout << "Yes " << result + 1 << endl;
        else cout << "No\n";
    }
    return 0;
}



//8 3
//60 57 52 33 27 17 12 4
//27
//15
//54