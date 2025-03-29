// source
// https://school.programmers.co.kr/learn/courses/30/lessons/42883

/// <summary>
/// 어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자
/// number : 초기 숫자
/// k : 제거할 숫자 개수
/// return : 만들 수 있는 가장 큰 수의 문자열
/// 
/// sol
/// 1. 문자열을 int 변환
/// 2. sort 후 가장 작은 수 2개 제거
/// 3. 이후 숫자로 
/// </summary>

namespace Num8_Problem
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Linq;
    using System.Text;
    using static System.Runtime.InteropServices.JavaScript.JSType;
    using System.Threading.Tasks;

    public class Solution
    {
        public string solution(string number, int k)
        {
            string answer = "";

            BigNumMaker bigNumMaker = new BigNumMaker(number, k);
            answer = bigNumMaker.MakeBiggestNum();
            Console.WriteLine(answer);
            return answer;
        }
    }

    public class BigNumMaker
    {
        string numString;
        int deleteCount;
        Stack<char> nums;

        public BigNumMaker(string input, int inputK)
        {
            numString = input;
            deleteCount = inputK;
            nums = new Stack<char> ();
        }

        public string MakeBiggestNum()
        {
            foreach (char c in numString)
            {
                // 현재 숫자가 스택 top보다 크면 pop
                while (nums.Count > 0 && nums.Peek() < c && deleteCount > 0)
                {
                    nums.Pop();
                    deleteCount--;
                }
                nums.Push(c);
            }

            // k가 아직 남아있으면 뒤에서 제거
            while(deleteCount > 0)
            {
                nums.Pop();
                deleteCount--;
            }

            // 스택을 문자열로 복원 (역순으로 담겨 있음)
            var result = new string(nums.ToArray());
            // 뒤집어서 return
            char[] arr = result.ToCharArray();
            Array.Reverse(arr);

            return new string(arr);
        }
    }

}
