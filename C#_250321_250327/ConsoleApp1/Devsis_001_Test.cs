namespace Dev_Problem_001

{
    /// <summary>
    /// 현재 계정에서 퀘스트만으로 클리어할 수 있는 최대 퀘스트 횟수
    /// 
    /// quest = [ 등장 요구 경험치, 클리어 경험치]
    /// 
    /// sol
    /// 1. quest로 들어온 배열을 입장 경험치 기준 정렬
    /// 2. 현재 exp에서 입장 가능지 확인 후 입장 가능하면 경험치 추가 + 퀘스트 클리어 횟수 증가
    /// </summary>

    using System;
    using System.Collections.Generic;
    using System.Linq;

    public class Solution
    {
        public int solution(int[,] quest)
        {
            int answer = 0;

            int currExp = 0;                // 현재 Exp
            int clearQuestCount = 0;    // 클리어한 퀘스트 개수

            // 1. 퀘스트를 List로 받아 정렬 
            List<Quest> questList = new List<Quest>();
            for(int i = 0; i < quest.GetLength(0); i++)
            {
                Quest nowQuest = new Quest(quest[i, 0], quest[i, 1]);
                questList.Add(nowQuest);
            }

            questList = questList.OrderBy(x => x.needExp).ToList();

            // 2. 퀘스트 하나하나 확인
            foreach (Quest nowQuest in questList)
            {
                // 지금 현재 퀘스트를 열 수 있다면
                if(nowQuest.IsActiveQuest(currExp))
                {
                    currExp += nowQuest.clearExp;
                    clearQuestCount++;
                }
                else
                {
                    break;
                }

            }

            answer = clearQuestCount;
            return answer;
        }
    }

    public class Quest
    {
        public int needExp;
        public int clearExp;

        public Quest(int inputNeedExp, int inputClearExp)
        {
            needExp = inputNeedExp;
            clearExp = inputClearExp;
        }

        public bool IsActiveQuest(int currExp)
        {
            if (currExp < needExp)
                return false;
            else
                return true;
        }
    }
}
