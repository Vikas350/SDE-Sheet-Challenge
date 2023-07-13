#include <bits/stdc++.h>
using namespace std;
void fun(vector<int> &num, vector<int> &ans, int n, int index, int sum){
	if(index == n){
		ans.push_back(sum);
		return ;
	}

	//pick
	fun(num,ans,n,index+1,sum + num[index]);

	//not pick
	fun(num,ans,n,index+1,sum);

}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int> ans;
	int n = num.size();
	fun(num,ans,n,0,0);
	sort(ans.begin(),ans.end());
	return ans;
}