#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX		1000

int		iTomato[MAX][MAX];
//int		iCheck[MAX][MAX];

bool	bVisited[MAX][MAX] = { false, };


int N, M;		// N 세로 M 가로
//int iCount=1;

int iMAX = 1;

int xDir[4] = { 0,0,-1,1 };
int yDir[4] = { -1,1,0,0 };

queue<pair<int, int>> q;


void bfs()
{
	while (!q.empty())
	{
		int iCurY = q.front().first;
		int iCurX = q.front().second;
		bVisited[iCurY][iCurX] = true;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNextY = iCurY + yDir[i];
			int iNextX = iCurX + xDir[i];
		
			if (0 <= iNextX && M > iNextX &&
				0 <= iNextY && N > iNextY &&
				iTomato[iNextY][iNextX] == 0 &&
				!bVisited[iNextY][iNextX])
			{
				q.push({ iNextY,iNextX });
				iTomato[iNextY][iNextX] = iTomato[iCurY][iCurX]+ 1;
				iMAX = iTomato[iNextY][iNextX];
			}

		}



	}
}



int main()
{
	cin >> M >> N;

	int iNumber = 0;


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> iNumber;
			iTomato[i][j] = iNumber;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			// 갈수 있을때
			if (iTomato[i][j] == 1 && !bVisited[i][j])
			{
				q.push({ i, j });
			}
			
		}
	}

	bfs();
	
		
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (iTomato[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	
	
	cout << iMAX - 1 << endl;

	return 0;
	


}