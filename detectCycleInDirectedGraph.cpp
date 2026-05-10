#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool dfs(vector<int> &vis,vector<int> &pathVis,vector<vector<int>> adj,int i){
    vis[i]=true;
    pathVis[i]=true;
    for(auto node  : adj[i]){
      if(!vis[node]){
        if(dfs(vis,pathVis,adj,node)) return true;
      }
      else if(pathVis[node]){
        return true;
      }
    }
    pathVis[i]=false;
    return false;
  }
  bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int> vis(V,0);
    vector<int> pathVis(V,0);
    vector<vector<int>> adj(V);
    for(auto i : edges){
      adj[i[0]].push_back(i[1]);
    }
    for(int i=0; i<V;i++)if(dfs(vis,pathVis,adj,i)) return true;
    return false;
}
};