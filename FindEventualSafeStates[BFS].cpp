//reverse edges.
//then run topo sort
//the ones who have indegree 0 are safeee
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> ans;
    vector<vector<int>> adj(graph.size());
    for(int i =0; i<graph.size();i++){
      for(auto node : graph[i]){
        adj[node].push_back(i);
      }
    }
    vector<int> indegree(graph.size(),0);
    for(int i =0 ;i <graph.size() ;i++){
      for(auto k : adj[i]) indegree[k]++;
    }
    queue<int> q;
    for(int i =0 ;i< indegree.size();i++){
      if(indegree[i]==0) q.push(i);
    }
    while(!q.empty()){
      auto tp =q.front();
      q.pop();
      for(auto i : adj[tp]){
        indegree[i]--;
        if(indegree[i]==0){
          q.push(i);
          ans.push_back(i);
        }
      }
    }
    sort(ans.begin(),ans.end());

    return ans;

  }
};