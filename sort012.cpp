#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
   int start = 0;
   int end = n-1;
   int check = 0;
   while(check <= end){
      if(arr[check] == 0){
         swap(arr[start],arr[check]);
         start++;
         check++;
      }
      else if(arr[check] == 2){
         swap(arr[check],arr[end]);
         end--;
         // check++;
      }
      else{
         check++;
      }
   }
}