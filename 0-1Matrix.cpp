#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> ans(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i =0; i<n;i++){
      for(int j =0 ;j<m;j++){
        if(mat[i][j]==0){
          q.push({{i,j},0});
          vis[i][j]=1;
        }
      }
    }
    while(q.size()){
      auto row = q.front().first.first;
      auto col = q.front().first.second;
      auto step = q.front().second;
      q.pop();
      ans[row][col]=step;
      int rowArr[] = {0,-1,0,1};
      int colArr[] = {-1,0,1,0};
      for(int  i =0 ;i <4 ;i++){
        int nrow= row+rowArr[i];
        int ncol= col+colArr[i];
        if( nrow>=0 && nrow< n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
          {
            vis[nrow][ncol]=true;
            q.push({{nrow,ncol},step+1});
          }
        }
      }
    }
    return ans;
  }
};