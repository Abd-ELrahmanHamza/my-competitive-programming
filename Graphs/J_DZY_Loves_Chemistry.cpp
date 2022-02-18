//#include<iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//int n,m;
//vector<vector<int>>graph;
//vector<bool>visited;
//int connectedCount =0 ;
//unsigned long long result = 1;
//void dfs(int node)
//{
//    visited[node] = true;
//    connectedCount++;
//    for(int i=0;i<graph[node].size();i++)
//        if(!visited[graph[node][i]])
//            dfs(graph[node][i]);
//}
//int connectedComp()
//{
//    for(int i=0;i<n;i++)
//    {
//        if(!visited[i])
//        {
//            connectedCount=0;
//            dfs(i);
//            result*=pow(2,connectedCount-1);
//        }
//    }
//}
//int main()
//{
//    cin>>n>>m;
//    graph = vector<vector<int>>(n);
//    visited = vector<bool>(n);
//    for(int i=0;i<m;i++)
//    {
//        int x,y;
//        cin>>x>>y;
//        graph[x-1].push_back(y-1);
//        graph[y-1].push_back(x-1);
//    }
//    connectedComp();
//
//    cout<<result;
//    return 0;
//}