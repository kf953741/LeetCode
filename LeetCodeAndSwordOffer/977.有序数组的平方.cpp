/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ret(nums.size(), 0);
    int curIndex = nums.size() - 1;
    int left = 0;
    int right = curIndex;
    while (curIndex >= 0) {
      if (nums[left] * nums[left] > nums[right] * nums[right]) {
        ret[curIndex] = nums[left] * nums[left];
        left++;
      } else {
        ret[curIndex] = nums[right] * nums[right];
        right--;
      }
      curIndex--;
    }
    return ret;
  }
};
// @lc code=end
