//#include <iostream>
//#include <vector>
//
//using namespace std;
//vector<vector<bool>> graph;
//vector<vector<bool>> visited;
//int n, m;
//
//bool valid(int i, int j) {
//    return i < n && i >= 0 && j < m && j >= 0;
//}
//
//int dirx[4] = {0, 0, 1, -1};
//int diry[4] = {1, -1, 0, 0};
//
//void dfs(int i, int j) {
//    visited[i][j] = true;
//    for (int d = 0; d < 4; d++) {
//        int cx = i + dirx[d];
//        int cy = j + diry[d];
//        if (valid(cx, cy) && !visited[cx][cy] && graph[cx][cy])
//            dfs(cx, cy);
//    }
//}
//
//int main() {
//    cin >> n >> m;
//    visited = vector<vector<bool>>(n, vector<bool>(m));
//    graph = vector<vector<bool>>(n, vector<bool>(m));
//    for (int i = 0; i < n; i++) {
//        int k;
//        cin >> k;
//        for (int j = 0; j < k; j++) {
//            int x;
//            cin >> x;
//            graph[i][x - 1] = true;
//        }
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++)
//            cout<<graph[i][j]<<" ";
//        cout<<endl;
//    }
//    int cnt = 0;
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++) {
//            if (!visited[i][j]&&graph[i][j]){
//                dfs(i, j);
//                cout<<i<<" "<<j<<endl;
//                cnt++;
//            }
//        }
//    cout << cnt-1;
//    return 0;
//}
