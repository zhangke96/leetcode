// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/squares-of-a-sorted-array/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
  int index = 0;
  vector<int> result;
  result.reserve(nums.size());
  for (int i = 0; i < nums.size(); ++i) {
    if (abs(nums[i]) < abs(nums[index])) {
      index = i;
    }
  }
  // 找到绝对值最小的点, 然后向两边找
  result.push_back(nums[index] * nums[index]);
  int right = index - 1;
  int left = index + 1;
  while (right >= 0 && left < nums.size()) {
    if (abs(nums[right]) >= abs(nums[left])) {
      result.push_back(nums[left] * nums[left]);
      ++left;
    } else {
      result.push_back(nums[right] * nums[right]);
      --right;
    }
  }
  while (right >= 0) {
    result.push_back(nums[right] * nums[right]);
    --right;
  }
  while (left < nums.size()) {
    result.push_back(nums[left] * nums[left]);
    ++left;
  }
  return result;
}

void printNums(const vector<int>& nums, int length) {
  for (int i = 0; i < length; ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums{-4, -1 ,0, 3, 10};
  printNums(sortedSquares(nums), nums.size());
  vector<int> nums2{-7, -3, 2, 3, 11};
  printNums(sortedSquares(nums2), nums2.size());
}

