#include<bits/stdc++.h>
using namespace std;
bool findCycle(vector<int> &pathVis,vector<int> &vis,int node,vector<vector<int>> &graph,vector<int> &mark){
  vis[node]=true;
  pathVis[node]=true;
  for(auto i : graph[node]){
    if(!vis[i]){
      if(findCycle(pathVis,vis,i,graph,mark)){
        mark[i]=false;
        return true;
      };
    }
    else if(pathVis[i]){
      mark[i]=false;
      return true;;
    }
  }
  pathVis[node]=false;
  mark[node]=true;
  return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph){
  vector<int> ans;
  vector<int> vis(graph.size()),pathVis(graph.size()),mark(graph.size());

  for(auto i : graph){
    for(auto node : i){
    if(!vis[node]){
     findCycle(pathVis,vis,node,graph,mark))
    }
  }
  }
  sort(ans.begin(),ans.end());
  return ans;
}

