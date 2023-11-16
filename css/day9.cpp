// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

#include<iostream>
#include<vector>
using namespace std;

//try brute force
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//       int final_inde=0;
//       int end=nums.size()-1;
//       int count_1_max=0;
//       for(final_inde=0;final_inde<=end;final_inde++){ 
//          int temp_k=k;
//          int count_1=0;
//          for(int i=final_inde;i<=end;i++){
//             if(nums[i]==1){
//                count_1++;
//             }
//             else if(temp_k>0){
//                count_1++;
//                temp_k--;
//             }
//             else{
//                break;   
//             }
//             count_1_max=max(count_1_max,count_1);
//          }
//       }
//       return count_1_max;
//    }
// };

//sliding window approch
//k=3
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_consutive_one = 0;
        int start = 0;
        int iterator_position = 0;
        int temp_k = k;
        for (iterator_position = 0; iterator_position < nums.size(); iterator_position++) {
            if (nums[iterator_position] == 0 && temp_k) {
                temp_k--;
            } else if (nums[iterator_position] == 0 && !temp_k) {
                while (nums[start] != 0) {
                    start++;
                }
                start++;
            }
            max_consutive_one = max(max_consutive_one, iterator_position - start + 1);
        }
        return max_consutive_one;
    }
};

int main(){
   Solution obj;
   vector<int> nums={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
   int k=3;
   int ans=obj.longestOnes(nums,k);
   cout<<ans;
}
