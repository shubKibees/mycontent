// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.


#include<iostream>
#include<vector>
using namespace std;

// class Solution {
//    int Max_Consecutive_Ones;
// public:
//     Solution():Max_Consecutive_Ones(0){}
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//       int count=0;
//         for(int i=0;i<nums.size();i++){
//          count+=nums[i];
//          if(nums[i]==0){
//             Max_Consecutive_Ones=max(Max_Consecutive_Ones,count);
//             count=0;
//          }
//         }
//         return max(Max_Consecutive_Ones, count);
//     }
// };


class Solution {
public:
    int singleNumber(vector<int>& nums) {
         int n = nums.size();

    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[nums[i]]++;
    }
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }
    return -1;
    }
};
