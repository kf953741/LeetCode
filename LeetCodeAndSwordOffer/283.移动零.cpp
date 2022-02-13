/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), fast =0, slow = 0;
        while (fast < n)
        {
            if (nums[fast])
            {
                swap(nums[fast],nums[slow]);
                slow++;
            }
            fast++;
        }
    }
};
// @lc code=end

