#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x==1) return false;
    bool isNumPrime = true;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            isNumPrime = false;
            break;
        }
    }
    return isNumPrime;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x,k;
        cin>>x>>k;
        cout<<(k==1 &&isPrime(x) || k==2 && x == 1?"Yes":"No")<<endl;
    }
    return 0;
}

