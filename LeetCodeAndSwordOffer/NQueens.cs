using System.Collections.Generic;
using System.Text;

namespace LeetCodeAndSwordOffer
{
    public class NQueens
    {
        public IList<IList<string>> SolveNQueens(int n)
        {
            IList<IList<string>> res = new List<IList<string>>();
            HashSet<int> col = new HashSet<int>();
            HashSet<int> frontEnd = new HashSet<int>();
            HashSet<int> endFront = new HashSet<int>();
            Solve(res, n, 0, col, frontEnd, endFront);
            return res;
        }

        public void Solve(IList<IList<string>> res, int n, int row, HashSet<int> col, HashSet<int> frontEnd,
            HashSet<int> endFront)
        {
            if (col.Count == n)
            {
                res.Add(PrintFormat(col));
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (col.Contains(i) || frontEnd.Contains(row + i) || endFront.Contains(row - i))
                {
                    continue;
                }

                col.Add(i);
                frontEnd.Add(row + i);
                endFront.Add(row - i);
                Solve(res, n, row + 1, col, frontEnd, endFront);
                col.Remove(i);
                frontEnd.Remove(row + i);
                endFront.Remove(row - i);
            }
        }

        public IList<string> PrintFormat(HashSet<int> col)
        {
            List<string> s = new List<string>();
            foreach (var i in col)
            {
                StringBuilder stringBuilder = new StringBuilder();
                for (int j = 0; j < col.Count; j++)
                {
                    stringBuilder.Append(".");
                }

                stringBuilder.Replace(".", "Q", i, 1);
                s.Add(stringBuilder.ToString());
            }

            return s;
        }
        
    }
}