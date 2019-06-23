using System.Text.RegularExpressions;

namespace LeetCodeAndSwordOffer
{
    public class MinNumberInRotateArray
    {
        public int minNumberInRotateArray(int[] rotateArray)
        {
            if (rotateArray.Length == 0)
            {
                return -1;
            }

            int startIndex = 0;
            int endIndex = rotateArray.Length - 1;
            int midIndex = 0;
            while (startIndex < endIndex)
            {
                midIndex = startIndex + (endIndex - startIndex) / 2;
                if (rotateArray[startIndex]==rotateArray[midIndex]&&rotateArray[midIndex]==rotateArray[endIndex])
                {
                    return FindMinNum(rotateArray, startIndex, endIndex);
                }
                if (rotateArray[midIndex]>rotateArray[endIndex])
                {
                    startIndex = midIndex+1;
                }
                else
                {
                    endIndex = midIndex;
                }

              
            }

            return rotateArray[startIndex];
        }

        private int FindMinNum(int[] nums,int startIndx,int endIndex)
        {
            int result = nums[startIndx];
            for (int i = startIndx; i <=endIndex; i++)
            {
                if (result>nums[i])
                {
                    result = nums[i];
                }
            }

            return result;
        }
    }
}