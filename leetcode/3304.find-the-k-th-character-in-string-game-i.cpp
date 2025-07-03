/*
 * @lc app=leetcode id=3304 lang=cpp
 *
 * [3304] Find the K-th Character in String Game I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char kthCharacter(int k) {
        vector<char> v(k);
        v[0] = 'a';
        int iterations = ceil(log2(k));
        cout << "iterations: " << iterations << endl;

        for (int i = 1; i <= iterations; i++) {
            int j = i * 2;
            cout<<"j = "<<j<<endl;
            for (int q = 0; q < j; q++) {
                v[j + q] = v[q] + 1;
                if (v[j + q] > 'z')
                    v[j + q] = 'a';
            }
        }
        return v.back();
    }
};
// @lc code=end
