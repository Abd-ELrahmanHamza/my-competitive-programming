/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string formateStringCS(string s)
    {
        string s2(s.begin(), s.end());
        for (char& c : s2) {
            c = tolower(c);
        }
        return s2;
    }
    string formateString(string s)
    {
        string s2(s.begin(), s.end());
        for (char& c : s2) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '.';
            }
        }
        return s2;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        unordered_map<string, string> wsV;
        unordered_map<string, string> wsCS;
        unordered_set<string> wsHS;
        vector<string> res(queries.size());
        for (int i = 0; i < wordlist.size(); i++) {
            auto wv = formateString(wordlist[i]);
            auto wCS = formateStringCS(wordlist[i]);
            wsHS.insert(wordlist[i]);
            if (wsV.find(wv) == wsV.end()) {
                wsV[wv] = wordlist[i];
            }
            if (wsCS.find(wCS) == wsCS.end()) {
                wsCS[wCS] = wordlist[i];
            }
        }

        for (int j = 0; j < queries.size(); j++) {
            if (wsHS.find(queries[j]) != wsHS.end()) {
                res[j] = queries[j];
            }
            if (!res[j].empty())
                continue;
            auto qCS = formateStringCS(queries[j]);
            res[j] = wsCS[qCS];

            if (!res[j].empty())
                continue;
            auto qv = formateString(queries[j]);
            res[j] = wsV[qv];
        }
        return res;
    }
};
// @lc code=end
