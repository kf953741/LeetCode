namespace LeetCodeAndSwordOffer
{
    public class Utils
    {
        public static void Swap(int i,int j,char[] nums)
        {
            char temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}