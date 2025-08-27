#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<vector<vector<int>>>> memo;
    struct Point {
        int i, j;
        bool turned;
        Point(int i, int j, bool turned)
        {
            this->i = i;
            this->j = j;
            this->turned = turned;
        }
    };
    pair<int, int> nextDir(int fromI, int fromJ)
    {
        if (fromI == 1 && fromJ == 1) {
            return { 1, -1 };
        }
        if (fromI == 1 && fromJ == -1) {
            return { -1, -1 };
        }
        if (fromI == -1 && fromJ == -1) {
            return { -1, 1 };
        }
        return { 1, 1 };
    }
    int getDirIdx(int fromI, int fromJ)
    {
        if (fromI == 1 && fromJ == 1)
            return 0;
        if (fromI == 1 && fromJ == -1)
            return 1;
        if (fromI == -1 && fromJ == 1)
            return 2;
        if (fromI == -1 && fromJ == -1)
            return 3;
        return -1;
    }
    int solve(vector<vector<int>>& grid, int i, int j, bool turned, int fromI, int fromJ)
    {

        int n = grid.size(), m = grid[0].size();

        if (memo[i][j][getDirIdx(fromI, fromJ)][turned] != -1)
            return memo[i][j][getDirIdx(fromI, fromJ)][turned];
        memo[i][j][getDirIdx(fromI, fromJ)][turned] = 0;
        int newI = i + fromI;
        int newJ = j + fromJ;

        if ((newI < n && newI >= 0 && newJ < m && newJ >= 0)
            && ((grid[i][j] == 0 && grid[newI][newJ] == 2) || (grid[i][j] == 2 && grid[newI][newJ] == 0))) {
            memo[i][j][getDirIdx(fromI, fromJ)][turned] = solve(grid, newI, newJ, turned, fromI, fromJ);
        }
        if (!turned) {
            for (int k = 0; k < 3; k++) {
                int newI = i + nextDir(fromI, fromJ).first;
                int newJ = j + nextDir(fromI, fromJ).second;
                if ((newI < n && newI >= 0 && newJ < m && newJ >= 0)
                    && ((grid[i][j] == 0 && grid[newI][newJ] == 2) || (grid[i][j] == 2 && grid[newI][newJ] == 0))) {
                    memo[i][j][getDirIdx(fromI, fromJ)][turned] = max(memo[i][j][getDirIdx(fromI, fromJ)][turned], solve(grid, newI, newJ, true, nextDir(fromI, fromJ).first, nextDir(fromI, fromJ).second));
                }
            }
        }
        memo[i][j][getDirIdx(fromI, fromJ)][turned] = memo[i][j][getDirIdx(fromI, fromJ)][turned] + 1;
        return memo[i][j][getDirIdx(fromI, fromJ)][turned];
    }
    int lenOfVDiagonal(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        memo = vector<vector<vector<vector<int>>>>(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, -1))));
        int res = 0;
        bool has1 = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    has1 = true;
                    if (i - 1 >= 0 && j + 1 < m && grid[i - 1][j + 1] == 2)
                        res = max(res, solve(grid, i - 1, j + 1, false, -1, 1));
                    if (i - 1 >= 0 && j - 1 >= 0 && grid[i - 1][j - 1] == 2)
                        res = max(res, solve(grid, i - 1, j - 1, false, -1, -1));
                    if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] == 2)
                        res = max(res, solve(grid, i + 1, j + 1, false, 1, 1));
                    if (i + 1 < n && j - 1 >= 0 && grid[i + 1][j - 1] == 2)
                        res = max(res, solve(grid, i + 1, j - 1, false, 1, -1));
                }
            }
        }
        if (!has1)
            return 0;
        return res + 1;
    }
};