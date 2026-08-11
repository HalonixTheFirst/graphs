#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  void findDist(vector<vector<int>> &adj, int src,vector<int> &dist,vector<int> &vis){
    vis[src]= true;
  }
  vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> dist(V,INT_MAX);
    vector<int> vis(V,false);
    for(auto i : edges){
      adj[i[0]].push_back(i[1]);
    }
    findDist(adj,0,dist,vis);
}
};
