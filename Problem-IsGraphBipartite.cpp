#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  bool dfs(int v, bool c,vector<int> &vis,vector<vector<int>>& graph) {
    vis[v]= c ? 1:0;
    for (auto i : graph[v]) {
      if (vis[i]) {
        if (vis[i]==vis[v]) return false;
      }
      else {
        dfs(i,!c,vis,graph);
      }
    }
    return true;
  }
public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> vis(graph.size(),0);
    return dfs(0,1,vis,graph);
  }
};
int main(){
  return 0;
}