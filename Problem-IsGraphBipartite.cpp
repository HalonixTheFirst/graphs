#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  bool dfs(int v, bool c,vector<int> &vis,vector<vector<int>>& graph) {
    if(c) vis[v]=1;
    else vis[v]=2;
    for (auto i : graph[v]) {
      if (vis[i]) {
        if (vis[i]==vis[v]) return false;
      }
      else {
        if (dfs(i,!c,vis,graph)==false) return false;;
      }
    }
    return true;
  }
public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> vis(graph.size(),0);
    for(int i = 0; i < graph.size();i++) {
      if(!vis[i]){
        if(!dfs(i,1,vis,graph)) return false;
      }
    }
    return true;
  }
};
int main(){
  return 0;
}