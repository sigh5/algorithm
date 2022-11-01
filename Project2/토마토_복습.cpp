#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
#include <stack>
#include <assert.h>

using namespace std;

#define MAX 1000

int M = 0, N = 0;

vector<int> arrVec[MAX];
vector<int> distArr[MAX];

array<bool, MAX> bVisited[MAX] = { false, };

array<int, 4>	XDir = { 0,0,-1,1 };
array<int, 4>	YDir = { -1,1,0,0 };

queue<pair<int, int>> q;


void bfs(int Y, int X)
{
	bVisited[Y][X] = true;
	

	while (!q.empty())
	{
		int iCurrentY = q.front().first;
		int iCurrentX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNewY = iCurrentY + YDir[i];
			int iNewX = iCurrentX + XDir[i];

			if (0 <= iNewY && N > iNewY &&
				0 <= iNewX && M > iNewX &&
				!bVisited[iNewY][iNewX] && arrVec[iNewY][iNewX] == 0)
			{
				bVisited[iNewY][iNewX] = true;
				q.push({ iNewY,iNewX });
				distArr[iNewY][iNewX] = distArr[iCurrentY][iCurrentX] + 1;
			}
			
			
			
		}


	}
}

int main()
{
	cin >> M >> N;

	int iHaveTomato = 0;

	for (int i = 0; i < N; ++i)
	{
		distArr[i].resize(M);

		for (int j = 0; j < M; ++j)
		{
			cin >> iHaveTomato;
			arrVec[i].push_back(iHaveTomato);

			if (arrVec[i][j] == 1)
			{
				q.push({ i,j });
				distArr[i][j] = 1;
			}

			if (arrVec[i][j] == -1)
			{
				distArr[i][j] = -1;
			}

		}
	}




	int iCurrentY = q.front().first;
	int iCurrentX = q.front().second;

	bfs(iCurrentY, iCurrentX);



	for (int i = 0; i < N; ++i)
	{
		sort(distArr[i].begin(), distArr[i].end(), [&](int a, int b)->bool
		{
			return a > b;
		});

		auto iter = find_if(distArr[i].begin(), distArr[i].end(), [&](int a)->bool
		{
			return a == 0;
		});

		if (iter != distArr[i].end())
		{
			cout << -1 << endl;
			return 0;
		}


	}


	vector<int> a;

	for (int i = 0; i < N; ++i)
	{
		a.push_back(distArr[i][0]);
	}

	sort(a.begin(), a.end(), [&](int a, int b)->bool
	{
		return a > b;
	});


	cout << a[0]-1 << endl;
}
