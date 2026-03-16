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
void bfs(vector<vector<int>> &adj,int n, vector<int> &res) {
  vector<int> visited(n+1,0);
  queue<int> q;
  q.push(1);
  visited[1]=true;
  while (q.size()) {
    auto tp=q.front();
    q.pop();

    res.push_back(tp);
    for (auto i : adj[tp]) if (!visited[i]){visited[i]=true;q.push(i);}
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
  bfs(v,n,res);
  for (auto i : res) cout<<i<<" ";
}