#include<bits/stdc++.h>
using namespace std;
class DSU {
private :
   vector<int> rank;
   vector<int> parent;
public:
   DSU(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      for (int i =0;i <= n;i++) parent[i]=parent[i];
   }
   int getParent(int n) {
      if (n == parent[n]) return n;
      else parent[n] = getParent(parent[n]);
   }
   void unio(int n ,int m){
      int p1 = getParent[n];
      int p2 = getParent[m];
      if (rank[p1] > rank[p2]) {
         parent[p2] = p1;
      }
      else if (rank[p2]> rank[p1]) {
         parent[p1] = p2;
      }
      else {
         parent[p1]= p2;
         rank[p2]++;
      }
   }
 };
int main() {

}