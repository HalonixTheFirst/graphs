#include<iostream>
using namespace std;
int main(){
  const int* ptr = new int;
  ptr =0;
  delete ptr;
  *ptr = 1;
}