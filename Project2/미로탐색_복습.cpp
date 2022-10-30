#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define MAX 101


int		iMaze[MAX][MAX];
int		iDist[MAX][MAX];
bool	bVistied[MAX][MAX] = { false, };

int N = 0, M = 0;

int		iYDir[4] = { -1,1,0,0 };
int		iXDir[4] = { 0,0,-1,1 };



void bfs(int iStartX, int iStartY)
{
	queue<pair<int, int>> q;
	q.push({ iStartY,iStartX });
	bVistied[iStartY][iStartX] = true;
	++iDist[iStartY][iStartX];
	while (!q.empty())
	{
		int iCurrentX = q.front().second;
		int iCurrentY = q.front().first;
		q.pop();
		

		if (iCurrentX == M-1 && iCurrentY == N-1)
			break;

		for (int i = 0; i < 4; ++i)
		{
			int iNewX = iCurrentX + iXDir[i];
			int iNewY = iCurrentY + iYDir[i];

			if (0 <= iNewX && M > iNewX &&
				0 <= iNewY && N > iNewY &&
				!bVistied[iNewY][iNewX] &&
				iMaze[iNewY][iNewX] == 1)
			{
				q.push({ iNewY,iNewX });
				bVistied[iNewY][iNewX] = true;
				iDist[iNewY][iNewX] = iDist[iCurrentY][iCurrentX] + 1;
			}

		}


	}


}



int main()
{
	cin >> N >> M;
	
	string str;


	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		for (int j = 0; j < M; ++j)
		{
			iMaze[i][j] = str[j] - '0';
		}
	}

	bfs(0, 0);

	cout << iDist[N - 1][M - 1] << endl;

}



// 이거 한문제 , DP 한문제 