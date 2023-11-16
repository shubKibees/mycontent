// You are given an m x n integer matrix matrix with the following two properties:

//     Each row is sorted in non-decreasing order.
//     The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.


#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int y=matrix.size();
        int x=matrix[0].size();
        int initial=0;
        int final=x*y-1;
        while(initial<=final){
         int mid=(initial+final)/2;
         int row=mid/x;
         int col=mid%x;
         if(matrix[row][col]==target){
            return true;
         }
         else if(matrix[row][col]<target){
            initial=mid+1;
         }
         else{
            final=mid-1;
         }
        }
        return false;
    }
};