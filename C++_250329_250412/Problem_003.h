#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
/// 
/// 배열 정렬하기3
/// 
/// 정수 배열 numbers가 주어질 떄 서로 다른 idx 2개를 뽑아 더한 모든 케이스를 배열에 담아 return
/// 
/// 길이 : 2~100
/// 원소 : -100000 ~ 100000
/// </summary>

namespace Problem_003
{
	vector<int> solution(vector<int> numbers);
	vector<int> solution2(vector<int> numbers);
}