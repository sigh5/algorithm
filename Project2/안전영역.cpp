#include <iostream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <array>
#include <memory.h>
using namespace std;

#define MAX 101

array<array<int, MAX>,MAX> arr;
array<array<bool, MAX>, MAX> bVisted = { false, };

array<int, 4> YDir = { -1,1,0,0 };
array<int, 4> XDir = { 0,0,-1,1 };

int N = 0;

void bfs(int iStartY, int iStartX, int iMaxNum)
{
	queue<pair<int, int>> q;
	q.push({ iStartY,iStartX });
	bVisted[iStartY][iStartX] = true;

	while (!q.empty())
	{
		int iCurrentY = q.front().first;
		int iCurrentX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNewY = iCurrentY + YDir[i];
			int iNewX = iCurrentX + XDir[i];

			if (0 <= iNewX && iNewX < N &&
				0 <= iNewY && iNewY <N &&
				!bVisted[iNewY][iNewX] && arr[iNewY][iNewX] > iMaxNum)
			{
				bVisted[iNewY][iNewX] = true;
				q.push({ iNewY,iNewX });
			}
		}
	}


}


int Solve(int iMaxNum)
{
	int iCount = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!bVisted[i][j] && arr[i][j] > iMaxNum)
			{
				bfs(i, j,iMaxNum);
				++iCount;
			}
		}
	}

	memset(&bVisted, false, sizeof(bVisted));
	return iCount;
}

int main()
{
	cin >> N;

	int Num = 0;

	int MaxNum = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Num;
			arr[i][j] = Num;

			MaxNum = max(MaxNum, Num);
		}
	}
	
	int iResult = 0;

	for (int i = MaxNum; i >= 1; --i)
	{
		iResult = max(Solve(i), iResult);

	}

	if (iResult == 0)
		cout << 1 ;
	
	else
		cout << iResult;


	
}



