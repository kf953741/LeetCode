namespace LeetCodeAndSwordOffer
{
    public class RectCover
    {
        public int rectCover(int number)
        {
            if (number<=2)
            {
                return number;
            }
            int pre1 = 1;
            int pre2 = 2;
            int result = 0;
            for (int i = 3; i <= number; i++)
            {
                result = pre1 + pre2;
                pre1 = pre2;
                pre2 = result;
            }

            return result;

        }
    }
}