using System;
using System.Linq;

using Dev_Problem_003;

class Program
{
    static void Main()
    {
        Solution solution = new Solution();
        double[,] test = { { 5.0, 5.0 }, { 3.0, 3.0 }, { 2.0, 1.0 } };
        solution.solution(test, [1.0, 1.0]);
    }
}