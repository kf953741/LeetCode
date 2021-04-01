/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <limits>
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int result = numeric_limits<int>::max();
        int windowStart = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
            while (sum>=s)
            {
                result = min(result,i-windowStart+1);
                sum-=nums[windowStart];
                windowStart++;
            }
    
        }
        return result==numeric_limits<int>::max()?0:result;
    }
};
// @lc code=end
