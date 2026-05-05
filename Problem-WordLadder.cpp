#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    unordered_set<string> s(wordList.begin(),wordList.end());
    q.push({beginWord,1});
    while(q.size()){
      auto word=q.front();
      q.pop();
      if(word.first==endWord) return word.second;
      for(int i=0;i<word.first.size();i++){
        string x = word.first;
        for(int j=0;j<26;j++){
          x[i]= 'a'+j;
          if(s.count(x)){
            s.erase(x);
            q.push({x,word.second+1});
          }
        }
      }
    }
    return 0;
  }
};
int main(){
  return 0;
}