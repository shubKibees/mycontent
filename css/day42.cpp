// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

//{start:pair<end,time>}

#include <bits/stdc++.h>
using namespace std;
class Solution
{
   vector<pair<int, int>> adj[100];

public:
   int networkDelayTime(vector<vector<int>> &times, int n, int k)
   {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      for (auto temp_vect : times)
      {
         adj[temp_vect[0]].push_back({temp_vect[1], temp_vect[2]});
      }
      vector<int> time_vector(n+1, INT_MAX);
      time_vector[0]=0;
      time_vector[k] = 0;
      pq.push({0, k});
      while(!pq.empty()){
         int time = pq.top().first;
         int node = pq.top().second;
         pq.pop();
         for(auto adj_pair : adj[node]){
            if(time+adj_pair.second<time_vector[adj_pair.first]){
               time_vector[adj_pair.first] = time+adj_pair.second;
               pq.push({time_vector[adj_pair.first], adj_pair.first});
            }
         }
      }
      for(auto x:time_vector){
         if(x==INT_MAX){
            return -1;
         }
      }
      return *max_element(time_vector.begin(), time_vector.end());
   }
};