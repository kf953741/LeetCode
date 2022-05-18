/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        if (sum % k != 0)
            return false;
        vector<bool> used(nums.size(), false);
        int bucket = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        int target = sum / k;
        return dfs(nums, used, target, 0, 0, k);
    }
    bool dfs(vector<int> &nums, vector<bool> &used, int target, int bucket, int numIndex, int k)
    {
        if (k == 0)
            return true;
        if (bucket == target)
            return dfs(nums, used, target, 0, 0, k - 1);
        for (int i = numIndex; i < nums.size(); i++)
        {
            if (used[i])
                continue;
            if (bucket + nums[i] > target)
                continue;
            used[i] = true;
            bucket += nums[i];
            if (dfs(nums, used, target, bucket, i + 1, k))
            {
                return true;
            }

            used[i] = false;
            bucket -= nums[i];
            if (bucket == 0)
                return false;
        }
        return false;
    }
};
// @lc code=end
