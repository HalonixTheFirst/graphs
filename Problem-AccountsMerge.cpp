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
class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int userNo = 1;
    int c = -1;
    DSU s(accounts.size()-1);
    vector<string> names(accounts.size());
    unordered_map<string,int> mpp;
    for (int i =0 ;i<accounts.size();i++) {
      for (int j =1;j<accounts[i].size();j++) {
        if (mpp.find(accounts[i][j]) != mpp.end()) {
          s.unionBySize(i,mpp[accounts[i][j]]);
        }
        else {
          mpp[accounts[i][j]] = i;
        }
      }
    }
    vector<vector<string>> ans;
    vector<vector<string>> mail(accounts.size());
    for (auto i : mpp) {
      string m = i.first;
      int node = s.getParent(i.second);
      mail[node].push_back(m);
    }
    for (int i =0 ;i < mail.size();i++) {
      if (mail[i].size()==0) continue;
      sort(mail[i].begin(),mail[i].end());
      vector<string> temp;
      temp.push_back(accounts[i][0]);
      for (auto j :mail[i] ) {
        temp.push_back(j);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};
