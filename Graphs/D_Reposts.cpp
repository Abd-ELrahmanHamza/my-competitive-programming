//#include<iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//#include <map>
//#include<bits/stdc++.h>
//
//using namespace std;
//int n;
//map<string,vector<string>> graph;
//map<string,bool> visited;
//int maxL = 0;
//
//void dfs(string node,int l) {
//    visited[node] = true;
//    maxL = max(maxL,l);
//    for (int i = 0; i < graph[node].size(); i++)
//        if (!visited[graph[node][i]])
//            dfs(graph[node][i],l+1);
//}
//
//
//int main() {
//    cin >> n;
//    string fs;
//    for (int i = 0; i < n; i++) {
//        string s1,s2,s3;
//        cin >> s1>>s2>>s3;
//
//        transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
//        transform(s3.begin(), s3.end(), s3.begin(), ::toupper);
//        if(i==0)
//            fs = s3;
//        graph[s3].push_back(s1);
//    }
//
//    dfs(fs,1);
//    cout<<maxL;
//    return 0;
//}