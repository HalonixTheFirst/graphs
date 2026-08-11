#include<bits/stdc++.h>
using namespace std;
void dijkstra(int src,int dest,vector<int> &dist,vector<vector<pair<int,int>>> &adj,set<pair<int,int>> &s) {
  dist[src] = 0;
  while (!s.empty()) {
    auto it = *(s.begin());
    s.erase(it);
    int node = it.second;
    int d = it.first;
    for (auto i : adj[node]) {
      if (d + i.first < dist[i.second]) {
        if (dist[i.second]!=INT_MAX) s.erase({dist[i.second],i.second});
        dist[i.second] = d+i.first;
        s.insert(make_pair(d+i.first,i.second));
      }
    }
  }

}
int main(){
  int nodes = 5;
  vector<vector<pair<int,int>>> adj(nodes);
  adj[0].push_back({1,2});
  adj[0].push_back({2,5});
  set<pair<int,int>> s;
  vector<int> dist(nodes,INT_MAX);
  s.insert(make_pair(0,0));
  dijkstra(0,5,dist,adj,s);

}