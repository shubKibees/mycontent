// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.




// [
// [0,0,0],
// [0,1,0],
// [1,1,1]
// ]
// [
// [0,0,0],
// [0,1,0],
// [1,2,1]
// ]
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
   vector<vector<int>> ans;
   vector<vector<int>> visited;
   vector<int>row_move;
   vector<int>col_move;
public:
    Solution():row_move{-1,0,1,0},col_move{0,1,0,-1}{}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      ans=vector<vector<int>>(mat.size(),vector<int>(mat[0].size(),-1));
      visited=vector<vector<int>>(mat.size(),vector<int>(mat[0].size(),0));
      queue<pair<pair<int,int>,int>> q;
      for(int i=0;i<mat.size();i++){
         for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==0){
               q.push({{i,j},0});
               visited[i][j]=1;
               ans[i][j]=0;
            }
         }
      }
      while(!q.empty()){
         pair<pair<int,int>,int> current=q.front();
         q.pop();
         for(int i=0;i<4;i++){
            int new_row=current.first.first+row_move[i];
            int new_col=current.first.second+col_move[i];
            if(new_row>=0 && new_row<mat.size() && new_col>=0 && new_col<mat[0].size()&&visited[new_row][new_col]!=1){
               visited[new_row][new_col]=1;
               q.push({{new_row,new_col},current.second+1});
               ans[new_row][new_col]=current.second+1;
            }
         }
      }
      return ans;
    }
};