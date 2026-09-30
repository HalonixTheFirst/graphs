#include<bits/stdc++.h>
using namespace std;
// Prim's algorithm returns the edge weight of an MST.
// Uses a vis array and a priority_queue
// minheap - > {weight , node , parent}
// MST ARRAY HOLDS {node, parent}
//sum holds all the weights
class Solution{
  public:
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  vector<pair<int,int>> mst;
  int Solve(vector<vector<int>> &adj,vector<int> &vis) {
    pq.push({0,{0,-1}});
    int sum =0 ;
    while (!pq.empty()) {
      auto tp = pq.top();
      pq.pop();
      int wt = tp.first;
      int node = tp.second.first;
      int parent = tp.second.second;
      if (vis[node]) continue;
      sum+=wt;
      vis[node] =true;
      if (parent != -1) mst.push_back({parent,node});
      for (auto i : adj[node]) {
        if (vis[i[1]] == true) {
          continue;
        }
        else {
          pq.push({i[0],{i[1],node}});
        }
      }
    }
    return sum;
  }
};
int main(){

}