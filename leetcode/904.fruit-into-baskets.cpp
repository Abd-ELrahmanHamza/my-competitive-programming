#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        int res = 0;
        int first = -1, second = -1;
        int firstCnt = 0, secondCnt = 0;
        int l = 0, r = 0;
        while (r < fruits.size()) {
            while (r < fruits.size()) {
                if (fruits[r] == second) {
                    r++;
                    secondCnt++;
                } else if (fruits[r] == first) {
                    firstCnt++;
                    swap(firstCnt, secondCnt);
                    swap(first, second);
                    r++;
                } else if (second == -1) {
                    second = fruits[r];
                    secondCnt = 1;
                    r++;
                } else if (first == -1) {
                    first = fruits[r];
                    firstCnt = 1;
                    swap(first, second);
                    swap(firstCnt, secondCnt);
                    r++;
                } else {
                    break;
                }
            }
            res = max(res, r - l);
            while (l < fruits.size() && firstCnt > 0) {
                if (fruits[l] == first) {
                    firstCnt--;
                } else if (fruits[l] == second) {
                    secondCnt--;
                }
                l++;
            }
            first = -1;
            firstCnt = 0;
        }

        return res;
    }
};