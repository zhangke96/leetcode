// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/backspace-string-compare/

#include <iostream>
#include <string>

using namespace std;

bool backspaceCompre(string s, string t) {
  int index1 = s.size() - 1;
  int index2 = t.size() - 1;
  while (index1 >= 0 || index2 >= 0) {
    // 分别找到比较的位置
    int jump = 0;
    while (index1 >= 0) {
      if (s[index1] == '#') {
        ++jump;
        --index1;
      } else {
        if (jump) {
          --jump;
          --index1;
        } else {
          break;
        }
      }
    }
    jump = 0;
    while (index2 >= 0) {
      if (t[index2] == '#') {
        ++jump;
        --index2;
      } else {
        if (jump) {
          --jump;
          --index2;
        } else {
          break;
        }
      }
    }
    // 两个字符串分别找到可以比较的字符或者没有可比较的字符
    // if ()
    if (index1 >= 0 && index2 < 0 || index2 >= 0 && index1 < 0) {
      return false;
    }
    if (index1 < 0 && index2 < 0) {
      return true;
    }
    if (s[index1] != t[index2]) {
      return false;
    } else {
      --index1;
      --index2;
    }
  }
  if (index1 >= 0 || index2 >= 0) {
    return false;
  }
  return true;
}

int main() {
  string s("ab##");
  string t("c#d#");
  cout << backspaceCompre(s, t) << endl;
  string s1("ab#c");
  string t1("ad#c");
  cout << backspaceCompre(s1, t1) << endl;
  string s2("bxj##tw");
  string t2("bxj###tw");
  cout << backspaceCompre(s2, t2) << endl;
  string s3("bbbextm");
  string t3("bbb#extm");
  cout << backspaceCompre(s3, t3) << endl;
  string s4("nzp#o#g");
  string t4("b#nzp#o#g");
  cout << backspaceCompre(s4, t4) << endl;
}