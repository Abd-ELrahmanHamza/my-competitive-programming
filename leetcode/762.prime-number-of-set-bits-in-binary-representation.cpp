/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPrime(int x)
    {
        if (x % 2 == 0)
            return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    set<int> getPrimes()
    {
        set<int> primes = { 2 };
        for (int i = 3; i <= 32; i++) {
            if (isPrime(i)) {
                primes.insert(i);
            }
        }
        return primes;
    }
    int countPrimeSetBits(int left, int right)
    {
        int res = 0;
        set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        for (int i = left; i <= right; i++) {
            int numOnes = 0;
            int x = i;
            while (x) {
                numOnes += x & 1;
                x = x >> 1;
            }
            if (primes.count(numOnes)) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
