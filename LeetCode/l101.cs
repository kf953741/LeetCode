using System;

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

    public class l101
    {
        public bool Solve(TreeNode p, TreeNode q)
        {
            if (p == null && q == null)
            {
                return true;
            }
            if (p != null && q != null && p.val == q.val)
            {
                return Solve(p.left, q.right) && Solve(p.right, q.left);
            }
            return false;
        }

        public bool IsSymmetric(TreeNode root)
        {
            if (root == null)
            {
                return true;
            }
            return Solve(root.left, root.right);
        }

    }
}

