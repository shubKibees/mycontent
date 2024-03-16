/// minim spanning tree 

#include<bits/stdc++.h>
using namespace std;





int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
   int cost=0;
   map<int,vector<pair<int,int>>> m;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   for(int i=0;i<edges.size();i++){
      m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
      m[edges[i][1]].push_back({edges[i][0],edges[i][2]});
   }
   vector<int> vis(n,0);
   pq.push({0,0});
   while(!pq.empty()){
      auto it=pq.top();
      pq.pop();
      int weight=it.second;
      int node=it.first;
      if(vis[node]==1) continue;
      vis[node]=1;
      cost+=weight;
      for(auto it:m[node]){
         int adj=it.first;
         int w=it.second;
         if(!vis[adj]){
            pq.push({w,adj});
         }
      }
   }
   return cost;
}
