using System.Collections.Generic;
using Code;

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

    public class AllElementsInTwoBinarySearchTrees
    {
        public IList<int> GetAllElements(TreeNode root1, TreeNode root2)
        {
            List<int> res1 = new List<int>();
            List<int> res2 = new List<int>();
            Dfs(root1,res1);
            Dfs(root2,res2);
            return Merge(res1,res2);
        }

        public void Dfs(TreeNode root,List<int> res)
        {
            if (root==null)
            {
                return;
            }
            Dfs(root.left,res);
            res.Add(root.val);
            Dfs(root.right,res);
        }

        public List<int> Merge(List<int> res1, List<int> res2)
        {
           List<int> res = new List<int>();
           int i = 0;
           int j = 0;
           int l1 = res1.Count;
           int l2 = res2.Count;
           while (i<l1&&j<l2)
           {
               if (res1[i]<=res2[j])
               {
                   res.Add(res1[i++]);
               }
               else
               {
                   res.Add(res2[j++]);
               }
           }

           while (i<l1)
           {
               res.Add(res1[i++]);
           }

           while (j<l2)
           {
               res.Add(res2[j++]);
           }

           return res;
        }
    }
}