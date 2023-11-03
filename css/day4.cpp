// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   int findKthPositive(vector<int> &arr, int k)
   {
      vector<int> lost_integer;
      int arr_size = arr.size();
      int index_for_arr = 0;
      for (int i = 1; i <= arr[arr_size - 1]; i++)
      {
         if (arr[index_for_arr] == i)
         {
            index_for_arr++;
         }
         else
         {
            lost_integer.push_back(i);
         }
      }
      if (k <= lost_integer.size())
      {
         return lost_integer[k - 1];
      }
      else
      {
         return arr[arr_size - 1] + k - lost_integer.size();
      }
   }
};

//[1,4,6,8,9]