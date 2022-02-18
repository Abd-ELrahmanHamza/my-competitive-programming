#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> result;
vector<int>cnts;
int n;

void dfs(int node, int &cnt) {
    visited[node] = true;
    result[node] = cnts.size();
    cnt++;
    for (auto x: adj[node]) {
        if (!visited[x]) {
            dfs(x, cnt);
        }
    }
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        adj = vector<vector<int>>(n + 1);
        visited = vector<bool>(n + 1);
        result = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            if (!visited[i]) {
                dfs(i, cnt);
                cnts.push_back(cnt);
            }
        }
        for (int i = 1; i <= n; i++)cout << cnts[result[i]] << " ";
        cout << endl;
    }
    return 0;
}