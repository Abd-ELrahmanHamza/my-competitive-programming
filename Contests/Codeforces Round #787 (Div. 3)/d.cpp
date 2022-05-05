#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define rep(i, v) for(int i=0;i<v.size();++i)

vector<vector<int>> graph;
vector<vector<int>> paths;
vector<bool> visited;

void dfs(int node, vector<int> &path) {
    path.push_back(node);
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if (!visited[graph[node][i]])
            dfs(graph[node][i], path);
    }
    if (!path.empty())
        paths.push_back(path);
    path.clear();
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        graph = vector<vector<int>>(n + 1);
        visited = vector<bool>(n + 1);
        paths.clear();
        int root = -1;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            if (p == i + 1)
                root = i + 1;
            else
                graph[p].push_back(i + 1);
        }
        vector<int> dummy;
        dfs(root, dummy);
        cout << paths.size() << endl;
        for (auto path: paths) {
            cout << path.size() << endl;
            for (int node: path) {
                cout << node << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
