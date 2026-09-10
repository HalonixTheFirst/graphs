#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  //pq = [time][curr_city]
  void travel(int k ,vector<vector<pair<int,int>>> &adj,vector<int> &dist) {
    pq.push({0,k});
    dist [k] = 0;
    while (pq.size()) {
      auto entry = pq.top();
      pq.pop();
      int time = entry.first;
      int city = entry.second;
      for (auto node : adj[city]) {
        if (time + node.second<dist[node.first]) {
          dist[node.first] = time+node.second;
          pq.push({dist[node.first],node.first});
        }
      }
    }
  }
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int> dist(n+1,INT_MAX);
    dist[0] = 0 ;
    //times[i] = {[src][dest][time]};
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i =0 ;i < times.size();i++) {
      int src = times[i][0];
      int dest = times[i][1];
      int cost = times[i][2];
      adj[src].push_back(make_pair(dest,cost));
    }
    travel(k,adj,dist);
    if (count(dist.begin(),dist.end(),INT_MAX ) ) return -1;
    return *max_element(dist.begin(),dist.end());
  }
};
/*
 * Notes:
 * 1 . Nodes start from 1 up to n . So sizes should be n+1;
 * 2. For dist if we set all of it to INT_MAX . Index 0 will never change cuz its not a node. This causes an error in the count function. Set it to zero before hand;
 * 3.
 */