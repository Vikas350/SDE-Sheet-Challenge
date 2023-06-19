#include<bits/stdc++.h>
using namespace std;
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// o(nlogk)
	priority_queue<int,vector<int>, greater<int>> pq1;
	priority_queue<int> pq2;
	for(int i=0; i<n; i++){
		pq1.push(arr[i]);
		if(pq1.size() > k){
			pq1.pop();
		}
	}

	for(int i=0; i<n; i++){
        pq2.push(arr[i]);
		if(pq2.size() > k){
			pq2.pop(); 
		}
    }

    return {pq2.top(), pq1.top()};

    //o(nlogn)
	sort(arr.begin(),arr.end());
	return {arr[k-1],arr[n-k]};

	//quick select - o(n)

}