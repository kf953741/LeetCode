using System;
using System.Collections.Generic;

namespace LeetCodeAndSwordOffer
{
    public class MaxSubArray53
    {
        public int MaxSubArray(int[] nums)
        {
            int max = nums[0];
            for (int i = 1; i<nums.Length; ++i)
            {
                nums[i] = Math.Max(nums[i - 1], 0) + nums[i];
                max = Math.Max(max,nums[i]);
            }
            return max;
        }
    }
}