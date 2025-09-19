/*
 * @lc app=leetcode id=3484 lang=cpp
 *
 * [3484] Design Spreadsheet
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Spreadsheet {
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows)
    {
        grid = vector<vector<int>>(rows, vector<int>(26));
    }
    int getRow(const string& cell)
    {
        return stoi(cell.substr(1)) - 1;
    }
    int getCol(const string& cell)
    {
        return cell[0] - 'A';
    }
    void setCell(string cell, int value)
    {
        cout << "cell : " << cell << endl;
        cout << "set " << getRow(cell) << " " << getCol(cell) << endl;
        grid[getRow(cell)][getCol(cell)] = value;
    }

    void resetCell(string cell)
    {
        grid[getRow(cell)][getCol(cell)] = 0;
    }

    int getValue(string formula)
    {
        int plusPos = formula.find('+');
        string first = formula.substr(1, plusPos - 1);
        string second = formula.substr(plusPos + 1);
        cout << "first: " << first << " second : " << second << endl;
        int num1 = 0, num2 = 0;
        if (isalpha(first[0])) {
            num1 = grid[getRow(first)][getCol(first)];
        } else {
            num1 = stoi(first);
        }
        if (isalpha(second[0])) {
            num2 = grid[getRow(second)][getCol(second)];
        } else {
            num2 = stoi(second);
        }
        return num1 + num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
// @lc code=end
