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
//	// NeedHeight 는 1이상이어야되니까
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
//		if (sum < NeedHeight) // 가져갈려는 양이 적다 middle 값을 낮춰야한다.max 값을 낮게해 자르는 위치를 낮춰야한다.
//		{
//			max = iMiddle - 1;
//		}
//		else
//		{
//			if (answer < iMiddle)		// Middle 이 높을 수록 아끼는 나무의 양이 많다.
//				answer = iMiddle;
//
//			min = iMiddle + 1;		// 가져갈려는 양이 많다  Middle 값을 올려 자르는 높이를 올려야한다.
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

// 존나 많다 -> 인덱스를 특정한다 -> 해쉬 , 전체를 구해야된다 -> Hash
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

		if (sum >= NeedHeight) // 가져갈려는 양이많다 middle 값을 올려 높은 위치에서 벤다.
		{
			if (answer < Middle) // middle 값이 클수록 나무를 아낄 수있다.
				answer = Middle;

			min = Middle + 1;
		}
		else   // 가져갈려는 양이 적다 Middle 값을 내려 낮은 위치에서벤다.
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
