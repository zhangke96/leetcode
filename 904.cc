// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/fruit-into-baskets/

#include <vector>
#include <iostream>
#include <set>

using namespace std;

int totalFruit(vector<int>& fruits) {
  set<int> buckets;
  int i = 0;
  int length = 0;
  for (int j = 0; j < fruits.size(); ++j) {
    if (buckets.count(fruits[j])) {
      continue;
    } else if (buckets.size() < 2) {
      buckets.insert(fruits[j]);
    } else {
      int result = j - i;
      length = std::max(length, result);
      i = j - 1;
      while (fruits[i - 1] == fruits[i]) {
        --i;
      }
      // 删除移除的水果
      buckets.erase(fruits[i - 1]);
      buckets.insert(fruits[j]);
    }
  }
  int result = fruits.size() - i;
  return std::max(result, length);
}

int main() {
  vector<int> fruits{1, 2, 1};
  cout << totalFruit(fruits) << endl;
  vector<int> fruits1{0, 1, 2, 2};
  cout << totalFruit(fruits1) << endl;
  vector<int> fruits2{1, 2, 3, 2, 2};
  cout << totalFruit(fruits2) << endl;
  vector<int> fruits3{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  cout << totalFruit(fruits3) << endl;
}