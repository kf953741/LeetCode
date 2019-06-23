namespace LeetCodeAndSwordOffer
{
    public class Fibonacci
    {
        public int fibonacci(int n)
        {
            int result = 0;
            int pre1 = 1;
            int pre2 = 0;
            for (int i = 1; i <= n; i++)
            {
                result = pre1 + pre2;
                pre1 = pre2;
                pre2 = result;
            }

            return result;
        }
    }
}