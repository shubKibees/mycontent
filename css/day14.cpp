// You are given an m x n grid where each cell can have one of three values:

//     0 representing an empty cell,
//     1 representing a fresh orange, or
//     2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
   vector<vector<int>> visited;
   vector<vector<int>> temp_grid;
   vector<int>row_move;
   vector<int>col_move;
   int mint;
public:
    Solution():mint{0},row_move{-1,0,1,0},col_move{0,1,0,-1}{}
    int orangesRotting(vector<vector<int>>& grid) {
      visited=vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),0));
      temp_grid=vector<vector<int>>(grid);
      queue<pair<int,int>>queueOfRottenOrange;
      for(int i=0;i<temp_grid.size();i++){
         for(int j=0;j<temp_grid[0].size();j++){
            if(temp_grid[i][j]==2){
               queueOfRottenOrange.push({i,j});
            }
         }
      }
      while(!queueOfRottenOrange.empty()){
         int no_of_rotten_oranges_push=queueOfRottenOrange.size();
         while(no_of_rotten_oranges_push--){
         pair<int,int>rotten_orange=queueOfRottenOrange.front();
         queueOfRottenOrange.pop();
         for(int i=0;i<4;i++){
            int new_row=rotten_orange.first+row_move[i];
            int new_col=rotten_orange.second+col_move[i];
            if(new_row>=0 && new_row<temp_grid.size() && new_col>=0 && new_col<temp_grid[0].size() && temp_grid[new_row][new_col]==1){
               temp_grid[new_row][new_col]=2;
               queueOfRottenOrange.push({new_row,new_col});
            }
         }
         }
         if(!queueOfRottenOrange.empty()){
            mint++; 
         }
      }
      for(int i=0;i<temp_grid.size();i++){
         for(int j=0;j<temp_grid[0].size();j++){
            if(temp_grid[i][j]==1){
               return -1;
            }
         }
      }
      return mint;
    }
};