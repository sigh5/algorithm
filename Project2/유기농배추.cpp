#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <memory>

using namespace std;

#define MAX 2500

int xDir[4] = { 0,0,-1,1 };
int yDir[4] = { -1,1,0,0 };

int iMaze[MAX][MAX];
//int iTotalNum[MAX*MAX];

bool bVisted[MAX][MAX];

int T;
int M, N;
int iCount = 0;

void Dfs(int iStartY, int iStartX)
{
	if (bVisted[iStartY][iStartX])
		return;

	bVisted[iStartY][iStartX] = true;
	//++iTotalNum[iCount];

	for (int i = 0; i < 4; ++i)
	{
		int iNextY = yDir[i] + iStartY;
		int iNextX = xDir[i] + iStartX;


		if ((0 <= iNextX && M >= iNextX) &&
			(0 <= iNextY && N >= iNextY) &&
			!bVisted[iNextY][iNextX] &&
			iMaze[iNextY][iNextX] != 0)
		{
			Dfs(iNextY, iNextX);

		}




	}





}



int main()
{
	int K;

	cin >> T;
	

	int im = 0, in = 0;

	for (int j = 0; j < T; ++j)
	{
		cin >> M >> N >> K;

		for (int i = 0; i < K; ++i)
		{
			cin >> im >> in;

			iMaze[in][im] = 1;
		}


		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (iMaze[i][j] == 1 && !bVisted[i][j])
				{
					++iCount;
					Dfs(i, j);
				}
			}
		}

		cout << iCount <<endl;


		memset(bVisted, false, sizeof(bVisted));
		memset(iMaze, 0, sizeof(iMaze));
		iCount = 0;

	}







}
