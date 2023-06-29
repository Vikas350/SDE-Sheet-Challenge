#include <bits/stdc++.h> 
using namespace std;
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> s;
    s.push(INT_MAX);
    vector<int> v;
    for(int i=n-1; i>=0; i--){
        int p = arr[i];
        while(s.top() <= p){
            s.pop();
        }

        if(s.size() == 1) v.push_back(-1);
        else v.push_back(s.top());

        s.push(p);
    }

    reverse(v.begin(),v.end());

    return v;
}