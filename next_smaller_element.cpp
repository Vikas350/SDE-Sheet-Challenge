#include <bits/stdc++.h> 
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--){
        int p = arr[i];
        while(s.top() >= p){
            s.pop();
        }

        int x = s.top();
        ans[i] = x;
        s.push(p);
    }

    return ans;
}