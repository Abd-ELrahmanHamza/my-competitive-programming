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

vll primeFactors(ll n) {
    vll primes;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0)
            primes.push_back(i), n /= i;
    }
    if (n > 1)
        primes.push_back(n);
    return primes;
}

int main() {
    ll n;
    cin>>n;
    if(n%2==0)
        cout<<"Mahmoud";
    else
        cout<<"Ehab";
    return 0;
}
