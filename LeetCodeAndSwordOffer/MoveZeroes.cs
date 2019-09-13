namespace LeetCodeAndSwordOffer
{
    public class MoveZeroes283
    {
        public void MoveZeroes(int[] nums) {
            int k =0;
            for(int i =0;i<nums.Length;i++)
            {
                if(nums[i]!=0)
                {
                    Swap(i,k,nums);
                    k++;
                }
            }
        }
    
        private void Swap(int i,int j,int[] nums)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}