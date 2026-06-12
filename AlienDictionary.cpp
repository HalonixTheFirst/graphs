#include<bits/stdc++.h>
using namespace std;
class Solution {
  //Compare two words . like 1st and 2nd.
  // find the first letter that isnt equal;
  // Create a directed edge between the first letter and the second letter
  // run a topo sort
  // return the topo sort
private:
  void findBigger(string a,string b, vector<unordered_set<int>> &adj){
    int ptr = 0;
     while(ptr<min(a.size(),b.size())){
       if(a[ptr]!=b[ptr]){
         adj[a[ptr]-'a'].insert(b[ptr] - 'a');
         return;
       }
       ptr++;
     }
  }
  string topo(vector<unordered_set<int>> &adj){
    string ans;
    vector<int> indegree(adj.size());
    for(int i =0 ;i<26;i++){
      for(auto tp : adj[i]) {indegree[tp]++;};
    }
    queue<int> q;
    for(int i =0 ;i<indegree.size();i++) if(indegree[i]==0) q.push(i);
    while(q.size()){
      auto tp = q.front();
      q.pop();
      char ch = tp+'a';
      ans+=ch;
      for(auto node: adj[tp]){
          indegree[node]--;
          if(indegree[node]==0) q.push(node);
      }
    }
    return ans;
  }

public:
  string findOrder(vector<string> &words) {
    vector<unordered_set<int>> adj(26);
    for(int i =0 ;i <words.size()-1;i++){
       findBigger(words[i],words[i+1],adj);
    }
    string ans= topo(adj);
   return ans;
}
};