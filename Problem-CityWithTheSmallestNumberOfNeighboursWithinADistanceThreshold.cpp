#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist;
    for (auto i : edges) {
      int src = i[0];
      int dest = i[1];
      int wt = i[2];
      dist.push_back({src,dest,wt});
    }

  }
};