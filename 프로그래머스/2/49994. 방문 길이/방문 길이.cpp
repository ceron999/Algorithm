
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct PairHash 
{
    size_t operator()(const pair<int, int>& p) const noexcept 
    {
        // 간단한 해시 결합
        return (hash<int>{}(p.first) * 31u) ^ hash<int>{}(p.second);
    }
};

unordered_map<pair<int,int>, vector<char>, PairHash> visited;
pair<int, int> nowPos;

bool IsVisited(char dir)
{
    auto it = visited.find(nowPos);
    if (it == visited.end()) 
        return false;

    const auto& searchVec = it->second;
    return find(searchVec.begin(), searchVec.end(), dir) != searchVec.end();
}

int solution(string dirs) {
    int answer = 0;

    for (char dir : dirs)
    {
        switch (dir)
        {
        case 'U':
            if (nowPos.second == 5)
                continue;
            
            if (!IsVisited(dir))
            {
                visited[nowPos].push_back('U');
                nowPos.second++;
                visited[nowPos].push_back('D');
                answer++;
            }
            else
            {
                nowPos.second++;
            }
            break;
        case 'D':
            if (nowPos.second == -5)
                continue;

            if (!IsVisited(dir))
            {
                visited[nowPos].push_back('D');
                nowPos.second--;
                visited[nowPos].push_back('U');
                answer++;
            }
            else
            {
                nowPos.second--;
            }
            break;
        case 'L':
            if (nowPos.first == -5)
                continue;

            if (!IsVisited(dir))
            {
                visited[nowPos].push_back('L');
                nowPos.first--;
                visited[nowPos].push_back('R');
                answer++;
            }
            else
            {
                nowPos.first--;
            }
            break;
        case 'R':
            if (nowPos.first == 5)
                continue;

            if (!IsVisited(dir))
            {
                visited[nowPos].push_back('R');
                nowPos.first++;
                visited[nowPos].push_back('L');
                answer++;
            }
            else
            {
                nowPos.first++;
            }
            break;
        }
    }

    return answer;
}