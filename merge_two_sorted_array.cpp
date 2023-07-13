#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
	// Write your code here.
	vector<int> ans(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                ans[k] = nums1[i];
                i++;
            }
            else if(nums1[i]>nums2[j])
            {
                ans[k] = nums2[j];
                j++;
            }
            else
            {
                ans[k] = nums1[i];
                ans[k+1] = nums2[j];
                i++;
                j++;
                k++;
            }
            
            k++;
        }
        for( ;i<m; i++)
        {
            ans[k] = nums1[i];
            k++;
        }
        for( ;j<n; j++)
        {
            ans[k] = nums2[j];
            k++;
        }
        
		return ans;
        
}