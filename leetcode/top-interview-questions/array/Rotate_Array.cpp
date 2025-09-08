#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int curIdx = 0, curNum = nums[0];
        int curCycleStart = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int newIdx = (curIdx + k) % n;
            int newNum = nums[newIdx];
            nums[newIdx] = curNum;
            if (newIdx == curCycleStart) {
                curIdx = (newIdx + 1) % n;
                curNum = nums[curIdx];
                curCycleStart = curIdx;
            } else {
                curIdx = newIdx;
                curNum = newNum;
            }
        }
    }
};