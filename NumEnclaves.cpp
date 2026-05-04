#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    int n,m;
public:
    int numEnclaves(vector<vector<int>>& grid) {
      n=grid.size();
      m=grid[0].size();
      vector<vector<int>> vis(n,vector<int> (m,0));
      int count =0;
      for(int i =0; i<n;i++){
        for(int j =0; j<m ;j++){
          if (i==0 || i == n-1 || j ==0 || j == m-1 ) {
            if (grid[i][j]==1)
          }
        }
      }
      return count;
    }
};
int main(){
    return 0;
}
