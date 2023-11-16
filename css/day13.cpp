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
    void bfs(int i,int j){
      pair<int,int> p{i,j};
      visited[i][j]=1;
      queue<pair<int,int>> q;
      q.push(p);  
      while(!q.empty()){
         pair<int,int>current=q.front();
         q.pop();
         for(int i=0;i<4;i++){
            int row_temp=current.first+row_move[i];
            int col_temp=current.second+col_move[i];
            if(row_temp>=0 && row_temp<temp_grid.size() && col_temp>=0 && col_temp<temp_grid[0].size() && temp_grid[row_temp][col_temp]==1 && visited[row_temp][col_temp]==0){
               visited[row_temp][col_temp]=1;
               temp_grid[row_temp][col_temp]=2;
               q.push({row_temp,col_temp});
            }
         }
      }
    }
    int orangesRotting(vector<vector<int>>& grid) {
      visited=vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),0));
      temp_grid=vector<vector<int>>(grid);
      for(int i=0;i<temp_grid.size();i++){
         for(int j=0;j<temp_grid[0].size();j++){
            if(temp_grid[i][j]==2){
               bfs(i,j);
               mint++;
            }
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