#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &arr, int n)
{
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            arr[j++] = arr[i];
        }
    }

    arr[j] = arr[arr.size() - 1];

    return j + 1;
}