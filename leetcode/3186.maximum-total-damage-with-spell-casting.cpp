/*
 * @lc app=leetcode id=3186 lang=cpp
 *
 * [3186] Maximum Total Damage With Spell Casting
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power)
    {
        map<int, int> freq;
        map<int, long long> preSumPowers;
        long long res = 0;
        for (int p : power) {
            freq[p]++;
        }
        for (auto it = freq.begin(); it != freq.end(); it++) {
            preSumPowers[it->first] = (long long)it->second * it->first;
            auto p = it;
            auto pp = it;
            auto ppp = it;
            auto pppp = it;
            auto ppppp = it;

            if (it != freq.begin()) {
                p = prev(it);
                if (p != freq.begin()) {
                    pp = prev(p);
                    if (pp != freq.begin()) {
                        ppp = prev(pp);
                        if (ppp != freq.begin()) {
                            pppp = prev(ppp);
                            if (pppp != freq.begin()) {
                                ppppp = prev(pppp);
                            }
                        }
                    }
                }
            }

            long long maxToAdd = 0;
            if (p->first < it->first - 2) {
                maxToAdd = preSumPowers[p->first];
            }
            if (pp->first < it->first - 2 && (pp->first >= p->first - 2 || p->first >= it->first - 2)) {
                maxToAdd = max(maxToAdd, preSumPowers[pp->first]);
            }
            if (ppp->first < it->first - 2 && (ppp->first >= pp->first - 2 || pp->first >= it->first - 2)) {
                maxToAdd = max(maxToAdd, preSumPowers[ppp->first]);
            }
            if (pppp->first < it->first - 2 && (pppp->first >= ppp->first - 2 || ppp->first >= it->first - 2)) {
                maxToAdd = max(maxToAdd, preSumPowers[pppp->first]);
            }
            if (ppppp->first < it->first - 2 && (ppppp->first >= pppp->first - 2 || pppp->first >= it->first - 2)) {
                maxToAdd = max(maxToAdd, preSumPowers[ppppp->first]);
            }
            preSumPowers[it->first] += maxToAdd;
            res = max(res, preSumPowers[it->first]);
        }
        return res;
    }
};
// @lc code=end
