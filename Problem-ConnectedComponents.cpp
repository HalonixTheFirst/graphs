#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countComponents(int V, vector<vector<int> > &edges) {
    //The edges matrix only has edges from a to b ;
    // edge between 0 and 1, 1 and 2; etc;
    vector<vector<int> > adj(V);
    for (auto pair: edges) {
      adj[pair[0]].push_back(pair[1]);
      adj[pair[1]].push_back(pair[0]);
    }
    //adj is now a proper adjacency list;
    int components = 0;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        components++;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        while (q.size()) {
          auto tp = q.front();
          q.pop();
          for (auto node: adj[tp]) {
            if (!vis[node]) {
              vis[node] = true;
              q.push(node);
            }
          }
        }
      }
    }
    return components;
  }
};

int main() {
  int V = 5;
  vector<vector<int> > edges = {{0, 1}, {1, 2}, {3, 4}};
  Solution sol;
  cout << "Number of Connected Components: " << sol.countComponents(V, edges) << endl;
  return 0;
}
