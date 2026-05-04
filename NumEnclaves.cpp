class Solution {
private:
  void convert(vector<vector<char>> &board,vector<vector<int>>&mark) {
    for (int i =0 ; i< board.size() ;i ++) {
      for (int j=0;j<board[0].size();j++) {
        if (!mark[i][j]) board[i][j]='X';
      }
    }
  }
  void dfs(vector<vector<char>>& board,vector<vector<int>> &vis,vector<vector<int>> &mark,int i , int j) {
    vis[i][j]=true;
    if (board[i][j]=='O') mark[i][j]=true;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for (int k = 0 ;k <4;k++) {
      int nrow = i+drow[k];
      int ncol = j+dcol[k];
      if ( ncol>=0 && ncol<board[0].size() && nrow>=0 && nrow<board.size() && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
        dfs(board,vis,mark,nrow,ncol);
      }
    }
  }
public:
  void solve(vector<vector<char>>& board) {
    int n =board.size();
    int m =board[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> mark(n,vector<int>(m,0));
    for (int i =0 ;i<n ;i++) {
      for (int j =0 ;j<m;j++) {
        if (i==0 || i == n-1 || j == 0 || j==m-1) {
          if (board[i][j]=='O') dfs(board,vis,mark,i,j);
        }
      }
    }
    convert(board,mark);
  }
};