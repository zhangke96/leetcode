// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  // 顺序查找
  int begin = -1, end = -1;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (nums[i] > target) {
      break;
    } else if (nums[i] == target) {
      if (begin == -1) {
        begin = i;
      }
      end = i;
    }
  }
  return {begin, end};
}

/*
执行用时： 8 ms , 在所有 C++ 提交中击败了 67.98% 的用户
内存消耗： 13.3 MB , 在所有 C++ 提交中击败了 50.01% 的用户
*/

vector<int> searchRange2(vector<int>& nums, int target) {
  // 二分查找
  int begin = 0, end = nums.size() - 1;
  while (begin <= end) {
    int middle = (begin + end) / 2;
    int middle_num = nums[middle];
    if (middle_num == target) {
      int begin_index = middle;
      int end_index = middle;
      while (begin_index >= 1 && nums[begin_index - 1] == target) {
        --begin_index;
      }
      while (end_index + 1 < nums.size() && nums[end_index + 1] == target) {
        ++end_index;
      }
      return {begin_index, end_index};
    } else if (middle_num < target) {
      begin = middle + 1;
    } else {
      end = middle - 1;
    }
  }
  return {-1,-1};
}

/*
执行用时：4 ms, 在所有 C++ 提交中击败了95.77%的用户
内存消耗：13.3 MB, 在所有 C++ 提交中击败了48.04%的用户
*/

void printResult(const vector<int>& result) {
  cout << "[ " << result.at(0) << ", " << result.at(1) << " ]" << endl;
}

int main() {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  printResult(searchRange2(nums, 8));
  printResult(searchRange2(nums, 6));
  printResult(searchRange2(nums, 0));
}