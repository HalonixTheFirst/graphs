#include<bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>> &dist) {
  // dist => {{src,dest},{distance}};
  int V = dist.size();
  int INF = 1e8;
  for (int i =0 ;i < V; i++) {
    for (int j = 0; j< V; j++) {
      for (int k = 0; k< V ;k ++) {
        if (dist[i][k] != INF && dist[k][j]!=INF) {
          dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
      }
    }
  }
}
int main(){

}