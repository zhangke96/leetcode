// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/remove-element/

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
  int remove = 0;
  for (int i = 0; i < nums.size() - remove;) {
    if (nums[i] == val) {
      ++remove;
      for (int j = i; j < nums.size() - remove; ++j) {
        nums[j] = nums[j + 1];
      }
    } else {
      ++i;
    }
  }
  return nums.size() - remove;
}

void printNums(const vector<int>& nums, int length) {
  for (int i = 0; i < length; ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums{3, 2, 2, 3};
  printNums(nums, removeElement(nums, 3));
  printNums(nums, removeElement(nums, 2));
}