using System;
using System.Collections.Generic;
using System.Collections;

namespace LeetCode
{
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;

        public TreeNode(int x)
        {
            val = x;
        }
    }

    public class l144
    {
        public IList<int> PreorderTraversal(TreeNode root)
        {
            List<int> result = new List<int>();
            Stack<TreeNode> stack = new Stack<TreeNode>();
            if (root == null)
            {
                return result;
            }
            stack.Push(root);
            while (stack.Count > 0)
            {
                TreeNode cur = stack.Pop();
                result.Add(cur.val);
                if (cur.right != null)
                {
                    stack.Push(cur.right);
                }
                if (cur.left != null)
                {
                    stack.Push(cur.left);
                }
            }
            return result;
        }
       
    }
}

