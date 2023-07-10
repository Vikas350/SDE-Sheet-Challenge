#include<bits/stdc++.h>
using namespace std;
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int> v;
	priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
	int start = 0;
	for(int end=0; end<n; end++){
		maxHeap.push(arr[end]);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

		if(maxHeap.size() > minHeap.size()){
            v.push_back(maxHeap.top());
        }
        else{
            v.push_back((maxHeap.top()+minHeap.top())/2);
        }
	}

	return v;
}
