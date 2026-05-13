// Keep a queue of lists;
// add the first word to a list and then to the queue. Get the list from the queue and then transform the last word to all the possible configurations
// then delete each tranformed word from the vector.
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<vector<string>> q;
    q.push({beginWord});
    vector<vector<string>> ans;
    vector<string> used;
    unordered_set<string> s(wordList.begin(),wordList.end());
    while (q.size()) {
      int size = q.size();
      if (!ans.empty()) return ans;
      for (auto w : used) s.erase(w);
      used.clear();
      for (int j =0; j<size;j++) {
        auto list = q.front();
        q.pop();
        string word = list.back();
        for (int i=0 ;i<word.size();i++){
          string x = word;
          for (char ch = 'a' ; ch<='z' ; ch++) {
            x[i] = ch;
            if (s.count(x)) {
              auto new_list = list;
              new_list.push_back(x);
              q.push(new_list);
              used.push_back(x);
              if (x==endWord) ans.push_back(new_list);
            }
          }
        }
      }
    }
    return ans;
  }
};
int main(){
  return 0;
}