// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

//     For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// bi---->ai
//1----->0

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
         for(auto it:adj[i]){
             indegree[it]++;
         }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
         if(indegree[i]==0){
            q.push(i);
         }
        }
        vector<int> topo;
        while(!q.empty()){
         int node=q.front();
         q.pop();
         topo.push_back(node);
         for(auto it:adj[node]){
            indegree[it]--;   
            if(indegree[it]==0){
               q.push(it);
            }
         }
        }
        return (topo.size()==numCourses)?topo:vector<int>();
    }
};