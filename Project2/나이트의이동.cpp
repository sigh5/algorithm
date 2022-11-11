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

static const int g_iMAX = 301;

int N = 0;

array<array<int, g_iMAX>, g_iMAX > arr;
array<array<int, g_iMAX>, g_iMAX > Distarr = {0,};

array<array<bool, g_iMAX>, g_iMAX > bVisted = {false,};

array<int, 8> YDir = { -2,-2,-1,1,2,2,1,-1 };
array<int, 8> XDir = { -1,1,2,2, 1, -1,-2,-2 };


int iStartY = 0, iStartX = 0;
int iGoalY = 0, iGoalX = 0;



void bfs(int iStartY, int iStartX)
{
	queue<pair<int, int>> q;
	q.push({ iStartY,iStartX });
	bVisted[iStartY][iStartX] = true;

	while (!q.empty())
	{
		int iCurretX = q.front().second;
		int iCurretY = q.front().first;
		q.pop();

		for (int i = 0; i < 8; ++i)
		{
			int iNewY = iCurretY + YDir[i];
			int iNewX = iCurretX + XDir[i];

			if (0 <= iNewX && iNewX < N &&
				0 <= iNewY && iNewY < N &&
				!bVisted[iNewY][iNewX])
			{
				Distarr[iNewY][iNewX] = Distarr[iCurretY][iCurretX] + 1;
				q.push({ iNewY,iNewX });
				bVisted[iNewY][iNewX] = true;
			}

			

		}


	}


}



int iSolve(int iStartY, int iStartX)
{
	bfs(iStartY, iStartX);

	
	return Distarr[iGoalY][iGoalX];

}



int main()
{
	int iTestNum = 0;

	cin >> iTestNum;

	
	while ((iTestNum--) > 0)
	{
		cin >> N;

		cin >> iStartY >> iStartX;
		cin >> iGoalY >> iGoalX;

		cout << iSolve(iStartY, iStartX) << "\n";
	

		memset(&bVisted, false, sizeof(bVisted));
		memset(&arr, false, sizeof(arr));
		memset(&Distarr, false, sizeof(Distarr));

	}

	

}

