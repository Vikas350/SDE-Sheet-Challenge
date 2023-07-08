#include <bits/stdc++.h> 
using namespace std;
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int> pq;
        int n = size;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        int ans;
        while(K--){
            ans = pq.top();
            pq.pop();
        }
        
        return ans;
}