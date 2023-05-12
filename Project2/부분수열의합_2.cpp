#include <iostream>
#include <string>
#include<vector>
#include <array>
#include <algorithm>
#include <set>
using namespace std;

#define MAX 21

int  N =0;

std::array<int, MAX> S{ 0 };
vector<int> arr;
set<int> Sum;

void dfs(int iStartIdx, int iSum)
{
	if (iStartIdx >= N)
	{
		return;
	}

	int iTemp = S[iStartIdx] + iSum;	// 계속 더한값과
	Sum.insert({ iTemp });				// ex) 3자리수열-> 2자리수열 구하기

	dfs(iStartIdx +1, iSum);
	dfs(iStartIdx + 1, iTemp);
}


int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	dfs(0, 0);

	int iIndex = 1;
	bool isCout = false;
	for (auto Set : Sum)
	{
		if (iIndex != Set)
		{
			cout << iIndex;
			isCout = true;
			break;
		}
		++iIndex;
	}

	if (!isCout)
		cout << iIndex;

	return 0;
}