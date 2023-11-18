// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dp(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int limit_y=heights[0].size()-1;
        int limit_x=heights.size()-1;
        pq.push({0,{0,0}});
        dp[0][0]=0;
        vector<int> dx={0,-1,0,1};
        vector<int> dy={-1,0,1,0};
        while(!pq.empty()){ 
            auto it=pq.top();
            pq.pop();
            int origin_x=it.second.first;
            int origin_y=it.second.second;
            if(origin_x==limit_x && origin_y==limit_y){
                return it.first;
            }
            for(int i(0);i<4;i++){
                int adj_x=origin_x+dx[i];
                int adj_y=origin_y+dy[i];
                if(adj_x>=0 && adj_x<=limit_x && adj_y>=0 && adj_y<=limit_y){
                    int effort=max(abs(heights[origin_x][origin_y]-heights[adj_x][adj_y]),it.first);
                    if(dp[adj_x][adj_y]>effort){
                        dp[adj_x][adj_y]=effort;
                        pq.push({effort,{adj_x,adj_y}});
                    }
                }
            }
        }
        return dp[limit_x][limit_y];
    }
};
