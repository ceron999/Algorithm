#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// <summary>
/// https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
/// 
/// ���ǰ��
/// 
/// A,B,C�� ���� �ٸ� ������� ����
/// ������ ���� Answers�� ���� �� A,B,C�� ������� ���� ������� answer�� ��ȯ(0�� ����)
/// A = 1,2,3,4,5
/// B = 2,1,2,3,2,4,2,5,
/// C = 3,3,1,1,2,2,4,4,5,5
/// 
/// sol
/// 1. ������ ������ �ϳ��� ������ a,b,c,�� �� ����� ��
/// 2. ������ ������ �� ī��Ʈ + 1
/// 3. ��������� a,b,c ����
/// </summary>

namespace Problem_004
{
    vector<int> solution(vector<int> answers);
}