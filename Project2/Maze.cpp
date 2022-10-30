#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 101

int iMaze[MAX][MAX];
int dist[MAX][MAX];
bool bVisited[MAX][MAX];

int xDir[4] = { 0,0,-1,1 };
int yDir[4] = { -1,1,0,0 };

int N, M;

int iCount = 0;

void bfs(int iStartY,int iStartX)
{
	queue<pair<int, int>> q;
	bVisited[iStartY][iStartX] = true;
	dist[iStartY][iStartX]++;
	q.push({ iStartY,iStartX });

	while (!q.empty())
	{
		int iFrontY = q.front().first;
		int iFrontX = q.front().second;
		
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNextY = iFrontY + yDir[i];
			int iNextX = iFrontX + xDir[i];

			if ((0 <= iNextY && N >= iNextY) &&
				(0 <= iNextX && M >= iNextX) &&
				1 == iMaze[iNextY][iNextX] &&
				!bVisited[iNextY][iNextX])
			{
				bVisited[iNextY][iNextX] = true;
				q.push({ iNextY,iNextX });
				dist[iNextY][iNextX] = dist[iFrontY][iFrontX] + 1;
			}


		}



	}






}



int main()
{
	string str;
	cin >> N >> M;


	for (int i = 0; i < N; ++i)
	{
		cin >> str;

		for (int j = 0; j < M; ++j)
		{
			iMaze[i][j] = str[j] - '0';
		}
	}


	bfs(0, 0);

	cout << dist[N-1][M-1]<<'\n';

}