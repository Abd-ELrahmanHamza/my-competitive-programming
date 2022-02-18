//#include<iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//vector<int> level(20000,-1);
//int m,n;
//void BFS()
//{
//    queue<int>q;
//    q.push(m);
//    level[m] = 0;
//    while (!q.empty())
//    {
//        int node = q.front();
//        q.pop();
////        cout<<node<<endl;
//        if(n==node)
//        {
//            cout<<level[node];
//            break;
//        }
//        int dec1 = node-1;
//        int mult2 = 2*node;
//        if(mult2<2*n && level[mult2]==-1)
//        {
//            q.push(mult2);
//            level[mult2] = level[node]+1;
//        }
//        if(dec1>0 && level[dec1]==-1)
//        {
//            q.push(dec1);
//            level[dec1] = level[node]+1;
//        }
//    }
//}
//int main()
//{
//    cin>>m>>n;
//    BFS();
//    return 0;
//}