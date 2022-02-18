//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//vector<vector<int>> graph;
//vector<bool> visited;
//int n, m;
//
//void dfs(int node) {
//    visited[node] = true;
//    for (int i = 0; i < graph[node].size(); i++) {
//        int child = graph[node][i];
//        if (!visited[child])
//            dfs(child);
//    }
//}
//
//int main() {
//    cin >> n >> m;
//    visited = vector<bool>(n);
//    graph = vector<vector<int>>(n);
//    map<int, vector<int>> m;
//    bool isZeros = false;
//    for (int i = 0; i < n; i++) {
//        int x, k;
//        cin >> k;
//        if(k>0)
//            isZeros = true;
//        for (int j = 0; j < k; j++) {
//            cin >> x;
//            for (int x: m[x - 1]) {
//                graph[i].push_back(x);
//                graph[x].push_back(i);
//            }
//            m[x - 1].push_back(i);
//        }
//    }
////    for (int i = 0; i < n; i++) {
////        cout << i << " : ";
////        for (int j = 0; j < graph[i].size(); j++)
////            cout << graph[i][j] << " ";
////        cout << endl;
////    }
//    int cnt = 0;
//    for (int i = 0; i < n; i++) {
//        if (!visited[i]) {
//            dfs(i);
//            cnt++;
//        }
//    }
//    if(isZeros)
//    cout << cnt - 1;
//    else
//        cout<<cnt;
//    return 0;
//}
