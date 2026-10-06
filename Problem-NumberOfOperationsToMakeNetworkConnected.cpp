#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class DSU {

public:
  vector<int> size;
  vector<int> parent;
  DSU(int n){
    size.resize(n+1,1);
    parent.resize(n+1);
    for (int i= 0;i<=n;i++) parent[i]=i;
  }
  int getParent(int v) {
    if (v == parent[v]) return v;
    else return parent[v]= getParent(parent[v]);
  }
  void unionBySize(int n,int m) {
    n = getParent(n);
    m = getParent(m);
    if (n==m) return;
    if (size[m]>size[n]) {
      size[m]+=size[n];
      parent[n]=m;
    }
    else if (size[n]>size[m]) {
      size[n]+=size[m];
      parent[m]=n;
    }
    else {
      size[n]+=size[m];
      parent[m]=n;
    }
  }
};

class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    DSU s(n);
    int extra = 0;
    for (auto i : connections) {
      if (s.getParent(i[0])==s.getParent(i[1])) extra++;
      else s.unionBySize(i[0],i[1]);
    }
    int comp = 0;
    for (int i =0 ;i<n ;i++) {
      if (s.parent[i] == i) comp++;
    }
    if (comp -1 <= extra) return comp-1;
    return -1;
  }
};
