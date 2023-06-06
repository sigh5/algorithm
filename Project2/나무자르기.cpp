#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <math.h>
#include <unordered_set>
using namespace std;

int N, M;

//int Solution(vector<int> Trees, int NeedHeight)
//{
//	int answer = 0;
//	int imax = -1000;
//	unordered_map<int, int> hash_map; // Key , Value 
//
//	for (auto tree : Trees)
//	{
//		hash_map[tree]++;
//		imax = max(tree, imax);
//	}
//	
//	for (int i = imax; i >= 0; --i)
//	{
//		int iSum = 0;
//		for (auto Hash : hash_map)
//		{
//			int Data = Hash.first - i;
//
//			if (Data <= 0)
//				continue;
//			else
//				iSum += Hash.second * Data;
//		}
//
//		if (iSum >= NeedHeight)
//		{
//			answer = i;
//			break;
//		}
//	}
//
//
//
//	return answer;
//}

//long long Solution(vector<int> Trees, int NeedHeight)
//{
//	long long answer = 0;
//	long long max,iMiddle,min = 0;
//	
//
//	sort(Trees.begin(), Trees.end(), Cmp);
//
//
//	int iSize = Trees.size();
//
//	max = Trees[0];
//
//	// NeedHeight �� 1�̻��̾�ߵǴϱ�
//	--max;
//
//	while (max >= min)
//	{
//		iMiddle = (max + min) / 2;
//
//		long long sum = 0;
//		
//		for (int i = 0; i < iSize; ++i)
//		{
//			if (Trees[i] - iMiddle > 0)
//				sum += Trees[i] - iMiddle;
//		}
//
//
//		if (sum < NeedHeight) // ���������� ���� ���� middle ���� ������Ѵ�.max ���� ������ �ڸ��� ��ġ�� ������Ѵ�.
//		{
//			max = iMiddle - 1;
//		}
//		else
//		{
//			if (answer < iMiddle)		// Middle �� ���� ���� �Ƴ��� ������ ���� ����.
//				answer = iMiddle;
//
//			min = iMiddle + 1;		// ���������� ���� ����  Middle ���� �÷� �ڸ��� ���̸� �÷����Ѵ�.
//		}
//	}
//
//
//
//	return answer;
//}

bool Cmp(int a, int b)
{
	return a > b;
}

// ���� ���� -> �ε����� Ư���Ѵ� -> �ؽ� , ��ü�� ���ؾߵȴ� -> Hash
long long Solution(vector<int> Trees, int NeedHeight)
{
	long long answer = 0;
	
	long long max=0, min=0, Middle = 0;
	int size = Trees.size();
	sort(Trees.begin(), Trees.end(), Cmp);

	max = Trees[0];

	--max;

	while (max >= min)
	{
		Middle = (max + min) / 2;
		long long sum = 0;

		for (int i = 0; i < size; ++i)
		{
			if (Trees[i] - Middle > 0)
				sum += Trees[i] - Middle;
		}

		if (sum >= NeedHeight) // ���������� ���̸��� middle ���� �÷� ���� ��ġ���� ����.
		{
			if (answer < Middle) // middle ���� Ŭ���� ������ �Ƴ� ���ִ�.
				answer = Middle;

			min = Middle + 1;
		}
		else   // ���������� ���� ���� Middle ���� ���� ���� ��ġ��������.
		{
			max = Middle - 1;
		}

	}


	return answer;
}




int main()
{
	cin >> N >> M;

	vector<int> Trees;

	int Height = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> Height;
		Trees.push_back(Height);
	}

	cout << Solution(Trees,M);

	return 0;
}
