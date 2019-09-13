namespace LeetCodeAndSwordOffer
{
    public class SortColors75
    {
        public void SortColors(int[] nums) {
            int zero = -1;
            int two = nums.Length;
            for(int i=0;i<two;)
            {
                if(nums[i]==0)
                {
                    zero++;
                    Swap(zero,i,nums); 
                    i++;
                }
                else if(nums[i]==2)
                {
                    two--;
                    Swap(two,i,nums);
                }
                else
                {
                    i++;
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