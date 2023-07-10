#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &component, int node){
    component.push_back(node);
    visited[node] = true;

    for(auto i:adjList[node]){
        if(visited[i] != true){
            dfs(adjList,visited,component,i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,set<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    unordered_map<int,bool> visited;
    vector<vector<int>> ans;

    for(int i=0; i<V; i++){
        if(visited[i] != true){
            vector<int> component;
            dfs(adjList,visited,component,i);
            ans.push_back(component);
        }
    }

    return ans;
}