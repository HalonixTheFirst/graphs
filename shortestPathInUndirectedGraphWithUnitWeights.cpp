#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  void dfs(vector<vector<int>> &adj,int src,vector<int> &dist,queue<pair<int,int>> &q,vector<int> &vis) {
    auto node = q.front();
    vis[node.first] =1;
    dist[node.first]= min(dist[node.first],node.second);
    q.pop();
    for (auto i : adj[node.first]) {
      if (!vis[i]) {
        q.push(make_pair(i,node.second+1));
      }
    }
    while (!q.empty()) dfs(adj,src,dist,q,vis);
  }
public:
  vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
    vector<int> dist(V,INT_MAX);
    vector<int> vis(V,0);
    vector<vector<int>> adj(V);
    for (auto i : edges) {
      adj[i[0]].push_back(i[1]);
      adj[i[1]].push_back(i[0]);
    }
    queue<pair<int,int>> q;
    q.push(make_pair(src,0));
    dfs(adj,src,dist,q,vis);
    for (int i =0 ;i<dist.size();i++) {
      if (dist[i]==INT_MAX) dist[i]=-1;
    }
    return dist;

  }
};

int main(){

}