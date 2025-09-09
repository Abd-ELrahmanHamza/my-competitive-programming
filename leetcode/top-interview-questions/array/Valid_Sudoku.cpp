
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i <= 6; i += 3) {
            for (int j = 0; j <= 6; j += 3) {
                vector<bool> found(10);
                for (int ii = i; ii <= i + 2; ii++) {
                    for (int jj = j; jj <= j + 2; jj++) {
                        if (board[ii][jj] == '.')
                            continue;
                        if (found[board[ii][jj] - '0']) {
                            return false;
                        }
                        found[board[ii][jj] - '0'] = true;
                    }
                }
            }
        }
        for (int i = 0; i <= 8; i++) {
            vector<bool> found(10);

            for (int j = 0; j <= 8; j++) {
                if (board[i][j] == '.')
                    continue;
                if (found[board[i][j] - '0']) {
                    return false;
                }
                found[board[i][j] - '0'] = true;
            }
        }
        for (int i = 0; i <= 8; i++) {
            vector<bool> found(10);

            for (int j = 0; j <= 8; j++) {
                if (board[j][i] == '.')
                    continue;
                if (found[board[j][i] - '0']) {
                    return false;
                }
                found[board[j][i] - '0'] = true;
            }
        }
        return true;
    }
};