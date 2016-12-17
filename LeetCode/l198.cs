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
//            result = new int[nums.Length ];
//            for (int i = 0; i < nums.Length; ++i)
//            {
//                result[i] = -1;
//            }
//            return Solve(nums.Length - 1, nums);
            int n = nums.Length;
            if (n == 0)
            {
                return 0;
            }
            int[] res = new int[nums.Length + 1];
            res[0] = 0;
            res[1] = nums[0];
            for (int i = 2; i <= nums.Length; i++)
            {
                res[i] = Math.Max(res[i - 1], res[i - 2] + nums[i - 1]);
            }
            return res[n];
        }


        public static void Main(string[] args)
        {
            Rob(new int[]{ 1, 2, 3 });
            Console.WriteLine(Rob(new int[]{ 1, 2, 3 }));
        }
    }
}
