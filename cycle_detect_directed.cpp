#include<bits/stdc++.h>
using namespace std;
bool isCyclic(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,unordered_map<int,bool> &pathVisited,int node){
  visited[node] = true;
  pathVisited[node] = true;

  for(auto x:adjList[node]){
    if(!visited[x]){
      bool detected = isCyclic(adjList,visited,pathVisited,x);
      if(detected == true) return true;
    }
    else if(pathVisited[x] == true){
      return true;
    }
  }

  pathVisited[node] = false;

  return false;

}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,set<int>> adjList;
  for(int i=0; i<edges.size(); i++){
    adjList[edges[i].first].insert(edges[i].second);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> pathVisited;

  for(int i=0; i<n; i++){
    if(!visited[i]){
      bool ans = isCyclic(adjList,visited,pathVisited,i);
      if(ans == true) return true;
    }
  }

  return false;
}