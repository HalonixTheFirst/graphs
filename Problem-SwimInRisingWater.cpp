
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValidCell(vector<vector<int>> &grid,int row,int col) {
    if (row<0 || row>= grid.size() || col<0 || col>=grid[0].size()) return false;
    return true;
  }

  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
  int bfs(vector<vector<int>> &vis,vector<vector<int>> &grid,int n) {
    //int minCount = INT_MAX;
    vis[0][0]= grid[0][0];
    int drow[] = {0,-1,0,1};
    int dcol[] = {-1,0,1,0};
    int r,c;
    r=c=0;
    pq.push({grid[0][0],{r,c}});
    while (!pq.empty()) {
      auto tp = pq.top();
      pq.pop();

      int cnt = tp.first;
      int dr = tp.second.first;
      int dc = tp.second.second;
      if (vis[dr][dc] < cnt) continue;
      //minCount = min(minCount,cnt);
      for (int i =0 ;i < 4; i ++) {
        if (isValidCell(grid,dr+drow[i],dc+dcol[i])) {
          int newCnt = max(cnt,grid[dr+drow[i]][dc+dcol[i]]);
          if (newCnt < vis[dr+drow[i]][dc+dcol[i]]) {
            pq.push({newCnt,{dr+drow[i],dc+dcol[i]}});
            vis[dr+drow[i]][dc+dcol[i]] = newCnt;
          }
        }
      }
      if (dr == n-1 && dc == n-1) return cnt;
    }

    return 0;
  }
  int swimInWater(vector<vector<int>>& grid) {
    vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
    int count = bfs(vis,grid,grid.size());
    return count;
  }
};