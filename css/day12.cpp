// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.



// [
   // [1,1,0],
   // [1,1,0],
   // [0,0,1]
// ]



#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class Solution {
   vector<vector<int>> adjLs; 
   vector<bool> visited;
public:
    void applyBFS(int node){
      queue<int> q;
      q.push(node);
      visited[node]=true;
      while(!q.empty()){
         int curr=q.front();
         q.pop();
         for(int it:adjLs[curr]){
            if(!visited[it]){
            q.push(it);
            visited[it]=true;
            }
         }
      }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      int count=0;
      visited.resize(isConnected.size(),false);
      adjLs.resize(isConnected.size());
      for(int i=0;i<isConnected.size();i++){
         for(int j=0;j<isConnected[0].size();j++){
            if(isConnected[i][j]==1&&i!=j){
               adjLs[i].push_back(j);
               adjLs[j].push_back(i);
            }
         }
      }
      for(int i=0;i<adjLs.size();i++){
         if(!visited[i]){
            count++;
            applyBFS(i);
         }
      }
    }
};