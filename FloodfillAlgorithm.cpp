#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int org = image[sr][sc];
    int n = image.size();
    int m =image[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    image[sr][sc] = color;
    queue<pair<int,int>> q;
    vis[sr][sc]=true;
    q.push({sr,sc});
    while(q.size()){
      auto tile = q.front();
      q.pop();
      //{a,b}
      // 1 1 1
      // 1 1 0 (1,1)
      // 1 0 1
      int col_ind[] ={0,-1,0,1};
      int row_ind[] ={-1,0,1,0};
      for(int i =0 ;i <4;i++){
        int cur_col = tile.second + col_ind[i];
        int cur_row = tile.first + row_ind[i];
        if(cur_row >= 0 && cur_row<n && cur_col >=0 && cur_col<m && image[cur_row][cur_col]==org && !vis[cur_row][cur_col]) {
          image[cur_row][cur_col]=color;
          q.push({cur_row,cur_col});
          vis[cur_row][cur_col]=true;
        }
      }
    }
    return image;
  }
};
int main(){

};