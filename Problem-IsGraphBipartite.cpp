#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  bool dfs(int v, bool c,vector<int> &vis,vector<vector<int>>& graph) {
    vis[v]= c ? 1:2;
    for (auto i : graph[v]) {
      if (vis[i]) {
        if (vis[i]==vis[v]) return false;
      }
      else {
        return dfs(i,!c,vis,graph);
      }
    }
    return true;
  }
public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> vis(graph.size(),0);
    for(int i = 0; i < graph.size();i++) {
      if(!vis[i]){
        if(dfs(i,1,vis,graph)==false) return false;
      }
    }
    return true;
  }
};
int main(){
  return 0;
}