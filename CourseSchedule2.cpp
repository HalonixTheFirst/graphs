#include<bits/stdc++.h>
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    vector<int> indegree(numCourses,0);
    vector<int> vis(numCourses,0);
    queue<int> q;
    vector<vector<int>> adj(numCourses);
    for(auto pair : prerequisites){
      adj[pair[1]].push_back(pair[0]);
    }
    for(int i =0 ;i<numCourses;i++){
      for(auto node : adj[i]){
        indegree[node]++;
      }
    }
    for(int i =0 ;i<numCourses;i++) if(indegree[i]==0) q.push(i);
    while(!q.empty()){
      auto node = q.front();
      q.pop();
      vis[node]= true;
      for(auto i : adj[node]){
        indegree[i]--;
        if(indegree[i]==0){
          q.push(i);
        }
      }
      ans.push_back(node);
    }
    if(ans.size() == numCourses) return ans;
    else return {};
  }
};