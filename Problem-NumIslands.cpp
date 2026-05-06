#include<bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int n,m;
    void dfs(vector<vector<char>>& grid , int i ,int j ,vector<vector<int>>&vis){
      vis[i][j]=1;
      int drow[]={-1,0,1,0};
      int dcol[]={0,-1,0,1};
      for(int k =0 ;k < 4;k++){
        int row= i + drow[k];
        int col = j + dcol[k];
        if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]){
          dfs(grid,row,col,vis);
        }
      }
    }
public:
  int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    n = grid.size();
    m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(grid[i][j]=='1' && !vis[i][j]){
          cnt++;
          dfs(grid,i,j,vis);
        }
      }
    }
    return cnt;
  }
};
int main(){
  return 0;
}