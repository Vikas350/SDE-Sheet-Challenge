#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int profit = 0;
    int n = prices.size();
    int buyVal = prices[0];
    for(int i=1; i<n; i++){
        int diff = prices[i] - buyVal;
        profit = max(profit,diff);
        buyVal = min(buyVal,prices[i]);
    }

    return profit;
}