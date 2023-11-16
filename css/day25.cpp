// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int last_value=nums[n-1];
        int count=nums.size();
        while(nums[0]>=last_value&&count){
              count--;
              nums.insert(nums.begin(),nums[n-1]);
              nums.pop_back();
              last_value=nums[n-1];
        }
        vector<int>temp=vector<int>(nums);
        sort(temp.begin(),temp.end());
        return temp==nums;
    }
};