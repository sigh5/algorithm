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

array<array<char, MAX>,MAX > arr;

array<int, 4> XDir = { 0,0,-1,1 };
array<int, 4> YDir = { -1,1,0,0 };

array<array<bool, MAX>,MAX> bVisted = { false, };

int N = 0;

void bfs(int iStartY, int iStartX )
{
	queue<pair<int, int>> q;
	q.push({ iStartY,iStartX });
	bVisted[iStartY][iStartX] = true;

	char cValue = arr[iStartY][iStartX];
	
	while (!q.empty())
	{
		int iCurrentY = q.front().first;
		int iCurrentX = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNewY = iCurrentY + YDir[i];
			int iNewX = iCurrentX + XDir[i];

			
			if (0 <= iNewY && iNewY < N &&
				0 <= iNewX && iNewX < N &&
				!bVisted[iNewY][iNewX] && arr[iNewY][iNewX] == cValue)
			{
				q.push({ iNewY,iNewX });
				bVisted[iNewY][iNewX] = true;
			}


		}
	}
}


int main()
{
	cin >> N ;

	string str;

	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		for (int j = 0; j < N; ++j)
		{
			arr[i][j] = str[j];
		}
	}


	int iNormalCnt = 0;
	int iIrregularCnt = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!bVisted[i][j])
			{
				if (arr[i][j] == 'R' || arr[i][j] == 'G' || arr[i][j] == 'B')
				{
					bfs(i, j);
					++iNormalCnt;
				}
			}
		}
	}

	memset(&bVisted, false, sizeof(bVisted));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[i][j] == 'G')
				arr[i][j] = 'R';
		}
	}


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!bVisted[i][j])
			{
				if (arr[i][j] == 'R' || arr[i][j] == 'B')
				{
					bfs(i, j);
					++iIrregularCnt;
				}
			}
		}
	}

	cout << iNormalCnt <<" "<<iIrregularCnt  << "\n";

}