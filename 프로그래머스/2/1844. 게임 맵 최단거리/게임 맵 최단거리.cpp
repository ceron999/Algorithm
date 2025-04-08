#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Point
{
    int y, x, cnt;
};

vector<int> dy = { -1,0,1,0 };
vector<int> dx = { 0,1,0,-1 };
int n, m;

bool isWithinRange(int y, int x)
{
    return (y >= 0) && (y < n) && (x >= 0) && (x < m);
}

int bfs(vector<vector<int>>& maps)
{
    bool isVisited[101][101] = { false };
    queue<Point> q;

    q.push({ 0,0,0 });
    isVisited[0][0] = true;

    while (!q.empty())
    {
        Point curr = q.front();
        q.pop();

        if (curr.y == n - 1 && curr.x == m - 1)
            return curr.cnt + 1;

        for (int i = 0; i < 4; i++)
        {
            int ny = curr.y + dy[i];
            int nx = curr.x + dx[i];

            if (isWithinRange(ny, nx) && !isVisited[ny][nx] && maps[ny][nx] != 0)
            {
                q.push({ ny,nx,curr.cnt+1 });
                isVisited[ny][nx] = true;
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size(); 
    m = maps[0].size();
    
    answer = bfs(maps);
    return answer;
}