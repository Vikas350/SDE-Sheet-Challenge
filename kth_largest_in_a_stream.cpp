#include <bits/stdc++.h> 
using namespace std;
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       for(int i=0; i<arr.size(); i++){
           pq.push(arr[i]);
       }
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
        pq.pop();
    }

    int getKthLargest() {
       // Write your code here.
       return pq.top();
    }

};