/*
 * @lc app=leetcode id=1970 lang=cpp
 *
 * [1970] Last Day Where You Can Still Cross
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(int m, int row, int col, vector<vector<int>>& cells)
    {

        vector<vector<bool>> grid(row, vector<bool>(col, true));
        vector<vector<bool>> visited(row, vector<bool>(col));
        for (int i = 0; i < m; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = false;
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < col; i++) {
            if (grid[0][i]) {
                q.push({ 0, i });
            }
        }

        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.first == row - 1)
                return true;
            if (t.second - 1 >= 0 && grid[t.first][t.second - 1] && !visited[t.first][t.second - 1]) {
                visited[t.first][t.second - 1] = true;
                q.push({ t.first, t.second - 1 });
            }
            if (t.second + 1 < col && grid[t.first][t.second + 1] && !visited[t.first][t.second + 1]) {
                visited[t.first][t.second + 1] = true;
                q.push({ t.first, t.second + 1 });
            }
            if (grid[t.first + 1][t.second] && !visited[t.first + 1][t.second]) {
                visited[t.first + 1][t.second] = true;
                q.push({ t.first + 1, t.second });
            }
            if (t.first - 1 >= 0 && grid[t.first - 1][t.second] && !visited[t.first - 1][t.second]) {
                visited[t.first - 1][t.second] = true;
                q.push({ t.first - 1, t.second });
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells)
    {
        int l = 0, r = cells.size();
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (isValid(m, row, col, cells)) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};
// @lc code=end
