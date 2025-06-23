/*
 * @lc app=leetcode id=2081 lang=cpp
 *
 * [2081] Sum of k-Mirror Numbers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<long long> nums;
    bool isKMirror(long long x, int k)
    {
        string num;
        while (x)
        {
            num += (x % k) + '0';
            x /= k;
        }
        int i = 0;

        while (i < num.size() / 2)
        {
            if (num[i] != num[num.size() - i - 1])
            {
                return false;
            }
            i++;
        }

        return true;
    }
    void genRec(string gen, int size, int i, int k, int n)
    {
        // cout << "gen: " << gen << "i: " << i << endl;
        if (nums.size() >= n)
        {
            return;
        }
        if (i > size / 2)
        {
            string genRec = gen;
            std::reverse(genRec.begin(), genRec.end());
            if (size % 2 != 0)
            {
                for (char c = 0; c < 10; c++)
                {
                    long long temp = stoll(gen + to_string(c) + genRec);
                    if (isKMirror(temp, k))
                    {
                        nums.push_back(temp);
                    }
                }
            }
            else
            {
                gen += genRec;
                long long num = stoll(gen);
                if (isKMirror(num, k))
                {
                    nums.push_back(num);
                }
            }
            return;
        }

        for (char c = i == 1 ? '1' : '0'; c <= '9'; c++)
        {
            genRec(gen + c, size, i + 1, k, n);
        }
    }
    long long kMirror(int k, int n)
    {
        long long res = 0;
        long long curNum = 1;
        int curSize = 2;
        for (int i = 1; i < 10; i++)
        {
            if (isKMirror(i, k))
            {
                nums.push_back(i);
            }
        }

        while (nums.size() < n)
        {
            genRec("", curSize, 1, k, n);
            curSize++;
        }
        for (int i = 0; i < n; i++)
        {
            res += nums[i];
        }
        return res;
    }
};
int main()
{
    Solution sol;
    long long res = sol.kMirror(4, 5);
    cout << "res: " << res << endl;
    return 0;
}
// @lc code=end
