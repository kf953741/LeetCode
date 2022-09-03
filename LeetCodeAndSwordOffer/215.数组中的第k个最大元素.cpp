/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, k, 0, nums.size() - 1);
    }
    int quickSelect(vector<int>& nums, int k, int lo, int hi)
    {
        if (lo > hi)
        {
            return -1;
        }
        int index = partiton(nums, lo, hi);
        if (index > k)
        {
            return quickSelect(nums, k, lo, index - 1);
        }
        else if(index < k)
        {
            return quickSelect(nums, k, index + 1, hi);
        }
        return nums[index];
        
    }
    int partiton(vector<int>& nums, int lo, int hi)
    {
        int pivot = nums[hi];
        int i = lo, j = lo;
        while (j < hi)
        {
            if (nums[j] < pivot)
            {
                swap(nums, i, j);
                i++;
            }
            j++;
        }
        swap(nums, i, hi);
        return i;   
    }
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
// @lc code=end

