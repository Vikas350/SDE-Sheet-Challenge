#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i:adjList[frontNode]){
            if(visited[i] != true){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    unordered_map<int,bool> visited;
    vector<int> ans;

    for(int i=0; i<vertex; i++){
        if(visited[i] != true){
            bfs(adjList,visited,ans,i);
        }
    }

    return ans;
}