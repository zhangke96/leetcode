// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/sqrtx/

#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int x) {
  unsigned int begin = 0, end = (1U << 16);
  unsigned int middle = 0;
  while (begin <= end) {
    middle = (begin + end) / 2;
    unsigned int pow = middle * middle;
    if (pow == x) {
      return middle;
    } else if (pow < x) {
      begin = middle + 1;
    } else {
      end = middle - 1;
    }
  }
  return middle * middle > x ? middle -1 : middle;
}

int main() {
  cout << mySqrt(4) << endl;
  cout << mySqrt(8) << endl;
  cout << mySqrt(0) << endl;
  cout << mySqrt(1) << endl;
  cout << mySqrt(1024) << endl;
  cout << mySqrt(1025) << endl;
  cout << mySqrt(2048) << endl;
  cout << mySqrt(4096) << endl;
  cout << mySqrt(4095) << endl;
}