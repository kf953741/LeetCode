using System.Collections.Generic;

namespace LeetCodeAndSwordOffer
{
    public class TwoStack_Queue
    {
        private Stack<int> _stack1 = new Stack<int>();
        private Stack<int> _stack2 = new Stack<int>();
        public void push(int node) 
        {
            while (_stack2.Count>0)
            {
                _stack1.Push(_stack2.Pop());
            }
            _stack1.Push(node);
          
        }
        public int pop()
        {
            while (_stack1.Count>0)
            {
                _stack2.Push(_stack1.Pop());
            }
            
            return _stack2.Pop();
        }
    }
}
