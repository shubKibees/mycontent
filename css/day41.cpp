// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700


// queue input {k,{dist,node}}
#include<bits/stdc++.h>
using namespace std;
class Solution {
   vector<pair<int,int>> adj[100];
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
      for(auto temp_vect:flights){
            adj[temp_vect[0]].push_back({temp_vect[1],temp_vect[2]});
        }
      vector<int> dist(n,INT_MAX);
      dist[src]=0;
      pq.push({0,{0,src}});
      while(!pq.empty()){
         int stops=pq.top().first;
         int distance=pq.top().second.first;
         int node=pq.top().second.second;
         pq.pop();
         if(stops>k){
            continue;
         }
         for(auto temp_vect:adj[node]){
            int adj_node=temp_vect.first;
            int dist_adj_node=temp_vect.second;
            if(distance+dist_adj_node<dist[adj_node]&&stops<=k){
               dist[adj_node]=distance+dist_adj_node;
               pq.push({stops+1,{dist[adj_node],adj_node}});
            }
         }
      }
      return dist[dst]==INT_MAX?-1:dist[dst];
    }
};