#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool detect(int V,vector<vector<int>>& adj, vector<int>& vis,int parent){
    vis[V]=true;
    for(auto i : adj(V)){
      if(!vis[i] && detect(i,adj,vis,i)) return true;
      else if(i!=parent) return true;
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
        if(detect(i,adj,vis,-1)) return true;
      }
    }
    return false;
  }
};
int main(){

}