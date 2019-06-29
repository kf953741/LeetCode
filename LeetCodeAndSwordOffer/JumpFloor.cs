namespace LeetCodeAndSwordOffer
{
    public class JumpFloor
    {
        public int jumpFloor(int number)
        {
            if (number<=0)
            {
                return 0;
            }
            if (number==1)
            {
                return 1;
            }
            if (number==2)
            {
                return 2;
            }
            return jumpFloor(number - 1) + jumpFloor(number - 2);
        }
        
        
    }
}