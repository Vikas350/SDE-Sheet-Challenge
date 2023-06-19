#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			pq.push(a[i] + b[j]);
			if(pq.size() > k){
				pq.pop();
			}
			
		}
	}

	vector<int> ans(k);
	int x = k-1;
	while(pq.size() > 0){
		ans[x--] = pq.top();
		pq.pop();
	}

	return ans;
}