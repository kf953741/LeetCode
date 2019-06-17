namespace LeetCodeAndSwordOffer
{
    public class ReplaceSpace
    {
        public string replaceSpace(string str)
        {
            int spaceNum = 0;
            foreach (var s in str)
            {
                if (s == ' ')
                {
                    spaceNum++;
                }
            }

            int newLength = str.Length + 2 * spaceNum;
            int indexOfNew = newLength - 1;
            int indexOfOrigin = str.Length - 1;
            char[] strChar = str.ToCharArray(0, str.Length);
            char[] newStr = new char[indexOfNew + 1];
            while (indexOfOrigin >= 0)
            {
                if (strChar[indexOfOrigin] == ' ')
                {
                    newStr[indexOfNew--] = '0';
                    newStr[indexOfNew--] = '2';
                    newStr[indexOfNew--] = '%';
                }
                else
                {
                    newStr[indexOfNew] = strChar[indexOfOrigin];
                    indexOfNew--;
                }

                indexOfOrigin--;
            }

            return new string(newStr);
        }
    }
}