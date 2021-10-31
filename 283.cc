// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/move-zeroes/

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
  int remove = 0;
  for (int i = 0; i < nums.size() - remove;) {
    if (nums[i] == 0) {
      ++remove;
      // 将后面的元素全部向前移
      for (int j = i; j < nums.size() - remove; ++j) {
        nums[j] = nums[j + 1];
      }
      nums[nums.size() - remove] = 0;
    } else {
      ++i;
    }
  }
}

void printNums(const vector<int>& nums, int length) {
  for (int i = 0; i < length; ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums{0, 1, 0, 3, 12};
  moveZeroes(nums);
  printNums(nums, nums.size());
}