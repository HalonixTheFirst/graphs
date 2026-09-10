#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  //This pq will store entries like so : [cost][count,city];
  //The smallest current distance will be picked first to find
public:
  void findPath(vector<vector<pair<int,int>>>& adj,int src,int dst,int k, vector<int> &dist) {
    //
    dist[src] = 0;
    pq.push({0,{0,src}});
    while (pq.size()) {
      auto tp = pq.top();
      pq.pop();
      int cost = tp.first;
      int count = tp.second.first;
      int city = tp.second.second;
      if (count>k) continue;
      for (auto i : adj[city]) {
        int neighbour = i.first;
        int price = i.second;
        if (dist[neighbour]> cost + price) {
          dist[neighbour] = cost +price;
          pq.push({dist[neighbour],{count+1,neighbour}});
        }
      }
    }
  }

  //flights -> from[i],to[i],price[i]
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n,INT_MAX);
    vector<vector<pair<int,int>>> adj(n);
    for (int i =0 ;i<flights.size();i++) {
      adj[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
    }
    findPath(adj,src,dst,k,dist);
    if (dist[dst]==INT_MAX) return -1;
    return dist[dst];
  }
};