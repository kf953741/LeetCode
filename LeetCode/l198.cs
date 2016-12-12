using System;

namespace LeetCode
{
    class l198
    {
        public static int[] result;

        public static int Solve(int idx, int[] nums)
        {
            if (idx < 0)
            {
                return 0;
            }
            if (result[idx] >= 0)
            {
                return result[idx];
            }
            result[idx] = Math.Max(nums[idx] + Solve(idx - 2, nums), Solve(idx - 1, nums));
            return result[idx];
        }

        public static int Rob(int[] nums)
        {
            result = new int[nums.Length ];
            for (int i = 0; i < nums.Length; ++i)
            {
                result[i] = -1;
            }
            return Solve(nums.Length - 1, nums);
        }

        public static void Main(string[] args)
        {
            Rob(new int[]{ 1, 2, 3 });
            Console.WriteLine(Rob(new int[]{ 1, 2, 3 }));
        }
    }
}
