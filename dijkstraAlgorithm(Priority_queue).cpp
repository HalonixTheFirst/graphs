#include<bits/stdc++.h>
using namespace std;
class Dijkstra {
public:
  vector<int> findShortestPaths(int source,int destination,vector<int> &dist,vector<vector<pair<int,int>>> &adj) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0,source));
    dist[source] = 0;
    while (!pq.empty()){
      auto d = pq.top().first;
      auto node = pq.top().second;
      pq.pop();
      if (d>dist[node]) continue;
      for (auto i : adj[node]) {
        if (dist[i.second]>d + i.first) {
          dist[i.second] = i.first + d;
          pq.push(make_pair(i.first+d,i.second));
        }
      }
    }
    return dist;
  }
};
int main(){

}