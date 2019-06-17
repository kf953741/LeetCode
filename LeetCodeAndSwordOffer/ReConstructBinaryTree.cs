using System.Collections.Generic;

namespace LeetCodeAndSwordOffer
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

    public class ReConstructBinaryTree
    {
        private Dictionary<int,int> _value2IndexInOrderTree = new Dictionary<int, int>();
        public TreeNode reConstructBinaryTree(int[] pre, int[] tin)
        {
            for (int i = 0; i < tin.Length; i++)
            {
                _value2IndexInOrderTree.Add(tin[i],i);
            }

            return reConstructBinaryTree(pre,0,pre.Length-1,0);
        }

        private TreeNode reConstructBinaryTree(int[] pre,int preL,int preR,int inTreeStart)
        {
            if (preL>preR)
            {
                return null;
            }
            TreeNode root = new TreeNode(pre[preL]);
            int leftTreeSize = _value2IndexInOrderTree[root.val] - inTreeStart;
            root.left = reConstructBinaryTree(pre, preL, leftTreeSize - 1,inTreeStart); 
            root.right =  reConstructBinaryTree(pre, preL+leftTreeSize+1, preR,inTreeStart+leftTreeSize+1);
            return root;
        }
    }
}