using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example_002
{
    public class Example002_Combine
    {
        List<string> results = new List<string>();


        public void Example()
        {
            string str = "abcde";
            char[] chars = str.ToCharArray();

            Combination(chars, 0, "");

            Console.WriteLine("모든 조합:");
            foreach (var combination in results)
            {
                Console.WriteLine(combination);
            }
        }

        void Combination(char[] arr, int start, string current)
        {
            // 비어있는거 아니면 추가
            if (!string.IsNullOrEmpty(current))
            {
                results.Add(current);
            }

            // (0,"") -> (1,"a") -> (2,"ab") ... -> (5, abcde) 순서
            for (int i = start; i < arr.Length; i++)
            {
                Combination(arr, i + 1, current + arr[i]);
            }
        }

    }
}
