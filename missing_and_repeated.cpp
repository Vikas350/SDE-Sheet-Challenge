#include <bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int hash[n+1] = {0};
        for(int i=0; i<n; i++){
            hash[arr[i]]++;
        }
        
        int a,b;
        for(int i=1; i<=n; i++){
            if(hash[i] == 0) b = i;
            if(hash[i] > 1) a = i;
        }
        
        return {b,a};
	
}
