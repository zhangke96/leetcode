// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/minimum-window-substring/

#include <string>
#include <map>
#include <iostream>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
  unordered_map<char, int> complete;
  unordered_map<char, int> comparing;
  for (auto c : t) {
    ++complete[c];
  }
  int i = 0;
  constexpr int INVALID_INDEX = 100000;
  pair<int, int> result{0, INVALID_INDEX};
  for (int j = 0; j < s.size(); ++j) {
    ++comparing[s[j]];
    bool has_string = true;
    while (has_string) {
      // 判断是否完成
      if (comparing.size() >= complete.size()) {
        for (pair<char, int> element : complete) {
          auto index = comparing.find(element.first);
          if (index == comparing.end() || index->second < element.second) {
            has_string = false;
            break;
          }
        }
      } else{
        has_string = false;
      }
      if (has_string) {
        if (j - i < result.second - result.first) {
          result = {i, j};
        }
        // 尝试移动前面窗口
        auto index = comparing.find(s[i]);
        --(index->second);
        if (index->second == 0) {
          comparing.erase(index);
        }
        ++i;
      }
    }
    // if (has_string) {
    //   if (j - i < result.second - result.first) {
    //     result = {i, j};
    //   }
    // }
  }
  if (result.second == INVALID_INDEX) {
    return "";
  } else {
    return s.substr(result.first, result.second - result.first + 1);
  }
}

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";
  cout << minWindow(s, t) << endl;
  string s1 = "a";
  string t1 = "aa";
  cout << minWindow(s1, t1) << endl;
  string s2 = "a";
  string t2 = "a";
  cout << minWindow(s2, t2) << endl;
}