using System.Collections.Generic;
using System.Runtime.InteropServices.WindowsRuntime;

namespace LeetCodeAndSwordOffer
{
    public class ListNode
    {
        public int val;
        public ListNode next;

        public ListNode(int x)
        {
            val = x;
        }
    }

    public class PrintListFromTailToHead
    {
        public List<int> printListFromTailToHead(ListNode listNode)
        {
            List<int> result = new List<int>();
            if (listNode==null)
            {
                return result;
            }
           
            Stack<int> stack = new Stack<int>();
            while (listNode!=null)
            {
                 stack.Push(listNode.val);
                 listNode = listNode.next;
            }

            while (stack.Count>0)
            {
                result.Add(stack.Pop());
            }
            return result;
        }
    }
}