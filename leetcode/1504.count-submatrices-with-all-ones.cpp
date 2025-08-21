
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat)
    {
        int res = 0;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!mat[i][j])continue;
                if (j - 1 >= 0) {
                    mat[i][j] += mat[i][j - 1];
                }
                int curRows = mat[i][j];
                res += curRows;
                for (int k = i-1; k >= 0; k--) {
                    curRows = min(curRows, mat[k][j]);
                    if(!curRows)break;
                    res += curRows;
                }
            }
        }
        return res;
    }
};
