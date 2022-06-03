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

bool compare(pair<ll, pair<ll, string>> p1, pair<ll, pair<ll, string>> p2) {
    if (p1.first < p2.first)
        return true;
    if (p1.first == p2.first) {
        return p1.second.first > p2.second.first;
    }
    return false;
}

int main() {
    string dummy;
    ll n;
    cin >> n;
    getline(cin, dummy);
    unordered_map<ll, ll> m;
    ll sum = 0;
    ll cnt = 0;
    while (n--) {
        char c = '.';
        ll x;
        string s;
        getline(cin, s);
        //cout<<s<<endl;
        cout << fixed << setprecision(7);
        if (s.find(' ') == 1) {
            c = s[0];
            x = stoi(s.substr(2));
        } else {
            x = stoi(s.substr(3));
            sum -= m[x] * x;
            cnt -= m[x];
            m[x] = 0;
            if (cnt == 0) {
                cout << 0 << endl;
            } else
                cout << (double) sum / (double) cnt << endl;
        }
        if (c == '+') {
            m[x]++;
            sum += x;
            cnt++;
            if (cnt == 0) {
                cout << 0 << endl;
            } else
                cout << (double) sum / (double) cnt << endl;
        } else if (c == '-') {
            if (m[x] > 0) {
                sum -= x;
                cnt--;
                m[x]--;
            }
            if (cnt == 0) {
                cout << 0 << endl;
            } else
                cout << (double) sum / (double) cnt << endl;
        }
    }
    return 0;
}
/*
2
+ 10
- 10

 */