#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        {
            int n = matrix.size();
            for (int i = 0; i <= ceil(n / 2.0); i++) {
                for (int j = 0; j < n - 2 * i - 1; j++) {
                    int temp = matrix[i][j + i];
                    matrix[i][j + i] = matrix[n - i - 1 - j][i];
                    matrix[n - i - 1 - j][i] = matrix[n - i - 1][n - i - 1 - j];
                    matrix[n - i - 1][n - i - 1 - j] = matrix[j + i][n - i - 1];
                    matrix[j + i][n - i - 1] = temp;
                }
            }
        }
    }
};