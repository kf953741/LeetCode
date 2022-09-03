/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        shuffle(nums);
        sort(nums, 0, nums.size() - 1);
        return nums;
    }

    void sort(vector<int> &nums, int lo, int hi)
    {
        if (lo >= hi)
        {
            return;
        }

        int i = partition(nums, lo, hi);
        sort(nums, lo, i - 1);
        sort(nums, i + 1, hi);
    }

    int partition(vector<int> &nums, int lo, int hi)
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

    void shuffle(vector<int> &nums)
    {
        int n = nums.size();
        for (size_t i = 0; i < n; i++)
        {
            int r = rand() % (n - i) + i;
            swap(nums, i, r);
        }
    }
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
// @lc code=end
