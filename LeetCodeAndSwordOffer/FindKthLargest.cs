using System;

namespace LeetCodeAndSwordOffer
{
    public class FindKthLargest215
    {
        public int FindKthLargest(int[] nums, int k)
        {
            if (k>nums.Length)
            {
                return -1;
            }
            Array.Sort(nums);
            return nums[nums.Length-k];
        }
    }
}