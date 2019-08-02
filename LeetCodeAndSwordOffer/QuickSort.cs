using System.Collections.Generic;

namespace LeetCodeAndSwordOffer
{
    public class QuickSort
    {
        private void Swap(List<int> nums, int i, int j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        private int Partition(List<int> nums,int low,int high)
        {
            int pivot = nums[low + (high - low) / 2];
            while (true)
            {
                while (nums[low]<pivot)
                {
                    low++;
                }

                while (nums[high]>pivot)
                {
                    high--;
                }

                if (low>=high)
                {
                    return high;
                }
                Swap(nums, low++, high--);
            }
        }

        public void quickSort(List<int> nums)
        {
            if (nums==null||nums.Count==0)
            {
                return;
            }
            quickSort(nums,0,nums.Count-1);
        }
        public void quickSort(List<int> nums,int low,int high)
        {
            if (low<high)
            {
                int k = Partition(nums, low, high);
                quickSort(nums,low,k);
                quickSort(nums,k+1,high);
            }
        }
    }
}