#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int n,m;
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis,int i ,int j) {
      vis[i][j]=true;
      int drow[]= {0,-1,0,1};
      int dcol[]= {-1,0,1,0};
      for (int k=0;k<4;k++) {
        int nrow=i+drow[k];
        int ncol=j+dcol[k];
        if (ncol>=0 && ncol<m && nrow>=0 && nrow<n && !vis[nrow][ncol] && grid[nrow][ncol]) {
          dfs(grid,vis,nrow,ncol);
        }
      }
    }
    int numEnclaves(vector<vector<int>>& grid) {
      n=grid.size();
      m=grid[0].size();
      vector<vector<int>> vis(n,vector<int> (m,0));
      int count =0;
      for(int i =0; i<n;i++){
        for(int j =0; j<m ;j++){
          if (i==0 || i == n-1 || j ==0 || j == m-1 ) {
            if (grid[i][j]==1) dfs(grid,vis,i,j);
          }
        }
      }
      for(int i =0; i<n;i++){
        for(int j =0; j<m ;j++){
          if (grid[i][j]==1 && !vis[i][j]) {
            count++;
          }
        }
      }
      return count;
    }
};
int main(){
    return 0;
}
