//#include <iostream>
//#include <vector>
//using namespace std;
//vector<vector<int>>graph;
//vector<bool>visited;
//vector<int>cats;
//int paths = 0;
//int n,m;
//void dfs(int node,int catsNum)
//{
//    visited[node]=true;
//    if(catsNum>m)
//        return;
//    catsNum = (cats[node]==0?0:catsNum+1);
//    if(graph[node].size()==1&& catsNum<=m && node!=0) {
//        paths++;
//    }
//
//    for(int i=0;i<graph[node].size();i++)
//    {
//        int child = graph[node][i];
//        if(!visited[child])
//            dfs(child,catsNum);
//    }
//}
//int main() {
//    cin>>n>>m;
//    cats = vector<int>(n);
//    visited = vector<bool>(n);
//    graph = vector<vector<int>>(n);
//    for(int i=0;i<n;i++)
//        cin>>cats[i];
//    for(int i=0;i<n-1;i++)
//    {
//        int x,y;
//        cin>>x>>y;
//        graph[x-1].push_back(y-1);
//        graph[y-1].push_back(x-1);
//    }
//    dfs(0,0);
//    cout<<paths;
//    return 0;
//}
