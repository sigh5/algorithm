#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <array>
#include <memory.h>

using namespace std;

#define MAX 101

vector<int> vec[MAX];
array<bool, MAX> bVisted = { false, };

int N = 0;

int iCount = 0;

void dfs(int iStart, int vecNum)
{
	if (bVisted[iStart])
		return;

	bVisted[iStart] = true;

	size_t size = vec[iStart].size();

	for (size_t i = 0; i < size; ++i)
	{
		int iNum = vec[iStart][i];
		dfs(iNum, vecNum);
	}
}

int main()
{
	cin >> N;

	int iNum = 0;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> iNum;
			if (iNum != 0)
			{
				vec[i].push_back(j);
			}

		}
	}

	for (int i = 1; i <= N; ++i)
	{
		dfs(i, i);

		for (int j = 1; j <= N; ++j)
		{
			cout << bVisted[j] << " ";
		}
		cout << '\n';
		memset(&bVisted, false, sizeof bVisted);
	}



}