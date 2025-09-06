/*
 * @lc app=leetcode id=2657 lang=cpp
 *
 * [2657] Find the Prefix Common Array of Two Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
        vector<bool> cntA(A.size() + 1);
        vector<bool> cntB(B.size() + 1);
        vector<int> C(A.size());
        int cur = 0;
        for (int i = 0; i < A.size(); i++) {
            cntA[A[i]] = true;
            if (cntB[A[i]]) {
                cur++;
            }
            cntB[B[i]] = true;
            if (cntA[B[i]]) {
                cur++;
            }
            C[i] = cur;
        }
        return C;
    }
};
// @lc code=end
