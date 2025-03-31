   using System;
   using System.Collections.Generic;


public class Solution
{
    public string solution(string s)
    {
        string answer = "";

        List<int> numbers = new List<int>();
        numbers = ParseStringToInt(s);

        numbers.Sort();

        answer = ParseIntToString(numbers[0], numbers[numbers.Count - 1]);
        Console.WriteLine(answer);
        return answer;
    }

    private List<int> ParseStringToInt(string s)
    {
        List<int> result = new List<int>();
        string[] temp = s.Split(' ');
        
        for(int i =0; i<temp.Length; i++)
        {
            result.Add(int.Parse(temp[i]));
        }

        return result;
    }

    private string ParseIntToString(int min, int max)
    {
        string result = string.Empty;

        result = $"{min} {max}";

        return result;
    }
}