// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/search-insert-position/

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int begin = 0, end = nums.size() - 1;
  int middle = 0;
  int middle_num = 0;
  while (begin <= end) {
    middle = (begin + end) / 2;
    middle_num = nums[middle];
    if (middle_num == target) {
      return middle;
    } else if (middle_num < target) {
      begin = middle + 1;
    } else {
      end = middle - 1;
    }
  }
  return middle_num < target ? middle + 1 : middle;
}

int main() {
  vector<int> nums{1, 3, 5, 6};
  cout << searchInsert(nums, 6) << endl;
  cout << searchInsert(nums, 5) << endl;
  cout << searchInsert(nums, 1) << endl;
  cout << searchInsert(nums, 4) << endl;
  cout << searchInsert(nums, 7) << endl;
  cout << searchInsert(nums, 0) << endl;
  cout << searchInsert(nums, 2) << endl;
}