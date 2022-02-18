//#include<bits/stdc++.h>
//
//using namespace std;
//int n, m;
//vector<vector<int>> graph;
//vector<bool> visited;
//vector<set<int>> edges;
//map<pair<int,int>,set<int>>edgesPairs;
//int cnt = 0;
//
//void dfs(int node, int pathClr, int v) {
//    visited[node] = true;
////    cout<<"Node = "<<node<<endl;
//    if(node==v) {
//        cnt++;
//        return;
//    }
//    for (int i = 0; i < graph[node].size(); i++)
//        if (!visited[graph[node][i]]) {
//            pair<int,int>P = {min(node,graph[node][i]),max(node,graph[node][i])};
//            if (edgesPairs[P].count(pathClr)!= 0)
//                dfs(graph[node][i], pathClr, v);
//        }
//}
//
//int main() {
//    cin >> n >> m;
//    graph = vector<vector<int>>(n);
//    edges = vector<set<int>>(n);
//    visited = vector<bool>(n);
//    for (int i = 0; i < m; i++) {
//        int x, y, z;
//        cin >> x >> y >> z;
//        graph[x - 1].push_back(y - 1);
//        graph[y - 1].push_back(x - 1);
//        edges[x-1].insert(z);
//        edges[y-1].insert(z);
//        edgesPairs[{min(x-1,y-1),max(x-1,y-1)}].insert(z);
//    }
//    for(int i=0;i<n;i++){
//        sort( graph[i].begin(), graph[i].end() );
//        graph[i].erase( unique( graph[i].begin(), graph[i].end() ), graph[i].end() );
//    }
////    for (int i = 0; i < graph.size(); i++) {
////        cout << i << " : ";
////        for (int x: graph[i])
////            cout << x << " ";
////        cout << endl;
////    }
////    for(int i=0;i<n;i++){
////        cout<<i<<" : ";
////        for(int x:edges[i])
////            cout<<x<<" ";
////        cout<<endl;
////    }
//    int q;
//    cin >> q;
//    for (int i = 0; i < q; i++) {
//        cnt = 0;
//        int u, v;
//        cin >> u >> v;
//        u--;v--;
//        for(int c:edges[u]) {
////            cout<<"Color : "<<c<<endl;
//            dfs(u, c, v );
//            visited.clear();
//            visited = vector<bool>(n);
//        }
//        cout << cnt << endl;
//
//    }
//    return 0;
//}