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

unordered_map<ll, ll> prime_factors_map(ll n, set<ll> &s) {
    unordered_map<ll, ll> primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes[i]++;
            s.insert(i);
            n /= i;
        }
    }
    if (n > 1) {
        s.insert(n);
        primes[n]++;
    }
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

bool isPrime(ll n) {
    if (n == 2)return true;
    if (n <= 2 || n % 2 == 0)return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPowerOfTwo(ll n) {
    ll x = n - 1;
    return (n & (x)) == 0;
}

ll power(ll x, ll y, ll mod = 1) {
    ll ans = 1;
    for (ll i = 0; i < y; i++) {
        ans = ((ans % mod) * (x % mod)) % mod;
    }
    return ans;
}

bool compare(pair<ll, char> p1, pair<ll, char> p2) {
    if (p1.first > p2.first)
        return true;
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    ll x = b;
    stack<ll> s;
    s.push(b);
    while (x >= a) {
        if (x == a) {
            cout << "YES\n";
            cout << s.size() << "\n";
            while (!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            return 0;
        }
        if (x % 2 == 0) {
            x /= 2;
        } else if ((x - 1) % 10 == 0) {
            x--;
            x /= 10;
        } else {
            cout << "NO";
            return 0;
        }
        s.push(x);
    }
    cout << "NO";
    return 0;
}
