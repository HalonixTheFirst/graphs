#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValidCell(vector<vector<int>> &grid,int row,int col) {
    if (row<0 || row>= grid.size() || col<0 || col>=grid[0].size()) return false;
    return true;
  }
  void findPath(vector<vector<int>> &dist, vector<vector<int>> &heights,int r,int c){
    dist[r][c]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{r,c}});
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,-1,0,1};
    while(!pq.empty()){
      auto entry = pq.top();
      pq.pop();
      int d1 = entry.first;
      int row = entry.second.first;
      int col = entry.second.second;
      if(d1 > dist[row][col]) continue;
      for(int i =0 ;i<4;i++){
        int nrow = drow[i] + row;
        int ncol = dcol[i] + col;
        if(isValidCell(heights,nrow,ncol)) {
          if(max(abs(heights[row][col] - heights[nrow][ncol]),dist[row][col]) < dist[nrow][ncol]) {
            dist[nrow][ncol] = max(abs(heights[row][col] - heights[nrow][ncol]),dist[row][col]);
            pq.push({max(dist[row][col],abs(heights[row][col] - heights[nrow][ncol])),{nrow,ncol}});
          }
        }
      }
    }

  }
  int minimumEffortPath(vector<vector<int>>& heights) {
    int num_rows = heights.size();
    int num_cols = heights[0].size();
    vector<vector<int>> dist(num_rows,vector<int>(num_cols,INT_MAX)) ;
    findPath(dist,heights,0,0);
    return dist [num_rows-1][num_cols-1];
  }
};
int main(){return 0;}