#include <bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(vector<int> &nums, int n)
{
    // next_permutation(nums.begin(),nums.end());
    // return nums;

    int pivot;
    int succ;
    vector<int> arr = nums;
    // int n = nums.size();

    // step1 - find pivot
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            pivot = i - 1;
            break;
        }
    }

    // step2 - find successor
    for (int i = n - 1; i >= pivot + 1; i--)
    {
        if (nums[i] > nums[pivot])
        {
            succ = i;
            break;
        }
    }

    // step3 - swap
    swap(arr[pivot], arr[succ]);

    // step4 - reverse
    reverse(arr.begin() + (pivot + 1), arr.end());
    // nums = arr;
    return nums;
}