namespace LeetCodeAndSwordOffer
{
    public class IsPalindrome125
    {
        public bool IsPalindrome(string s)
        {
            if (string.IsNullOrEmpty(s))
            {
                return true;
            }
            s = s.ToLower();
            int i = 0;
            int j = s.Length-1;
            while (i<j)
            {
                if (!Isre(s[i]))
                {
                    i++;
                }
                else if(!Isre(s[j]))
                {
                    j--;
                }
                else if(s[i]!=s[j])
                {
                    return false; 
                }
                else
                {
                    i++;
                    j--;
                }

            }

            return true;
        }
        
        public bool Isre(char c)
        {
            if(c >= 'a' && c <= 'z') 
                return true;
            if(c >= '0' && c <= '9') 
                return true;
            return false;
        }
    }
}