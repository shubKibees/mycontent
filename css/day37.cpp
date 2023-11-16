// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//     All the visited cells of the path are 0.
//     All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.


// ["0,0",0]
// [1,1,"0"]
// [1,1,"0"]


// {distance,{x,y}}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int Y_n=grid.size();
        int X_n=grid[0].size();
        vector<vector<int>>distance(Y_n,vector<int>(X_n,INT_MAX));
        if(grid[0][0]==1)return -1;
        pq.push({1,{0,0}});
        distance[0][0]=1;
        vector<int>move{0,1,-1};
        while(!pq.empty()){
            int dist=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<move.size();i++){
                for(int j=0;j<move.size();j++){
                    if(i==j && i==0)continue;
                    int new_x=x+move[i];
                    int new_y=y+move[j];
                    if(new_x>=0 && new_x<Y_n && new_y>=0 && new_y<X_n && grid[new_x][new_y]==0 && distance[new_x][new_y]>dist+1){
                        distance[new_x][new_y]=dist+1;
                        pq.push({dist+1,{new_x,new_y}});
                    }
                }
            }
        }
        return distance[Y_n-1][X_n-1]==INT_MAX?-1:distance[Y_n-1][X_n-1];
    }
};