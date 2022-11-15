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

int N = 0, M = 0;

#define MAX 1000

array<array<int, MAX >, MAX> arr;
bool bVisted[MAX][MAX][2] = { {false,} ,{false,} };

array<int, 4> XDir = { 0,0,-1,1 };
array<int, 4> YDir = { -1,1,0,0 };

int iCount = 0;

void bfs(int iStartY, int iStartX)
{
		// X,Y						// 벽부순 횟수, 최단거리 
	queue<pair<pair<int, int>,pair<int,int>>> q;
	q.push({ {iStartY,iStartX }, {0,1} });
	bVisted[iStartY][iStartX][0] = true;
	

	while (!q.empty())
	{
		int iCurrentY = q.front().first.first;
		int iCurrentX = q.front().first.second;
		
		int iB = q.front().second.first;
		int iCnt = q.front().second.second;
		q.pop();

		if (iCurrentX == M - 1 && iCurrentY == N - 1)
		{
			iCount = iCnt;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int iNewY = iCurrentY + YDir[i];
			int iNewX = iCurrentX + XDir[i];

			if (0 <= iNewY && iNewY < N &&
				0 <= iNewX && iNewX < M)
			{
				if (arr[iNewY][iNewX] == 1 && iB == 0 )	//벽을 처음 부수는 경우 그리고 벽을 부순횟수가 이제 1이되면 못들어옴
				{
					q.push({ {iNewY,iNewX}, {iB + 1 , iCnt + 1} });
					bVisted[iNewY][iNewX][iB+1] = true;
				}
				else if (arr[iNewY][iNewX] == 0 && !bVisted[iNewY][iNewX][iB])
				{
					bVisted[iNewY][iNewX][iB] = true;
					q.push({ { iNewY,iNewX },{ iB  , iCnt + 1 } });
				}
			}

		}
			
	}

	

}


int Solve(int iStartY, int iStartX)
{
	 bfs(iStartY, iStartX);


	 if (iCount == 0)
		 return -1;

	 return iCount;
}


int main()
{
	cin >> N >> M;

	string str;

	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		for (int j = 0; j < str.length(); ++j)
		{

			arr[i][j] = str[j] - '0';
		}
	}

	cout << Solve(0, 0);

}