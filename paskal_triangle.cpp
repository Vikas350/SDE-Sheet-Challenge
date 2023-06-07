#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans;
    vector<long long int> v;
    if (n == 1)
    {
        ans.push_back({1});
        // return ans;
    }
    else
    {
        ans.push_back({1});
        ans.push_back({1, 1});
    }

    v = {1, 1};
    int p = n - 2;
    while (p > 0)
    {
        vector<long long int> s;
        s.push_back(1);
        for (int i = 0; i < v.size() - 1; i++)
        {
            s.push_back(v[i] + v[i + 1]);
        }
        s.push_back(1);
        ans.push_back(s);
        v = s;
        p--;
    }

    return ans;
}