#include <bits/stdc++.h>
using namespace std;

vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    // Write your code here.
    priority_queue<pair<int,int>> pq;
        unordered_map<int,int> vk;
        vector<int> ans;
        
        for(auto x:nums){
            vk[x]++;
        }
        
        for(auto z:vk){
            pq.push({z.second,z.first});
        }
        
        while(k != 0){
            pair<int,int> p = pq.top();;
            pq.pop();
            
            ans.push_back(p.second);
            k--;
            
        }
        
        sort(ans.begin(),ans.end());
        return ans;
}