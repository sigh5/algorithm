#include <iostream>
#include <string>
#include<vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_NUM 501


int N=0, M = 0;

array<array<int, MAX_NUM>, MAX_NUM> arr;
array<array<bool, MAX_NUM>, MAX_NUM> bVisted;



array<int, 4 > yDir{ -1,1,0,0 };
array<int, 4 > XDir{ 0,0,-1,1 };

int iMax = -100;

void dfs(int iCurY ,int iCurX , int iSum, int iDepth)
{
	if (iDepth == 4)
	{
		iMax = max(iSum, iMax);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int iNewY = yDir[i] + iCurY;
		int iNewX = XDir[i] + iCurX;
		
		if (0 > iNewY || N < iNewY ||
			0 > iNewX || M < iNewX)
			continue;
		if (bVisted[iNewY][iNewX])
			continue;

		bVisted[iNewY][iNewX] = true;
		dfs(iNewY,iNewX,iSum + arr[iNewY][iNewX], iDepth + 1);
	}	

	if(iCurX - 1 >= 1  && iCurY - 1 >= 1 && iCurY +1 <= N)  // っ
		iMax = max(iMax, arr[iCurY][iCurX-1] + arr[iCurY][iCurX ] + arr[iCurY-1][iCurX] + arr[iCurY +1][iCurX ] ) ;
	if(iCurX + 1 <= M && iCurY - 1 >= 1 && iCurY + 1 <= N)  // た
		iMax = max(iMax, arr[iCurY][iCurX + 1] + arr[iCurY][iCurX] + arr[iCurY - 1][iCurX] + arr[iCurY + 1][iCurX]);
	if (iCurX + 1 <=M && iCurY - 1  >=1 && iCurX - 1 >=1)  // で
		iMax = max(iMax, arr[iCurY][iCurX + 1] + arr[iCurY][iCurX] + arr[iCurY - 1][iCurX] + arr[iCurY ][iCurX-1]);
	if (iCurX + 1 <=M && iCurY + 1 <=N  && iCurX - 1 >=1)  // ぬ
		iMax = max(iMax, arr[iCurY][iCurX + 1] + arr[iCurY][iCurX] + arr[iCurY + 1][iCurX] + arr[iCurY][iCurX - 1]);
}



int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; ++j)
		{
			dfs(i, j, arr[i][j], 0);
			
			bVisted.fill({ false });
		}
	}
	
	

	cout << iMax << "\n";

	return 0;
}
