#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

    // <장르, {플레이수, 인덱스} vector>
unordered_map<string, vector<vector<int>>> genreMap;
unordered_map<string, int> genreTotalPlayMap;

vector<int> SearchMostPlayedMusic(const string &nowGenre)
{
    vector<int> mostPlayedMusics;

    // 받아온 장르의 <플레이수, 인덱스>를 플레이 수 기준으로 정렬
    vector<vector<int>> nowGenreList = genreMap[nowGenre];
    sort(nowGenreList.begin(), nowGenreList.end(), [](const auto& a, const auto& b)
        {
            return a[0] > b[0];
        });


    if (nowGenreList.size() == 1)
    {
        mostPlayedMusics.push_back(nowGenreList[0][1]);
        return mostPlayedMusics;
    }
    mostPlayedMusics.push_back(nowGenreList[0][1]);
    mostPlayedMusics.push_back(nowGenreList[1][1]);
    return mostPlayedMusics;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    // 1. 장르별 총 플레이 수, 인덱스별 플레이 수를 따로 저장
    for (int i = 0; i < genres.size(); i++)
    {
        genreMap[genres[i]].push_back({ plays[i], i });
        genreTotalPlayMap[genres[i]] += plays[i];
    }

    // 2. 장르 총 플레이 순으로 정렬
    vector<pair<string, int>> genreOrder(genreTotalPlayMap.begin(), genreTotalPlayMap.end());
    sort(genreOrder.begin(), genreOrder.end(), [](const auto& a, const auto& b)
        {
            return a.second > b.second;
        });


    // 3. 장르 순서가 높은 순으로 2개씩 뽑아낸다.
    for (int nowGenreIdx = 0; nowGenreIdx < genreOrder.size(); nowGenreIdx++)
    {
        string nowGenre = genreOrder[nowGenreIdx].first;
        vector<int> currMusics = SearchMostPlayedMusic(nowGenre);
        
        for(int nowNum : currMusics)
            answer.push_back(nowNum);
    }

    return answer;
}