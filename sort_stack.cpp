#include <bits/stdc++.h> 
using namespace std;
void sortStack(stack<int> &stack)
{
	// Write your code here
	priority_queue<int,vector<int>,greater<int>> pq;
	while(stack.empty() != true){
		pq.push(stack.top());
		stack.pop();
	}

	while(pq.empty() != true){
		stack.push(pq.top());
		pq.pop();
	}
}