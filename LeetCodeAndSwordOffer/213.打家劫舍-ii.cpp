/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
         if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums,0,n-2),robRange(nums,1,n-1));
    }
    int robRange(vector<int> &nums, int start, int end)
    {
        int n = nums.size();
        vector<int> dp(n,0);
       
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (size_t i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
};
// @lc code=end
