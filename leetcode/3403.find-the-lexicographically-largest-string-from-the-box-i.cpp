/*
 * @lc app=leetcode id=3403 lang=cpp
 *
 * [3403] Find the Lexicographically Largest String From the Box I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void updateLexMaxLargestIdx(int &curLexLargestIdx, int otherIdx, string &word, int subMaxLen)
    {
        int i = curLexLargestIdx, j = otherIdx;
        int curIdx = 0;
        while (i < word.size() && j < word.size() && curIdx < subMaxLen)
        {

            if (word[i] > word[j])
            {
                return;
            }
            else if (word[j] > word[i])
            {
                curLexLargestIdx = otherIdx;
                return;
            }
            i++, j++, curIdx++;
        }
        if (i == word.size())
        {
            curLexLargestIdx = otherIdx;
        }
    }
    string answerString(string word, int numFriends)
    {
        if (numFriends == 1)
            return word;
        int subMaxLen = word.size() - numFriends + 1;
        char lexMaxC = 'a';
        for (char c : word)
            lexMaxC = max(lexMaxC, c);
        vector<int> lexMaxIndices;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == lexMaxC)
                lexMaxIndices.push_back(i);
        }
        int curLexLargestIdx = lexMaxIndices[0];
        for (int i = 1; i < lexMaxIndices.size(); i++)
        {
            updateLexMaxLargestIdx(curLexLargestIdx, lexMaxIndices[i], word, subMaxLen);
        }
        string res = word.substr(curLexLargestIdx, min((int)word.size() - curLexLargestIdx, subMaxLen));
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.answerString("dbcadc", 5) << endl;
    return 0;
}
// @lc code=end
