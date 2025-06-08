/*
 * @lc app=leetcode id=2894 lang=cpp
 *
 * [2894] Divisible and Non-divisible Sums Difference
 */

// @lc code=start
class Solution
{
  public:
    int differenceOfSums(int n, int m)
    {
        int sDiv = 0;
        for (int i = 0; i <= n; i += m)
        {
            sDiv += i;
        }
        return n * (n + 1) / 2 - 2 * sDiv;
    }
};
// @lc code=end
