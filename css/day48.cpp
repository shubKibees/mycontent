// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void heapify(vector<int> &nums){
        int n = nums.size();
        for(int i(0);i<n;i++){
         int left  = 2*i+1;
         int right = 2*i+2;
         int max = i;
         if(left<n && nums[left]>nums[max]){
             max = left;
         }
         if(right<n && nums[right]>nums[max]){
             max = right;
         }
         if(max!=i){
             swap(nums[max],nums[i]);
         }
      }
    }
    int findKthLargest(vector<int>& nums, int k) {
      heapify(nums);
    }
};