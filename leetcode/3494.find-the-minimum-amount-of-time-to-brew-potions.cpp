#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana)
    {
        vector<long long> prevTime(skill.size() + 1);
        for (int i = 0; i < mana.size(); i++) {
            int endTime = prevTime.back();
            prevTime[0] = prevTime[1];
            long long diff = 0;
            for (int j = 1; j <= skill.size(); j++) {
                prevTime[j] = prevTime[j - 1] + skill[j - 1] * mana[i];
                diff = max(diff, (j + 1 < prevTime.size() ? prevTime[j + 1] - prevTime[j] : 0));
            }
            for (int j = 0; j <= skill.size(); j++) {
                prevTime[j] = prevTime[j] + diff;
            }
        }
        return prevTime.back();
    }
};