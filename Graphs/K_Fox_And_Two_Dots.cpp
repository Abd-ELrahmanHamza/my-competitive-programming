//#include <iostream>
//#include <vector>
//
//using namespace std;
//vector<vector<char>> graph;
//vector<vector<bool>> visited;
//int n, m;
//
//bool valid(int i, int j) {
//    return i < n && i >= 0 && j < m && j >= 0;
//}
//
//void solve(int i, int j, int dirc,char color ) {
//    if(!valid(i,j) || graph[i][j]!=color)
//        return;
////    cout<<graph[i][j]<<" "<<i<<" "<<j<<endl;
//
//    if(visited[i][j])
//    {
////        cout<<graph[i][j]<<" "<<i<<" "<<j<<endl;
//        cout<<"Yes";
//        exit(0);
//    }
//    visited[i][j]=true;
//    if(dirc!=0)
//        solve(i,j+1,1,color);
//    if(dirc!=1)
//        solve(i,j-1,0,color);
//    if(dirc!=3)
//        solve(i-1,j,2,color);
//    if(dirc!=2)
//        solve(i+1,j,3,color);
//}
//
//int main() {
//    cin >> n >> m;
//    visited = vector<vector<bool>>(n, vector<bool>(m));
//    graph = vector<vector<char>>(n, vector<char>(m));
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> graph[i][j];
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            if(!visited[i][j])
//                solve(i,j,-1,graph[i][j]);
//    cout<<"No";
//    return 0;
//}
