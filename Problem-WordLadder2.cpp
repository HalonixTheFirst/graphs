// Keep a queue of lists;
// add the first word to a list and then to the queue. Get the list from the queue and then transform the last word to all the possible configurations
// then delete each tranformed word from the vector.
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
  string nextWord(vector<string> &list,unordered_set<string> &s,queue<vector<string>> &q) {
    string word = list.back();
    string change;
    for (int i=0 ;i<word.size();i++){
      string x = word;
      for (char ch = 'a' ; ch<='z' ; ch++) {
        x[i] = ch;
        if (s.count(x)) {
          auto new_list = list;
          new_list.push_back(x);
          q.push(new_list);
          change = x;
        }
      }
    }
    return change;
  }
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<vector<string>> q;
    q.push({beginWord});
    vector<vector<string>> ans;
    unordered_set<string> s(wordList.begin(),wordList.end());
    while (q.size()) {
      auto list = q.front();
      q.pop();
      string word = nextWord(list,s,q);
      s.erase(word);
      if (list.back()==endWord) ans.push_back(list);
    }
    return ans;
  }
};
int main(){
  return 0;
}