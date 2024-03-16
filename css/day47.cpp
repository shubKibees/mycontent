// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

//     For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

// A subarray is a contiguous part of an array.


#include <bits/stdc++.h>
using namespace std;
class Solution {
   int count;
public:
   Solution():count(0){}
   //brute method
   // int subarraysWithKDistinct(vector<int>& nums, int k) {
   //      int n = nums.size();
   //      for(int i(0);i<nums.size();i++){
   //       set<int> s;
   //       for(int j(i);j<nums.size();j++){
   //          s.insert(nums[j]);
   //          if(s.size()==k){
   //              count++;
   //          }
   //       }
   //      }
   //      return count;   
   //  }
   int subarraysWithKDistinct(vector<int>& nums, int k) {
    
   }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout<<s.subarraysWithKDistinct(nums,k);
}