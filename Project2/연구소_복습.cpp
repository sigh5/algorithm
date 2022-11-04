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

#define MAX 9

int iWidth = 0, iHeight = 0;

array<array<int, MAX> ,MAX> iMaze = { 0 };
array<array<int, MAX>, MAX> iCopyMaze = { 0 };

queue<pair<int, int>> q;
int iCount = 0;

array <int, 4> iDirY = { -1,1,0,0 };
array <int, 4> iDirX = { 0,0,-1,1 };

/* BackTracking : 해를 찾는 도중 해가 아니어서
			막히면 다시 돌아가서 찾는 기법 최적화 필수
	
	DFS는 백트래킹 기법을 사용하지 못한다.
	(가능한 모든 경로 후보를 탐색하므로)
*/

void bfs()
{
	queue <pair<int, int>> copyQ;	
	copyQ = q;

	array<array<int, MAX>, MAX> iSpreadMaze;
	memcpy(&iSpreadMaze,&iCopyMaze,sizeof(iCopyMaze));

	while (!copyQ.empty())
	{
		int iCurrentY = copyQ.front().first;
		int iCurrentX = copyQ.front().second;
		copyQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNewY = iCurrentY + iDirY[i];
			int iNewX = iCurrentX + iDirX[i];

			if (0 <= iNewY && iNewY < iHeight &&
				0 <= iNewX && iNewX < iWidth &&
				iSpreadMaze[iNewY][iNewX] == 0)
			{
				iSpreadMaze[iNewY][iNewX] = 2;
				copyQ.push({ iNewY,iNewX });
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < iHeight; ++i)
	{
		for (int j = 0; j < iWidth; ++j)
		{
			if (iSpreadMaze[i][j] == 0)
			{
				++cnt;
			}
		}
	}

	iCount = max(cnt, iCount);

}

void Wall(int cnt)
{
	if (cnt == 3)
	{
		bfs();
		return;
	}

	for (int i = 0; i < iHeight; ++i)
	{
		for (int j = 0; j < iWidth; ++j)
		{
			if (iCopyMaze[i][j] == 0)
			{
				iCopyMaze[i][j] = 1;
				Wall(cnt + 1);
				iCopyMaze[i][j] = 0;
			}
		}
	}

}


int main()
{
	cin >> iHeight >> iWidth;
	int iMazeValue = 0;

	for (int i = 0; i < iHeight; ++i)
	{
		for (int j = 0; j < iWidth; ++j)
		{
			cin >> iMazeValue;
			iMaze[i][j] = iMazeValue;

			if (iMazeValue == 2)
			{
				q.push({ i,j });
			}
		}
	}

	for (int i = 0; i < iHeight; ++i)
	{
		for (int j = 0; j < iWidth; ++j)
		{
			if (iMaze[i][j] == 0)
			{
				memcpy(&iCopyMaze, &iMaze, sizeof(iMaze));
				iCopyMaze[i][j] = 1;
				Wall(1);
				iCopyMaze[i][j] = 0;
			}
		}
	}


	cout << iCount << endl;

}
