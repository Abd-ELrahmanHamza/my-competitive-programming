#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(const string& s)
    {
        static const regex pattern("^[A-Za-z0-9_]+$");
        return regex_match(s, pattern);
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive)
    {
        unordered_map<string, vector<string>> um;
        for (int i = 0; i < code.size(); i++) {
            if (isActive[i] && isValid(code[i])) {
                um[businessLine[i]].push_back(code[i]);
            }
        }
        sort(um["electronics"].begin(), um["electronics"].end());
        sort(um["grocery"].begin(), um["grocery"].end());
        sort(um["pharmacy"].begin(), um["pharmacy"].end());
        sort(um["restaurant"].begin(), um["restaurant"].end());

        vector<string> res;
        res.insert(res.end(), um["electronics"].begin(), um["electronics"].end());
        res.insert(res.end(), um["grocery"].begin(), um["grocery"].end());
        res.insert(res.end(), um["pharmacy"].begin(), um["pharmacy"].end());
        res.insert(res.end(), um["restaurant"].begin(), um["restaurant"].end());
        return res;
    }
};