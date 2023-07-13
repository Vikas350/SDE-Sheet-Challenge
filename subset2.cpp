#include <bits/stdc++.h> 
using namespace std;
void fun(vector<int> &arr,vector<int> subset,set<vector<int>> &st,int n,int idx){
    if(idx == n){
        // sort(subset.begin(),subset.end());
        st.insert(subset);
        return ;
    }

    fun(arr,subset,st,n,idx+1);

    int element = arr[idx];
    subset.push_back(element);

    fun(arr,subset,st,n,idx+1);

}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    set<vector<int>> st;
    vector<int> subset;
    sort(arr.begin(),arr.end());
    fun(arr,subset,st,n,0);
    for(auto x:st){
        ans.push_back(x);
    }

    return ans;
    
}