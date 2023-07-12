#include<bits/stdc++.h>
using namespace std;

void dfs(int** arr, vector<vector<bool>> &vis, int row, int col,int n,int m){
   if(row<0 || col<0 || row>=n || col>=m) return ;
   if(vis[row][col] == true || arr[row][col] == 0) return ;

   vis[row][col] = true;

   dfs(arr,vis,row-1,col-1,n,m);
   dfs(arr,vis,row,col-1,n,m);
   dfs(arr,vis,row+1,col-1,n,m);
   dfs(arr,vis,row-1,col,n,m);
   dfs(arr,vis,row+1,col,n,m);
   dfs(arr,vis,row-1,col+1,n,m);
   dfs(arr,vis,row,col+1,n,m);
   dfs(arr,vis,row+1,col+1,n,m);
   
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int count = 0;
   vector<vector<bool>> vis(n,vector<bool> (m,false));
   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
         if(vis[i][j] != true && arr[i][j] == 1){
            count++;
            dfs(arr,vis,i,j,n,m);
         }
      }
   }

   return count;
}
