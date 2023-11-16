// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      int sum=0;
      int start=0;
      int count=0;
      for(int final_iterator=0;final_iterator<nums.size();final_iterator++){
         sum+=nums[final_iterator];
         while(start<final_iterator&&sum>goal){
            sum-=nums[start];
            start++;
         }
         if(sum==goal){
            count++;
            int temp=start;
            while(temp<final_iterator && nums[temp]==0){
               count++;
               temp++;
            }
         }
      }
      return count;
    }
};

int main(){
   Solution s;
   vector<int> nums={0,0,0,0,0,0,1,0,0,0};
   int goal=0;
   cout<<s.numSubarraysWithSum(nums,goal);
}

// class Solution {

// public:

//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int left=0;
//         int right=0;
//         int count=0;
//         int sum=0;
//         while(right<nums.size())
//         {
//             sum+=nums[right];
//             while(left<right && sum>goal)
//             {
//               sum-=nums[left];
//                 left+=1;
//             }
//             if(sum==goal)
//             {
//                 int temp=left;
//                 while(temp<right && nums[temp]==0)
//                 {
//                     temp+=1;
//                     count+=1;
//                 }
//                 count+=1;
//             }
//             right+=1;
//         }
//         return count;
//     }
// };