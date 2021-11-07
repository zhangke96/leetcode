// Copyright [2021] zhangke
// https://leetcode-cn.com/problems/minimum-size-subarray-sum/

#include <vector>
#include <iostream>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
  int sum = 0;
  int i = 0, j = 0;
  int length = 0;
  // i指向开始的元素, j指向结束的后一个元素
  while (j < nums.size()) {
    while (sum < target && j < nums.size()) {
      sum += nums[j++];
    }
    if (sum < target) {
      // 没有符合的
      break;
    }
    // 如果只有一个元素就能满足, 返回1
    if (i + 1 == j) {
      return 1;
    }
    // 开始挪到前面窗口
    while (sum - nums[i] >= target) {
      sum -= nums[i];
      ++i;
    }
    int result = j - i;
    // 第一个结果
    if (length == 0) {
      length = result;
    }
    // 之后取结果小的
    length = std::min(result, length);
    // 移动第一个指针, 继续下一轮
    sum -= nums[i++];
    // j = std::max(i, j);
  }
  return length;
}

int main() {
  vector<int> nums{2, 3, 1, 2, 4, 3};
  cout << minSubArrayLen(7, nums) << endl;
  vector<int> nums2{1, 4, 4};
  cout << minSubArrayLen(4, nums2) << endl;
  vector<int> nums3{1, 1, 1, 1, 1, 1};
  cout << minSubArrayLen(7, nums3) << endl;
}
