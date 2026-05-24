// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//   bool dfs(vector<int> &vis,vector<int> &pathVis,vector<vector<int>> adj,int v){
// 	  vis[v]= true;
//     pathVis[v]=true;
//     for(auto i : adj[v]){
// 		if(!vis[i]){
//       if (dfs(vis,pathVis,adj,v))return true;
//  	    }
//       else if (pathVis[i]) {
//         return true;
//       }
//     }
//     pathVis[v]=false;
//     return false;
// }
// bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//     vector<int> vis(numCourses,false);
//     vector<int> pathVis(numCourses,false);
//     vector<vector<int>> adj(numCourses);
//     for(auto i : prerequisites){
//       adj[i[0]].push_back(i[1]);
//     }
//     for(int i =0; i <numCourses ; i++){
//       if(!vis[i]){
//         if(dfs(vis,pathVis,adj,i)==true) return false;
//     }
//
//     }
//     return true;
//   }
// };
// int main(){
//   return 0;
// }
//TOO SLOW TT
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> vis(numCourses,false);
    vector<vector<int>> adj(numCourses);
    for(auto i : prerequisites){
      adj[i[0]].push_back(i[1]);
    }
    queue<int> q;
    vector<int> ans;
    vector<int> indegree(numCourses);
    for (int i =0 ;i < numCourses;i++) {
      for (auto node : adj[i]) {
        indegree[node]++;
      }
    }
    for (int i =0; i< indegree.size();i++)if (indegree[i]==0) q.push(i);
    while (!q.empty()) {
      auto tp = q.front();
      q.pop();
      ans.push_back(tp);
      for (auto i : adj[tp]) {
        indegree[i]--;
        if (indegree[i]==0) {
          q.push(i);
        }
      }
    }
    return ans.size()==numCourses;
  }
};