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

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' ||
           c == 'U';
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll v = 0, c = 0;
    for (char x: s) {
        if (isVowel(x))v++;
    }
    c = n - v;

    while (q--) {
        int index;
        char ch;
        cin >> index >> ch;
        if (isVowel(s[index]) && !isVowel(ch)) {
            s[index] = ch;
            v--;
            c++;
        } else if (!isVowel(s[index]) && isVowel(ch)) {
            s[index] = ch;
            v++;
            c--;
        }
        if (v > c)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}