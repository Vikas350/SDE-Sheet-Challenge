#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end()); // sort the vector for ease
        int a,b;
        a = intervals[0][0];
        b = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            
            if(intervals[i][0] > b){
                ans.push_back({a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
            else if(intervals[i][0] <= b){
                b = max(b,intervals[i][1]); //here we change only b
                // because the value of a --> minimum hi hogi kyuki hmne sort kiya hai
            }
            
        }
        
        ans.push_back({a,b});
        
        return ans;
}
