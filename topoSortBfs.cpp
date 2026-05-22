#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for(auto i : edges){
      adj[i[0]].push_back(i[1]);
    }
    vector<int> topo;
    vector<int> indegree(V);
    for (int i =0; i<V;i++) {
      for (auto it : adj[i]) {
        indegree[it]++;
      }
    }
    queue<int> q;
    for (int i =0 ;i<V;i++) {
      if (indegree[i]==0) q.push(i);
    }
    while (!q.empty()) {
      auto node = q.front();
      q.pop();
      topo.push_back(node);
      for (auto i : adj[node]) {
        indegree[i]--;
        if (indegree[i]==0) {
          q.push(i);
        }
      }
    }
    return topo;
  }
};