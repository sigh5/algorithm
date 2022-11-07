#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <array>
#include <memory.h>

#pragma warning(disable : 4996)

using namespace std;

#define  MAX 51

int iWidth = 0, iHeight = 0;

array<array<int,MAX>,MAX> arr;
bool bVisted[MAX][MAX];


array<int, 8> iYDir = { -1,-1,-1,0,1,1,1,0 };
array<int, 8> iXDir = { -1,0,1,1,1,0,-1,-1 };

vector<pair<int, int>> vec;

void bfs(int iStartY, int iStartX)
{
	queue<pair<int, int>> q;
	q.push({ iStartY,iStartX });
	bVisted[iStartY][iStartX] = true;

	while (!q.empty())
	{
		int iCurrentY = q.front().first;
		int iCurrentX = q.front().second;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int NewY = iCurrentY + iYDir[i];
			int NewX = iCurrentX + iXDir[i];

			if (0 <= NewX && NewX < iWidth &&
				0 <= NewY && NewY < iHeight &&
				!bVisted[NewY][NewX] && arr[NewY][NewX]==1)
			{
				q.push({ NewY,NewX });
				vec.push_back({ NewY,NewX });
				bVisted[NewY][NewX] = true;
			}
		}
	}

}

int main()
{
	int iInputX=0, iInputH = 0;

	while (true)
	{
		int iCount = 0;
		cin >> iWidth >> iHeight;

		if (iWidth == 0 && iHeight == 0)
			break;
		
		for (int i = 0; i < iHeight; i++)
		{
			for (int j = 0; j < iWidth; ++j)
			{
				int iNum = 0;
				cin >> iNum;
				arr[i][j] = iNum;
			}
		}

		for (int i = 0; i < iHeight; ++i)
		{
			for (int j = 0; j < iWidth; ++j)
			{
				if (!bVisted[i][j] && arr[i][j]==1)
				{
					bfs(i, j);
					++iCount;
				}
				
			}
		}

		
		cout <<iCount << "\n";

		memset(&arr, 0, sizeof(arr));
		memset(&bVisted, 0, sizeof(bVisted));
	}

}

