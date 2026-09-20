#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
  priority_queue<pair<long long ,long long>,vector<pair<long long,long long>>,greater<pair<long long ,long long>>> pq;
  int count =0;
  int min_time = LONG_LONG_MAX;

  void travel(vector<vector<pair<long long,long long >>> &adj,int n,vector<long long> &dist,vector<long long> &ways) {
    pq.push({0,0});
    dist[0]=0;
    while (pq.size()) {
      auto tp = pq.top();
      pq.pop();
      long long time = tp.first;
      long long city = tp.second;
      if (city == n-1) {
        if (time == min_time) count++;
        if (time<min_time) {
          min_time=time;
          count=1;
        }
      }
      if (time > dist[city]) continue;
      for (auto i : adj[city]) {
        if (time+i.second<dist[i.first]){
          pq.push({i.second+time,i.first});
          dist[i.first]=time+i.second;
          ways[i.first]=ways[city];
        }
        else if (time + i .second == dist [i.first]) {
          ways[i.first] =(ways[i.first]+ ways[city])%1000000007;
        }
        else continue;
      }
    }
  }
public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<long long,long long >>> adj(n);
    //roads = [u1,v1,time];
    vector<long long> dist(n,LONG_LONG_MAX);
    vector<long long> ways(n,0);
    ways[0]=1;
    for (int i =0 ;i< roads.size();i++) {
      adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
      adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
    }
    travel(adj,n,dist,ways);
    return ways[n-1];
  }
};