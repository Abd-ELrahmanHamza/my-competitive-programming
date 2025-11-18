#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int i = 0;
        while (i < bits.size()) {
            if (i == bits.size() - 1)
                return true;
            if (bits[i] == 1) {
                i++;
            }
            i++;
        }
        return false;
    }
};