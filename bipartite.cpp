#include<bits/stdc++.h>
using namespace std;

bool bfs(unordered_map<int,set<int>> &adjList,vector<int> &color, int node){
	queue<int> q;
	q.push(node);
	color[node] = 1;

	while(!q.empty()){
		int frontNode = q.front();
		q.pop();

		for(auto x:adjList[frontNode]){
			if(color[x] == -1){
				color[x] = !color[frontNode];
				q.push(x);
			}
			else if(color[x] == color[frontNode]){
				return false;
			}
		}
	}

	return true;

}
bool dfs(unordered_map<int,set<int>> &adjList,vector<int> &color, int node, int col){
	
	color[node] = col;

	for(auto x:adjList[node]){
		if(color[x] == -1){
			bool check = dfs(adjList,color,x,!col);
			if(check == false) return false;

		}
		else if(color[x] == col){
			return false;
		}
	}

	return true;

}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size();
	unordered_map<int,set<int>> adjList;
	for(int i=0; i<edges.size(); i++){
		for(int j=0; j<edges[0].size(); j++){
			if(edges[i][j] == 1){
				adjList[i].insert(j);
		        adjList[j].insert(i);
			}
		}
		
	}

	// int n = adjList.size();
	vector<int> color(n,-1);

	for(int i=0; i<n; i++){
		if(color[i] == -1){
			bool ans = dfs(adjList,color,i,0);
			// bool ans = bfs(adjList,color,i);
			if(ans == false) return false;
		}
	}

	return true;
}