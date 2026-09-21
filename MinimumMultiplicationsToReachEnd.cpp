#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

  int minSteps(vector<int>& arr, int start, int end) {
    queue<pair<int,int>> q;
    vector<int> dist(10000,INT_MAX);
    if (start == end ) return 0;
    q.push({start,0});
    dist[start] = 0;
    while (q.size()) {
      auto tp = q.front();
      q.pop();
      int steps = tp.second;
      int num = tp.first;
      if (dist[num]<steps) continue;
      for (auto i : arr) {
        int newNum = (num*i)%10000;
        if (newNum == end) return steps+1;
        if (dist[newNum] > steps+1) {
          q.push({newNum,steps + 1});
          dist[newNum ] = steps+1;
        }
      }

    }
    return -1;
  }
};