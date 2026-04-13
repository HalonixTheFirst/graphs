#include <bits/stdc++.h>
using namespace std;
/*
1 2
1 5
2 3
2 4
3 4
4 5
 */
void dfs(vector<vector<int>> &adj,int v,vector<int> &res,vector<int> &visited) {
  visited[v]=true;
  res.push_back(v);
  for (auto i : adj[v]) {
    if (!visited[i])dfs(adj,i,res,visited);
  }
}
int main(){
  int n=5;
  int m=6;
  vector<vector<int>> v(n+1);
  while(m--){
    int c,k;
    cin>>c>>k;
    v[c].push_back(k);
    v[k].push_back(c);
  }
  vector<int> res;
  vector<int> vis(n+1,false);
  dfs(v,1,res,vis);
  for (auto i : res) cout<<i<<" ";
}