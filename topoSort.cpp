#include <bits/stdc++.h> 
using namespace std;
void dfs(unordered_map<int,set<int>> &adjList, unordered_map<int,bool> &vis, stack<int> &s, int node){
    vis[node] = true;
    for(auto x:adjList[node]){
        if(!vis[x]){
            dfs(adjList,vis,s,x);
        }
    }

    s.push(node);
    
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,set<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        adjList[edges[i][0]].insert(edges[i][1]);
    }

    /*
    stack<int> s;
    unordered_map<int,bool> vis;
    for(int i=0; i<v; i++){
        if(vis[i] != true){
            dfs(adjList,vis,s,i);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
    */

    unordered_map<int,int> indegree;
    // unordered_map<int,bool> vis;
    for(int i=0; i<v; i++){
        for(auto x:adjList[i]){
            indegree[x]++;
        }
    }

    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto x:adjList[frontNode]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }

    }

    return ans;

}