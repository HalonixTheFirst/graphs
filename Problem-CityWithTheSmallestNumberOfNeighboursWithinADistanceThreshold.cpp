#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int INF = 1e9;
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n,vector<int>(n,INF)) ;
    for (int i =0 ;i<edges.size();i++) {
      for (int j =0 ;j<edges.size();j++) {
        if (i == j) dist[i][j] =0;
      }
    }
    for (int i =0 ;i < n; i++) {
      for (int j = 0; j< n; j++) {
        for (int k = 0; k< n ;k ++) {
          if (dist[i][k] != INF && dist[k][j]!=INF) {
            dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
          }
        }
      }
    }
    int bestCount =0 ;
    int answer =-1 ;
    for (int i =0 ;i<n;i++) {
      int count =0 ;
      for (int j =0 ;j<n;j++) {
        if (i!=j) {
          if (dist[i][j]<distanceThreshold) count++;
        }
      }
      if (count<=bestCount) {
        bestCount= count;
        answer = i;
      }
    }
    return answer;
  }
};