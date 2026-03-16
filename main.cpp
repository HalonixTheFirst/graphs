#include <bits/stdc++.h>
using namespace std;
int main(){
  int n=10;
  vector<vector<int>> v(n+1);
  int m;
  cout<<"Enter m\n";
  cin>>m;
  for(int i=0;i<m;i++){
    int c,k;
    cin>>c>>k;
    v[c].push_back(k);
    v[k].push_back(c);
  }
}