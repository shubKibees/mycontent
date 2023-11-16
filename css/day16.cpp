// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// ["X","X","X","X"],
// ["X","O","O","X"],
// ["X","X","O","X"],
// ["X","O","X","X"]

// ["X","X","X","X"],
// ["X","X","X","X"],
// ["X","X","X","X"],
// ["X","O","X","X"]

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
    vector<int>row_move;
   vector<int>col_move;
   vector<vector<bool>>visited;
public:
    Solution():row_move{-1,0,1,0},col_move{0,1,0,-1}{}
    void Dfs(pair<int,int>node,vector<vector<char>>&board){
      visited[node.first][node.second]=true;
      for(int i=0;i<4;i++){
         int new_row=node.first+row_move[i];
         int new_col=node.second+col_move[i];
         if (new_row >= 0 && new_row < board.size() && new_col >= 0 && new_col < board[0].size() && board[new_row][new_col] == 'O' && !visited[new_row][new_col]) {
            Dfs({new_row,new_col},board);
         }
      }
   
    }
    void solve(vector<vector<char>>& board) {
      visited=vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));
      for(int i=0;i<board.size();i++){
         for(int j=0;j<board[0].size();j++){
            if(i==0||j==0||i==board.size()-1||j==board[0].size()-1){
               if(board[i][j]=='O'){
                  Dfs({i,j});
                  visited[i][j]=true;
               }
            }
         }
      }
      for(int i=0;i<board.size();i++){
         for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='O'&&!visited[i][j]){
               board[i][j]='X';
            }
         }
      }
    }
};


class Solution
{
public:
   void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j)
   {
      vector<int> del_row{-1, 0, 1, 0};
      vector<int> del_col{0, 1, 0, -1};
      visited[i][j] = true;
      for (int k = 0; k < 4; k++)
      {
         int new_row = i + del_row[k];
         int new_col = j + del_col[k];
         if (new_row >= 0 && new_row < board.size() && new_col >= 0 && new_col < board[0].size() && !visited[new_row][new_col] && board[new_row][new_col] == 'O')
         {
            dfs(board, visited, new_row, new_col);
         }
      }
   }
   void solve(vector<vector<char>> &board)
   {
      vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
      for (int i = 0; i < board.size(); i++)
      {
         for (int j{0}; j < board[0].size(); j++)
         {
            if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)
            {
               if (board[i][j] == 'O')
               {
                  dfs(board, visited, i, j);
               }
            }
         }
      }
      for (int i{0}; i < board.size(); i++)
      {
         for (int j{0}; j < board[0].size(); j++)
         {
            if (board[i][j] == 'O' && !visited[i][j])
            {
               board[i][j] = 'X';
            }
         }
      }
   }
};