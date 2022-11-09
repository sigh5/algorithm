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

int M = 0, N = 0, H = 0;

array<array<array<int, MAX>, MAX>,MAX> arr;
array<array<array<bool, MAX>, MAX>, MAX> bVisted;

array<array<array<int, MAX>, MAX>, MAX> dateValue;

struct BoxData
{
	int iHeight;
	int iY = 0;
	int iX = 0;
};

vector<BoxData> boxVec;

array<int, 2> HDir = {-1,1};
array<int, 4> YDir = {-1,1,0,0};
array<int, 4> XDir = {0,0,-1,1};

int iCount = 0;

queue<BoxData> q;


void bfs()
{
	
	BoxData data;
	memset(&data, 0, sizeof(data));

	while (!q.empty())
	{
		int iCurrentHeight = q.front().iHeight;
		int iCurrentY = q.front().iY;
		int iCurrentX = q.front().iX;

		q.pop();

		for (int i = 0; i < 2; ++i)
		{
			int iNewHeight =iCurrentHeight + HDir[i];

			if (0 <= iCurrentY && iCurrentY < N &&
				0 <= iCurrentX && iCurrentX < M &&
				0<= iNewHeight && iNewHeight <H &&
 				!bVisted[iNewHeight][iCurrentY][iCurrentX]
				&& arr[iNewHeight][iCurrentY][iCurrentX] == 0)
			{
				memset(&data, 0, sizeof(data));
				data.iHeight = iNewHeight;
				data.iY = iCurrentY;
				data.iX = iCurrentX;
				arr[iNewHeight][iCurrentY][iCurrentX] = 1;
				bVisted[iNewHeight][iCurrentY][iCurrentX] = true;
				dateValue[iNewHeight][iCurrentY][iCurrentX] = dateValue[iCurrentHeight][iCurrentY][iCurrentX] + 1;
				q.push(data);
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int iNewY = iCurrentY + YDir[i];
			int iNewX = iCurrentX + XDir[i];

			if (0 <= iNewY && iNewY < N &&
				0 <= iNewX && iNewX < M &&
				0 <= iCurrentHeight && iCurrentHeight < H &&
				!bVisted[iCurrentHeight][iNewY][iNewX]
				&& arr[iCurrentHeight][iNewY][iNewX] == 0)
			{
				memset(&data, 0, sizeof(data));
				data.iHeight = iCurrentHeight;
				data.iY = iNewY;
				data.iX = iNewX;
				arr[iCurrentHeight][iNewY][iNewX] = 1;
				bVisted[iCurrentHeight][iNewY][iNewX] = true;
				dateValue[iCurrentHeight][iNewY][iNewX] = dateValue[iCurrentHeight][iCurrentY][iCurrentX] + 1;
				q.push(data);
			}
		}
	}

}


int main()
{
	cin >> M >> N >> H;

	memset(&bVisted, false, sizeof(bVisted));

	int iNum = 0;
	BoxData data;
	memset(&data, 0, sizeof(data));
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int q = 0; q < M; ++q)
			{
				cin >> iNum; 
				arr[i][j][q] = iNum;
				if (iNum == 1)
				{
					data.iHeight = i;
					data.iY = j;
					data.iX = q;
					boxVec.push_back( data );
					dateValue[i][j][q] = 1;
				}

				if (iNum == -1)
				{
					dateValue[i][j][q] = -1;
				}
			}
		}
	}



	for (auto iter : boxVec)
	{	
		q.push(iter);
	}
	
	bfs();

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{	
			sort(dateValue[i][j].begin(), dateValue[i][j].begin() + M, [&](int a, int b)->bool
			{
				return a > b;
			});
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int q = 0; q < M; ++q)
			{
				if (dateValue[i][j][q] == 0)
				{

					cout << -1 << endl;
					return 0;
				}
			}
		}
	}


	int iMax = 0;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			iMax = max(dateValue[i][j][0], iMax);
		}
	}
	
	cout << iMax-1;


}