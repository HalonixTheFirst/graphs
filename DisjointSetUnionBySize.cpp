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
  void unionBySize(int u,int v) {
    int u_p = getParent(u);
    int v_p = getParent(v);
    if (u_p == v_p) return;
    if (size[v_p]>size[u_p]) {
      size[v_p]+=size[u_p];
      parent[u_p]=v_p;
    }
    else {
      size[u_p]+=size[v_p];
      parent[v_p]=u_p;
    }
  }
};