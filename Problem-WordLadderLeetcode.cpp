#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  unordered_map<string,int> mpp;
  vector<vector<string>> ans;
  string begin;
  void dfs(string word,vector<string> &list) {
    if (word == begin) {
      reverse(list.begin(),list.end());
      ans.push_back(list);
      reverse(list.begin(),list.end());
      return;
    }
    int size = word.size();
    for (int i =0 ;i <size;i++) {
      string newWord= word;
      for (char ch = 'a' ; ch<='z'; ch++) {
        newWord[i]=ch;
        if (mpp.count(newWord) && mpp[newWord] +1 == mpp[word]) {
          list.push_back(newWord);
          dfs(newWord,list);
          list.pop_back();
        }
      }
    }
  }
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    mpp[beginWord] = 0;
    int x = 0;
    begin= beginWord;
    unordered_set<string> list(wordList.begin(),wordList.end());
    queue<string> q;
    q.push(beginWord);
    list.erase(beginWord);
    int sz = beginWord.size();
    while (q.empty()) {
      string word = q.front();
      q.pop();
      if (word == endWord) return ans;
      for (int i =0 ; i < sz;i++) {
        string newWord= word;
        for (char ch = 'a' ; ch<='z'; ch++) {
          newWord[i]=ch;
          if (list.count(newWord)) {
            q.push(newWord);
            list.erase(newWord);
            mpp[newWord]= x;
          }
        }
      }
    }
    if (mpp.count(endWord)) {
      vector<string> seq;
      dfs(endWord,seq);
    }
    return ans;
  }
};
int main(){

}