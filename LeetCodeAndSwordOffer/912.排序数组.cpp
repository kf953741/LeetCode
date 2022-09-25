/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    shullfe(nums);
    sort(nums, 0, nums.size() - 1);
    return nums;
  }
  void sort(vector<int>& nums, int lo, int hi) {
    if (lo >= hi) {
      return;
    }
    int p = partition(nums, lo, hi);
    sort(nums, lo, p - 1);
    sort(nums, p + 1, hi);
  }
  int partition(vector<int>& nums, int lo, int hi) {
    int pivot = nums[hi];
    int cur = lo;
    while (lo < hi) {
      if (nums[lo] < pivot) {
        swap(nums, cur, lo);
        cur++;
      }
      lo++;
    }
    swap(nums, cur, hi);
    return cur;
  }
  void shullfe(vector<int>& nums) {
    int size = nums.size();
    for (size_t i = 0; i < size; i++) {
      int t = rand() % (size - i) + i;
      swap(nums, i, t);
    }
  }
  void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};
// @lc code=end
