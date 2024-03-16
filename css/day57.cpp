// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int resolve(int y,int x,vector<vector<int>>& grid){
      //base case
      if(y==1 && x==1){
         return grid[0][0];
      }
      int to_left=0;
      if(x-1>0){
        to_left=grid[y][x]+resolve(y,x-1,grid);
      }
      int to_top=0;
      if(y-1>0){
      to_top=grid[y][x]+resolve(y-1,x,grid);
      }
      return max(to_left,to_top);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int y=grid.size();
        int x=grid[0].size();
        return resolve(y,x,grid);
    }
};