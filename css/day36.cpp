
// You have been given an undirected, connected graph of <em><strong>‘V’</strong></em> vertices (labelled from 0 to V-1) and <em><strong>‘E’</strong></em> edges. Each edge connecting two nodes 'u' and 'v' has a weight denoting the distance between them.
// Your task is to find the shortest path distance from the source node <em><strong>'S'</strong></em> to all the vertices. You have to return a list of integers denoting the shortest distance between each vertex and source vertex 'S'.
// 1. There are no self-loops(an edge connecting the vertex to itself) in the given graph.

// 2. There are no parallel edges i.e no two vertices are directly connected by more than 1 edge.

// index--->{node,weight}
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
// vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
// {
//    vector<pair<int,int>>adj[vertices];
//    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//    vector<int> dist(vertices,INT_MAX);
//    for(auto v_t:edge){
//       adj[v_t[0]].push_back({v_t[1],v_t[2]});
//       adj[v_t[1]].push_back({v_t[0],v_t[2]});
//    }
//    dist[source]=0;
//    pq.push({0,source});
//    while(!pq.empty()){
//       int node=pq.top().second;
//       int distance=pq.top().first;
//       pq.pop();
//       for(auto node_instance:adj[node]){
//          int adj_node=node_instance.first;
//          int adj_distance=node_instance.second;
//          if(distance+adj_distance<dist[adj_node]){
//             dist[adj_node]=distance+adj_distance;
//             pq.push({dist[adj_node],adj_node});
//          }
//       }
//    }
//    return dist;
// }

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source){
   vector<pair<int,int>>adj[vertices];
   set<pair<int,int>>stak;
   vector<int> dist(vertices,INT_MAX);
   for(auto v_t:edge){
      adj[v_t[0]].push_back({v_t[1],v_t[2]});
      adj[v_t[1]].push_back({v_t[0],v_t[2]});
   }
   stak.insert({0,source});
   while (!stak.empty())
   {
      pair<int,int>p=*(stak.begin());
      stak.erase(stak.begin());
      int node=p.second;
      int distance=p.first;
      for(auto node_instance:adj[node]){
         int adj_node=node_instance.first;
         int adj_distance=node_instance.second;
         if(distance+adj_distance<dist[adj_node]){
            if(dist[adj_node]!=INT_MAX){
               stak.erase({dist[adj_node],adj_node});
            }
            dist[adj_node]=distance+adj_distance;
            stak.insert({dist[adj_node],adj_node});
         }
      }
      for(auto d:dist){
         cout<<d<<" ";
      }
      cout<<endl;
   }
   return dist;
}
