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

bool isPrime(ll n) {
    if (n == 2)return true;
    if (n < 2 || n % 2 == 0)return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    string n;
    cin >> n;
    ll nll = stoi(n);
    std::reverse(n.begin(), n.end());
    ll nRev = stoi(n);
    bool isPrimen = isPrime(nll);
    bool isPrimeRev = isPrime(nRev);
    if ((isPrimen && !isPrimeRev) || (isPrimen && nll == nRev))
        cout << "LAB A";
    else if (!isPrimen)
        cout << "LAB B";
    else
        cout << "LAB C";
    return 0;
}
