#include<bits/stdc++.h>
using namespace std;
class DSU {
public:
  vector<int> size;
  vector<int> parent;
  DSU(int n){
    size.resize(n+1,1);
    parent.resize(n+1);
    for (int i= 0;i<=n;i++) parent[i]=i;
  }
  int getParent(int v) {
    if (v == parent[v]) return v;
    else return parent[v]= getParent(parent[v]);
  }
  void unionBySize(int u,int v) {
    int u_p = getParent(u);
    int v_p = getParent(v);
    if (u_p == v_p) return;
    if (size[v_p]>size[u_p]) {
      size[v_p]+=size[u_p];
      parent[u_p]=v_p;
    }
    else {
      size[u_p]+=size[v_p];
      parent[v_p]=u_p;
    }
  }
};
bool isValid(int nrow,int ncol,vector<vector<int>> &board,vector<vector<int>> &vis) {
  return (ncol>=0 && ncol<board[0].size() && nrow>=0 && nrow<board.size() && !vis[nrow][ncol] && board[nrow][ncol] == 1);
    }
bool isValidSum(int nrow,int ncol,vector<vector<int>> &board) {
  return (ncol>=0 && ncol<board[0].size() && nrow>=0 && nrow<board.size() && board[nrow][ncol] == 1);
}
void dfs(vector<vector<int>> &vis,vector<vector<int>> &grid,int parent,int row,int col ,DSU &s) {
  int drow[] = {0,-1,0,1};
  int dcol[] = {-1,0,1,0};
  vis[row][col]=true;
  for (int k =0; k<4;k++) {
    int nrow = row + drow[k];
    int ncol = col +dcol[k];

    if (isValid(nrow,ncol,grid,vis)) {
      s.unionBySize(nrow*grid.size()+ncol,row*grid.size() + col);
      dfs(vis,grid,parent,nrow,ncol,s);
    }
  }

}
class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    //unordered_map<int,int> mpp;
    DSU s(n*n);
    vector<vector<int>> vis(n,vector<int> (n,0));
    for (int i =0 ;i < n ;i++) {
      for (int j =0 ;j< n;j++) {
        int parent = i*n + j;
        if (!vis[i][j] && grid[i][j]) dfs(vis,grid,parent,i,j,s);
      }
    }
    int drow[] = {0,-1,0,1};
    int dcol[] = {-1,0,1,0};
    int sum =0 ;
    for (int i=0 ;i<n;i++) {
      for (int j=0;j<n;j++) {
        if (grid[i][j]==0) {
          int curSum = 1;
          unordered_set<int> sums;
          for (int k =0 ;k<4;k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            if (isValidSum(nrow,ncol,grid)) {
              //curSum += mpp[s.getParent(nrow*n +ncol)];
              //curSum += s.size[s.getParent(nrow*n+ncol)];
              sums.insert(s.getParent(nrow*n+ncol));
            }
          }
          for (auto k : sums) curSum +=s.size[k];
          sum = max(sum,curSum);
        }
      }
    }
    if (!sum) return s.size[s.getParent(0)];
  return sum;
  }
};