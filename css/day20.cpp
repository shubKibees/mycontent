// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0;
        int count=0;
        int temp_k=0;
        int window_start=0;
        for(int window_end=0;window_end<nums.size();window_end++){
            if(nums[window_end]&1){
               temp_k++;
            }
            while(window_start<window_end&&temp_k>k){
               if(nums[window_start]&1){
                   temp_k--;
                   window_start++;
               }
               window_start++;
            }
            if(temp_k==k){
                count++;
                int temp=window_start;
                while (temp<window_end&&!nums[temp]&1)
                {
                  count++;
                  temp++;
                }
            }
        }
        return count;
    }
};