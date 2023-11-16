// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
   vector<int>row_move;
   vector<int>col_move;
   vector<vector<bool>> visited;
public:
    Solution():row_move{-1,0,1,0},col_move{0,1,0,-1}{}
    void dfs(vector<vector<int>>& grid,pair<int,int>node){
       visited[node.first][node.second]=true;
      for(int i=0;i<4;i++){
         int new_row=node.first+row_move[i];
         int new_col=node.second+col_move[i];
         if (new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size() && grid[new_row][new_col] == 1 && !visited[new_row][new_col]) {
            dfs(grid,{new_row,new_col});
         }
      }
    }
    int numEnclaves(vector<vector<int>>& grid) {
      visited=vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size(),false));
      for(int i=0;i<grid.size();i++){
         for(int j=0;j<grid[0].size();j++){
            if(i==0||j==0||i==grid.size()-1||j==grid[0].size()-1){
               if(grid[i][j]==1){
                  visited[i][j]=true;
                  dfs(grid,{i,j});
               }
            }
         }
      }
      int count=0;
      for(int i=0;i<grid.size();i++){
         for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1&&!visited[i][j]){
               count++;
            }
         }
      }
      return count;
    }
};