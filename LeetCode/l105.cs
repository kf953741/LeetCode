using System;
using System.Collections.Generic;
using System.Collections;

namespace LeetCode
{
    public class l105
    {
        public TreeNode BuildTree(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd, Dictionary<int,int> inDic)
        {
            if (preorder == null || inorder == null || preStart > preEnd || inStart > inEnd)
            {
                return null;
            }
            TreeNode root = new TreeNode(preorder[preStart]);
            int inRoot = inDic[root.val];
            int leftTreeNum = inRoot - inStart;
            root.left = BuildTree(preorder, preStart + 1, preStart + leftTreeNum, inorder, inStart, inRoot - 1, inDic);
            root.right = BuildTree(preorder, preStart + leftTreeNum + 1, preEnd, inorder, inRoot + 1, inEnd, inDic);
            return root;

        }

        public TreeNode BuildTree(int[] preorder, int[] inorder)
        {
            Dictionary<int,int> inDic = new Dictionary<int, int>();
            for (int i = 0; i < inorder.Length; i++)
            {
                inDic.Add(inorder[i], i);
            }
            return BuildTree(preorder, 0, preorder.Length - 1, inorder, 0, inorder.Length - 1, inDic);
        }
    }
}

