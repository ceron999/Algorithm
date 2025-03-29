// source
// https://school.programmers.co.kr/learn/courses/30/lessons/12909

/// <summary>
/// 
/// </summary>

namespace Num9_Problem
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Linq;

    public class Solution
    {
        public bool solution(string s)
        {
            bool answer = true;

            ParenthesesStack ps = new ParenthesesStack(s);
            answer = ps.IsParenthesesCouple();
            Console.WriteLine(answer);
            return answer;
        }
    }

    public class ParenthesesStack
    {
        public string parentheses;
        public Stack<char> stack;

        public ParenthesesStack(string inputS)
        {
            parentheses = inputS;
            stack = new Stack<char>();
        }

        public bool IsParenthesesCouple()
        {
            // () 수가 홀수개 or )로 시작이면 반드시 올바르지 않음
            if (parentheses.Length % 2 != 0 || parentheses[0] == ')') 
                return false;

            foreach(char particle in parentheses)
            {
                if(stack.Count > 0 && stack.Peek() == '(' && particle == ')' )
                {
                    stack.Pop();
                    continue;
                }
                stack.Push(particle);
            }

            if (stack.Count > 0)
                return false;
            else
                return true;
        }
    }
}
