#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	unordered_map<int,int> vk;
	for(int i=0; i<n; i++){
		vk[arr[i]]++;
		if(vk[arr[i]] > 1) return arr[i];
	}

	return -1;
}