#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool detect(int V,vector<vector<int>>& adj, vector<int>& vis){
    vis[V]=true;
    queue<pair<int,int>> q;
    q.push({V,-1});
    while(q.size()){
      auto parent = q.front().second;
      auto node = q.front().first;
      q.pop();
      for(auto i : adj[node]){
        if(!vis[i]) {
          vis[i]=true;
          q.push({i,node});
        }
        else if(parent!=i) return true;
      }
    }
    return false;
  }
  bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> vis(V,0);
    for(auto &edge : edges){
      int j = edge[0];
      int k = edge[1];
      adj[j].push_back(k);
      adj[k].push_back(j);
    }
    for(int i =0 ;i <V;i++){
      if(!vis[i]){
        if(detect(i,adj,vis)) return true;
      }
    }
    return false;
  }
};
int main(){

}