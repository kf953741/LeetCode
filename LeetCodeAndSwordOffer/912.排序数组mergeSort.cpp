/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }
  void mergeSort(vector<int>& nums, int l, int r) {
    if (l >= r) {
      return;
    }
    int mid = l + (r - l) / 2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    merge(nums, l, mid, r);
  }
  void merge(vector<int>& nums, int l, int mid, int r) {
    vector<int> temp;
    int index1 = l;
    int index2 = mid + 1;
    while (index1 <= mid && index2 <= r) {
      if (nums[index1] <= nums[index2]) {
        temp.push_back(nums[index1++]);
      } else {
        temp.push_back(nums[index2++]);
      }
    }
    while (index1 <= mid) {
      temp.push_back(nums[index1++]);
    }
    while (index2 <= r) {
      temp.push_back(nums[index2++]);
    }
    for (int i = 0; i < temp.size(); i++) {
      nums[i + l] = temp[i];
    }
  }
};
// @lc code=end
