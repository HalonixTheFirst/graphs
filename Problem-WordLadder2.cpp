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
      if (!ans.empty()) return ans;
      for (auto w : used) s.erase(w);
      used.clear();
      for (int i =0; i<q.size();i++) {
        auto list = q.front();
        q.pop();
        nextWord(list,s,q,used);
      }
    }
    return ans;
  }
};
int main(){
  return 0;
}