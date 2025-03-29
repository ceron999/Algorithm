using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Example_001
{
    public class Example001_Graph
    {
        public void Example()
        {
            Dictionary<int, List<int>> graph = new Dictionary<int, List<int>>()
            {
                {1, new List<int>{2, 3}},
                {2, new List<int>{1, 4}},
                {3, new List<int>{1, 5}},
                {4, new List<int>{2}},
                {5, new List<int>{3}}
            };

            Queue<int> queue = new Queue<int>();
            HashSet<int> visited = new HashSet<int>();

            queue.Enqueue(1);
            visited.Add(1);

            Console.Write("1번 친구로부터 연결된 친구들: ");
            while (queue.Count > 0)
            {
                int now = queue.Dequeue();
                Console.Write(now + " ");

                foreach (var next in graph[now])
                {
                    if (!visited.Contains(next))
                    {
                        visited.Add(next);
                        queue.Enqueue(next);
                    }
                }
            }
        }
        
    }
}
