#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int reverseDegree(string s) {
    int sum = 0;
    unordered_map<char,int> mpp;
    int z = 26;
    for(char i ='a' ;i<='z';i++){
      mpp[i] = z;
      z--;
    }
    for(int i =0 ;i<s.size();i++){
      int pos = i+1;
      int revInd = mpp[s[i]];
      int ans = pos*revInd;
      sum+=ans;
    }
    return sum;
  }

};
int main(){
  Solution s;
  s.reverseDegree("abc");
}