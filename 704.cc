// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/binary-search/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
  int begin = 0, end = nums.size() - 1;
  while (begin <= end) {
    int middle = (begin + end) / 2;
    int middle_num = nums[middle];
    if (middle_num == target) {
      return middle;
    } else if (middle_num < target) {
      begin = middle + 1;
    } else {
      end = middle - 1;
    }
  }
  return -1;
}

int main () {
  vector<int> nums{-1, 0, 3, 5, 9, 12};
  cout << search(nums, 9) << endl;
  cout << search(nums, 2) << endl;
  vector<int> nums2{5};
  cout << search(nums2, 5) << endl;
  vector<int> nums3{-1, 0, 3, 5, 9, 12};
  cout << search(nums3, 0) << endl;
  return 0;
}