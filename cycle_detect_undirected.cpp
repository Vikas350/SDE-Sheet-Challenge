#include<bits/stdc++.h>
using namespace std;
bool isCyclicBFS(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited, int node){
    queue<int> q;
    q.push(node);
    unordered_map<int,int> parent;
    parent[node] = -1;
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto x:adjList[frontNode]){
            if(visited[x] != true){
                q.push(x);
                parent[x] = frontNode;
                visited[x] = true;
            }
            else if(visited[x] == true && parent[frontNode] != x){
                return true;
            }
        }
    }

    return false;
}
bool isCyclicDFS(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited, int node, int parent){
    visited[node] = true;
    for(auto x:adjList[node]){
        if(visited[x] != true){
            bool detected = isCyclicDFS(adjList,visited,x,node);
            if(detected == true) return true;
        }
        else if(visited[x] == true && parent != x){
            return true;
        }
    }

    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,set<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        adjList[edges[i][0]].insert(edges[i][1]);
        adjList[edges[i][1]].insert(edges[i][0]);
    }

    int parent = -1;
    unordered_map<int,bool> visited;
    for(int i=0; i<n; i++){
        if(visited[i] != true){
            bool ans = isCyclicBFS(adjList,visited,i);
            // bool ans = isCyclicBFS(adjList,visited,i,parent);
            if(ans == true) return "Yes";
        }
    }

    return "No";
}
