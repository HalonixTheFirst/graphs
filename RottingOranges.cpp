#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    for(int i =0 ;i <n;i++){
      for(int j=0;j<m;j++){
        if(grid[i][j]==2){
          q.push({{i,j},0});
          vis[i][j]=true;
        }
      }
    }
    int time = 0;
    while(q.size()){
      int column_index[] = {0,1,0,-1};
      int row_index[] = {-1,0,+1,0};
      int row = q.front().first.first;
      int column = q.front().first.second;
      time = max(time,q.front().second);
      q.pop();
      for(int i =0 ;i<4;i++){
        int curr_row = row + row_index[i];
        int curr_col = column + column_index[i];
        if(curr_row>=0 && curr_row<n && curr_col >=0 && curr_col<m && !vis[curr_row][curr_col] && grid[curr_row][curr_col]==1){
          q.push({{curr_row,curr_col},time+1});
          vis[curr_row][curr_col] =true;
        }
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(grid[i][j]==1 && !vis[i][j]) return -1;
      }
    }
    return time;
  }
};