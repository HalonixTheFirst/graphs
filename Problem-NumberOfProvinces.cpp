#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  void dfs(int i,vector<vector<int>>& adj, vector<int> &vis){
    vis[i]=true;
    for(int j=0;j<adj.size();j++){
      if(adj[i][j] && !vis[j]) dfs(j,adj,vis);
    }

  }
  int findCircleNum(vector<vector<int>>& isConnected) {
    int cnt=0;
    vector<int> vis(201);
    for(int i=0;i<isConnected.size();i++) {
      if(!vis[i]) {
        cnt++;
        dfs(i,isConnected,vis);
      }
    }
    return cnt;
  }

};