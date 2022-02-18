//#include<iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int n;
//vector<vector<pair<int, int>>> graph;
//vector<bool> visited;
//vector<int> dp;
//
//void dfs0(int node) {
//    visited[node] = true;
//    for (int i = 0; i < graph[node].size(); i++) {
//        if (!visited[graph[node][i].first]) {
//            dp[0] += graph[node][i].second;
//            dfs0(graph[node][i].first);
//        }
//    }
//}
//
//void dfs(int node) {
//    visited[node] = true;
//    for (int i = 0; i < graph[node].size(); i++) {
//        if (!visited[graph[node][i].first]) {
//            dp[graph[node][i].first - 1] = dp[node - 1] + (!graph[node][i].second ? 1 : -1);
//            dfs(graph[node][i].first);
//        }
//    }
//}
//
//
//int main() {
//    cin >> n;
//    graph = vector<vector<pair<int, int>>>(n + 1);
//    visited = vector<bool>(n + 1, false);
//    dp = vector<int>(n, 0);
//    for (int i = 0; i < n - 1; i++) {
//        int x, y;
//        cin >> x >> y;
//        graph[x].push_back({y, 0});
//        graph[y].push_back({x, 1});
//    }
//    dfs0(1);
//    visited = vector<bool>(n + 1, false);
//    dfs(1);
//    int minPath = *min_element(dp.begin(), dp.end());
//    cout << minPath << endl;
//    for (int i = 0; i < n; i++) {
//        if (dp[i] == minPath)
//            cout << i + 1 << " ";
//    }
//    return 0;
//}