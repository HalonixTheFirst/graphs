#include<bits/stdc++.h>
using namespace std;
class DSU {
private:
  vector<int> size;
  vector<int> parent;
public:
  DSU(int n){
    size.resize(n+1,0);
    parent.resize(n+1);
    for (int i= 0;i<=n;i++) parent[i]=parent[i];
  }
  int getParent(int v) {
    if (v == parent[v]) return v;
    else parent[v]= getParent(parent[v]);
  }
  void unionBySize(int n,int m) {
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
int main(){

}