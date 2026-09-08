#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValidCell(vector<vector<int>> &grid,int row,int col) {
    if (row<0 || row>= grid.size() || col<0 || col>=grid[0].size() || grid[row][col] == 1) return false;
    return true;
  }
  void ans(vector<vector<int>> &grid,vector<vector<int>> &dist) {
    queue<pair<int,pair<int,int>>> q;
    q.push({1,make_pair(0,0)});
    dist[0][0]=1;
    while (!q.empty()) {
      auto entry = q.front();
      int curDist=entry.first;
      int row = entry.second.first;
      int col = entry.second.second;
      q.pop();
      if (curDist> dist[row][col]) continue;
      int drow[]={-1,-1,0, 1,1,1,0,-1};
      int dcol[]={0,-1,-1,-1,0,1,1,1};
      for (int i =0 ;i< 8;i++) {
        if (isValidCell(grid,row+drow[i],col+dcol[i]) && curDist+1 <dist[row+drow[i]][col+dcol[i]] ) {
          q.push({curDist+1,{row+drow[i],col+dcol[i]}});
          dist[row+drow[i]][col+dcol[i]]= min(curDist+1,dist[row+drow[i]][col+dcol[i]]);
        }
      }
    }
  }
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0]==1 || grid[grid.size()-1][grid.size()-1]==1) return -1;
    vector<vector<int>> dist(grid.size(),vector<int> (grid[0].size(),INT_MAX));
    int n = grid.size();
    ans(grid,dist);
    if (dist[n-1][n-1]==INT_MAX ) return -1;
    return dist[n-1][n-1];
  }
};
int main() {return 0;}