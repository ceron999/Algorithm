using System;
using System.Collections.Generic;
using System.Text;



/// <summary>
/// player  : 0~23시의 시간별 이용자
/// m       : 서버 1대당 버티는 이용자 수
/// k       : 서버 1대가 운영 가능한 시간
/// 
/// 확인할 부분
/// 1. 매 시간 이용자 수, 사용 가능한 서버 수를 확인
/// 2. 현재 증설할지 말지에 대한 상황 확인
/// 
/// </summary>

public class Solution
{
    public int solution(int[] players, int m, int k)
    {
        int answer = 0;

        Server server = new Server(players, m, k);
        server.UpdateServer();
        server.DebugExpandedServer();

        answer = server.serverCall;

        return answer;
    }
}

public class Server
{
    public int[] players;
    public int availableNum;
    public int availableTime;

    public int[] expandedServer;
    public int serverCall;      // 서버를 부른 횟수

    public Server(int[] getPlayers, int m, int k)
    {
        players = getPlayers;
        availableNum = m;
        availableTime = k;

        expandedServer = new int[players.Length];
        foreach (int server in expandedServer)
        {
            expandedServer[server] = 0;
        }
        serverCall = 0;
    }

    // 핵심 함수
    public void UpdateServer()
    {
        for (int time = 0; time < players.Length; time++)
        {
            // 1. 기존 서버로만 운영이 가능하다면 패스
            if (players[time] < availableNum)
                continue;

            // 2. 운영이 불가능하다면 사용 가능한 서버가 있는지 확인
            if(IsExpandServer(time))
            {
                // 3. 서버가 더 필요없다면 패스
                continue;
            }
            else
            {
                // 4. 서버가 더 필요하다면 필요 개수만큼 증설
                UpdateExpandedServer(time);
            }

        }
    }

    // 서버를 증설한다
    private void UpdateExpandedServer(int time)
    {
        int needServerNum = (players[time] + availableNum) / availableNum;
        needServerNum -= (expandedServer[time] + 1);

        for (int i = time; i < time + availableTime && i < players.Length; i++)
        {
            expandedServer[i] += needServerNum;
        }

        serverCall += needServerNum;
    }

    // 현재 사용 가능한 서버가 존재하여 더 서버를 늘릴 필요가 없으면 true
    private bool IsExpandServer(int time)
    {
        // 현재 이용 가능한 인원 수를 체크
        int count = availableNum * (expandedServer[time] + 1);

        if (count > players[time])
            return true;
        else
            return false;
    }

    public void DebugExpandedServer()
    {
        StringBuilder sb = new StringBuilder();

        sb.Append("[");
        foreach(int i in expandedServer)
        {
            sb.Append(i + " ,");
        }
        sb.Append("]");

        Console.WriteLine(sb.ToString());
    }
}