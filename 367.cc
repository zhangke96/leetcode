// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/valid-perfect-square/

#include <iostream>

using namespace std;

bool isPerfectSquare(int num) {
  unsigned int begin = 0, end = 1U << 16;
  while (begin <= end) {
    unsigned int middle = (begin + end) / 2;
    unsigned int pow = middle * middle;
    if (pow == num) {
      return true;
    } else if (pow < num) {
      begin = middle + 1;
    } else {
      end = middle - 1;
    }
  }
  return false;
}

int main() {
  cout << isPerfectSquare(16) << endl;
  cout << isPerfectSquare(14) << endl;
  cout << isPerfectSquare(1) << endl;
  cout << isPerfectSquare(1024) << endl;
  cout << isPerfectSquare(2048) << endl;
}