#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
/// 
/// 모의고사
/// 
/// A,B,C는 서로 다른 방식으로 찍음
/// 문제의 정답 Answers가 들어올 때 A,B,C의 정답률이 높은 순서대로 answer로 반환(0은 제외)
/// A = 1,2,3,4,5
/// B = 2,1,2,3,2,4,2,5,
/// C = 3,3,1,1,2,2,4,4,5,5
/// 
/// sol
/// 1. 문제의 정답을 하나씩 가져와 a,b,c,가 쓴 정답과 비교
/// 2. 정답이 맞으면 각 카운트 + 1
/// 3. 정답순으로 a,b,c 나열
/// </summary>

namespace Problem_004
{
    vector<int> solution(vector<int> answers);
}