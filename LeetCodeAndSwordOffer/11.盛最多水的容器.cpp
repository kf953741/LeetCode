/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
        {
            return 0;
        }

        int left = 0;
        int right = n - 1;
        int maxArea = 0;
        while (left < right)
        {
            int curArea = min(height[left],height[right])*(right-left);
            maxArea = max(curArea, maxArea);
            if (height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return maxArea;
    }
};
// @lc code=end
