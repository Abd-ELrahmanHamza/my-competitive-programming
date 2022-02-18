//#include<iostream>
//#include <vector>
//
//using namespace std;
//vector<vector<char>> graph;
//int r1, r2, c1, c2, n, m;
//bool result = false;
//
//bool valid(int r, int c) {
//    return r >= 0 && r < n && c >= 0 && c < m;
//}
//
//bool checkN(int r, int c) {
//    char c11 = (valid(r + 1, c) ? graph[r + 1][c] : 'X');
//    char c22 = (valid(r - 1, c) ? graph[r - 1][c] : 'X');
//    char c33 = (valid(r, c + 1) ? graph[r][c + 1] : 'X');
//    char c44 = (valid(r, c - 1) ? graph[r][c - 1] : 'X');
//    return c11 == '.' || c22 == '.' || c33 == '.' || c44 == '.';
//}
//
//void solve(int r, int c) {
//    if (!valid(r, c)) {
//        return;
//    }
//    if (r == r2 && c == c2) {
//        if (graph[r][c] == 'X') {
//            result = true;
//            return;
//        }
//    }
//    if (graph[r][c] == 'X') {
//        return;
//    }
//    graph[r][c] = 'X';
//    solve(r, c + 1);
//    solve(r, c - 1);
//    solve(r + 1, c);
//    solve(r - 1, c);
//}
//
//int main() {
//    cin >> n >> m;
//    graph = vector<vector<char>>(n, vector<char>(m));
//    for (auto &v: graph) {
//        for (auto &x: v) cin >> x;
//    }
//
//    cin >> r1 >> c1 >> r2 >> c2;
//    r1--;
//    c1--;
//    r2--;
//    c2--;
//    solve(r1+1, c1);
//    solve(r1-1, c1);
//    solve(r1, c1+1);
//    solve(r1, c1-1);
//    if (result)
//        cout << "YES";
//    else
//        cout << "NO";
//    return 0;
//}