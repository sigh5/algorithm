#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include<unordered_map>
using namespace std;

int main()
{
	int k = 0; 
	
	vector<int> answer;

	unordered_map<int, int> hash_map; // Data, Index
	
	vector<pair<int, int>> Results;

	// 넣었다고 가정을 하고
	int iIndex=0;
	for (auto Data : vec)
	{
		int Min = Data - K;
		int MAx = Data + k;

		for (int i = Min; i <= MAX; ++i)
		{
			if (hash_map[i])
				iCount++;
		}

		Results.push_back({ iIndex,iCount });
	    ++index;
	}

	for (auto Result : Results)
	{
		answer.push_back(Result.second);
	}

	

}


