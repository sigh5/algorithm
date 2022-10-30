#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <memory>

using namespace std;

#define MAX_N 10000
#define MAX_M MAX_N*(MAX_N-1)/2


int N, M;

vector<int> vecGraph[MAX_N];
bool bVisted[MAX_N][MAX_N];
queue<pair<int, int>> q;

int iCount = 0;

void bfs(int iStartY, int iStartX)
{
	bVisted[iStartY][iStartX] = true;
	
	q.push({ iStartY, iStartX });

	while (!q.empty())
	{
		int iCurX = q.front().second;
		int iCurY = q.front().first;

		q.pop();


		if (vecGraph[iCurY][iCurX] != 0 && !bVisted[iCurY][iCurX])
		{
			q.push({ iCurY,iCurX });
			bVisted[iCurY][iCurX] = true;
			vecGraph[iCurY][iCurX] = 0;
			vecGraph[iCurX][iCurY] = 0;
		}
	}


}



int main()
{	
	int a = 0, b = 0;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;

		vecGraph[a].push_back(b);
		vecGraph[b].push_back(a);
	}

	for (int i = 0; i < N; ++i)
	{
		int vecSize = vecGraph[i].size();
		
		for (int j = 0; j < vecSize; ++j)
		{
			if (!bVisted[i][j] && vecGraph[i][j] != 0)
			{
				bfs(i, j);
				iCount++;
			}
		}
	}

	cout << iCount;


}
