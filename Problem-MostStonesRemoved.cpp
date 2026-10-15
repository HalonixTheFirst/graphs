#include<bits/stdc++.h>
using namespace std;
void dfs(int startRow,vector<int> &vis,vector<vector<int>> &stones) {
    vis[startRow]=1;
    for (int i =0;i<stones.size();i++) {
      if (!vis[i]){
        if (stones[i][0] == stones[startRow][0] || stones[i][1] == stones[startRow][1]) dfs(i,vis,stones);
      }
    }
}
class Solution {
public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    int components = 0;
    vector<int>vis(n,0) ;
    for (int i =0 ;i<n;i++){
      if (!vis[i]) {
        components++;
        dfs(i,vis,stones);
      }
    }
    return n - components;
  }
};