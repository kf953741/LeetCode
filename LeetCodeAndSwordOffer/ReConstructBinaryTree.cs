
namespace Code
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
        public TreeNode reConstructBinaryTree(int[] pre, int[] tin)
        {
            return reConstructBinaryTree(pre, 0, pre.Length-1, tin, 0, tin.Length-1);
        }

        private TreeNode reConstructBinaryTree(int[] pre, int lPre, int rPre, int[] tin, int lTin, int rTin)
        {
            if (lTin>rTin||lPre>rPre)
            {
                return null;
            }
            TreeNode root = new TreeNode(pre[lPre]);
            for (int i = lTin; i <= rTin; i++)
            {
                if (tin[i]==root.val)
                {
                    int length = i-lTin ;
                    root.left = reConstructBinaryTree(pre, lPre+1, lPre+length, tin, lTin, i-1);
                    root.right = reConstructBinaryTree(pre, lPre+length+1, rPre, tin, i+1, rTin);
                    break;
                }                        
            }

            return root;

        }
    }
}