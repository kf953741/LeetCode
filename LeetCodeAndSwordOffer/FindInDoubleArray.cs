namespace LeetCodeAndSwordOffer
{
    public class FindInDoubleArray
    {
        public bool Find(int target, int[][] array)
        {
            if (array==null||array.Length==0||array[0].Length==0)
            {
                return false;
            }
            
            int lens = array.Length-1;
            int cols = array[0].Length;
            int curRowIndex = 0;
            int curColIndex = cols - 1;
            while (curColIndex>=0&&curRowIndex<=cols-1)
            {
                if (target==array[curRowIndex][curColIndex])
                {
                    return true;
                }

                if (array[curRowIndex][curColIndex]<target)
                {
                    curRowIndex++;
                }
                else
                {
                    curColIndex--;
                }
            }
            return false;
        }
    }
}