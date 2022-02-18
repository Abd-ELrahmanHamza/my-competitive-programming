//#include <bits/stdc++.h>
//
//using namespace std;
//vector<vector<int>> adj;
//vector<bool> visited;
//int n;
//
//void dfs(int node) {
//    visited[node] = true;
//    for (auto n: adj[node]) {
//        if (!visited[n]) {
//            dfs(n);
//        }
//    }
//}
//
//int connectedComp() {
//    int num = 0;
//    for (int i = 26; i < n + 26; i++) {
//        if (!visited[i]) {
//            num++;
//            dfs(i);
//        }
//    }
//    return num;
//}
//
//int main() {
//    string s;
//    cin >> n;
//    adj = vector<vector<int>>(26+n);
//    visited = vector<bool>(26+n);
//    for (int i = 0; i < n; i++) {
//        cin >> s;
//        sort(s.begin(), s.end());
//        auto res = unique(s.begin(), s.end());
//        s = string(s.begin(), res);
//        for (int j = 0; j < s.size(); j++) {
//            adj[s[j] - 'a'].push_back(26 + i);
//            adj[26 + i].push_back(s[j] - 'a');
//        }
//    }
//    cout << connectedComp();
//    return 0;
//}