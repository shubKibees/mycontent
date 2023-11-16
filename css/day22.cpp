// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return true if you can finish all courses. Otherwise, return false.

//edge       

//0<---1      
//0<---4
//1<---2
//2<---3


//         0<---1<---2<---3
//         ^
//         |
//         |
//         4

//vertix       degree
//0               2
//1               1
//2               1
//3               0
//4               0


#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> adj[numCourses];
      for(int i=0;i<prerequisites.size();i++){
          adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
      }
      vector<int> indegree(numCourses,0);
      for(int i=0;i<numCourses;i++){
         for(auto it:adj[i]){
            indegree[it]++;
         }
      }
      queue<int> queu;
      for(int i=0;i<numCourses;i++){
         if(indegree[i]==0){
            queu.push(i);
         }
      }
      vector<int> ans;
      while (!queu.empty())
      {
         int node=queu.front();
         queu.pop();
         ans.push_back(node);
         for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
               queu.push(it);
            }
         }
      }
      if(ans.size()==numCourses){
         return true;
      }
      return false;
    }
};