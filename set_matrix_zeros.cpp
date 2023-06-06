#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>v,r;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]==0)
                {
                    v.push_back(i);
                    r.push_back(j);
                }
            }
        }
        
        int s = v.size();
        int t = r.size();
        
        for(int i=0; i<s; i++)
        {
            for(int j=0; j<n; j++)
            {
                matrix[v[i]][j]=0;
                
            }
        }
        
        for(int j=0; j<t; j++)
        {
            for(int i=0; i<m; i++)
            {
                matrix[i][r[j]]=0;
                
            }
        }
    }
};