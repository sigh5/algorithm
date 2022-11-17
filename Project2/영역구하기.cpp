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

#define MAX 100

int M = 0, N = 0, K=0;

array<array<int, MAX>, MAX> arr;

array<array<bool, MAX>, MAX> bVisted = { false, };

vector<int> vec;

array<int, 4> iYDir = { -1,1,0,0 };
array<int, 4> iXDir = { 0,0,-1,1 };


void bfs(int iStartY, int iStartX)
{
	int iCnt = 1;
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
			int iNewY = iCurrentY + iYDir[i];
			int iNewX = iCurrentX + iXDir[i];

			if (0 <= iNewX && iNewX < N &&
				0 <= iNewY && iNewY < M &&
				!bVisted[iNewY][iNewX] && arr[iNewY][iNewX] == 0)
			{
				q.push({ iNewY,iNewX });
				bVisted[iNewY][iNewX] = true;
				++iCnt;
			}

		}
	}

	vec.push_back(iCnt);
}



int main()
{
	cin >> M >> N >> K;

	int iLeft=0, ibottom =0, iRight=0, iTop = 0;

	for (int t = 0; t < K; ++t)
	{
		cin >> iLeft >> ibottom >> iRight >> iTop;

		for (int i = ibottom; i < iTop; ++i)
		{
			for (int j = iLeft; j < iRight; ++j)
			{
				arr[i][j] = 1;
			}
		}
	}

	int iCount = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!bVisted[i][j] && arr[i][j] == 0)
			{
				bfs(i, j);
				++iCount;
			}
		}

	}

	sort(vec.begin(), vec.end(), [&](int a, int b)->bool
	{
		return a < b;
	});

	cout << iCount << '\n';
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}

}