#include<bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V,vector<vector<int>> &edges, int src){
  vector<int> dist(V,INT_MAX);
  dist[src] =0;
  for(int k =0; k<V;k++){
    for(auto i : edges){
      int u = i[0];
      int v = i[1];
      int wt = i[2];
      if(dist[u] != INT_MAX && dist[v]>dist[u] +wt ){
        if(k==V-1) return {-1};

        dist[v] = dist[u] + wt;
      }
    }
  }
  return dist;
}
//Int main copied from geeksforgeeks :P
int main() {

  // Number of vertices in the graph
  int V = 5;

  // Edge list representation: {source, destination, weight}
  vector<vector<int>> edges = {
    {1, 3, 2},
    {4, 3, -1},
    {2, 4, 1},
    {1, 2, 1},
    {0, 1, 5}
  };

  // Define the source vertex
  int src = 0;

  // Run Bellman-Ford algorithm to get shortest paths from src
  vector<int> ans = bellmanFord(V, edges, src);

  // Output the shortest distances from src to all vertices
  for (int dist : ans)
    cout << dist << " ";

  return 0;
}