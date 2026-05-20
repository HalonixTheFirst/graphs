#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  void dfs(stack<int> &st,int v,vector<vector<int>> &adj,vector<int> &vis) {
    vis[v]=true;
    for (auto i : adj[v]) {
      if (!vis[i]) {
        dfs(st,i,adj,vis);
      }
    }
    st.push(v);
  }
public:
  vector<int> topoSort(vector<vector<int>>&adj,int V) {
    vector<int> ans;
    stack<int> st;
    vector<int> vis;
    for (int i =0;i<V;i++) if (!vis[i]) dfs(st,i,adj,vis);
    while (!st.empty()) {ans.push_back(st.top());st.pop();}
    return ans;
  }
};
int main(){
  Solution s;
  int V=6;
  vector<vector<int>> adj(V);
  adj[5].push_back(0);
  adj[5].push_back(2);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);
  s.topoSort(adj,4);
  return 0;
}