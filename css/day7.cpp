// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

//     Integers in each row are sorted in ascending from left to right.
//     Integers in each column are sorted in ascending from top to bottom.

// matrix = 
// [
//    [ 1,4 ,7 ,11,15],
//    [ 2, 5, 8,12,19],
//    [ 3, 6, 9,16,22],
//    [10,13,14,17,24],
//    [18,21,23,26,30]
// ]


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int y=matrix.size();
      int x=matrix[0].size();
      int i=0;
      int j=x-1;
      while(i<y&&j>=0){
         if(matrix[i][j]==target){
            return true;
         }
         else if(matrix[i][j]>target){
            j--;
         }
         else {
            i++;
         }
      }
      return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int y = matrix.size(), x = matrix[0].size();
        int i = 0, j = x - 1;
        while (i < y && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j--;
            else
                i++;        
        }
        return false;
    }
};

