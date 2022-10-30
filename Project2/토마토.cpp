#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

#define MAX 100

int		iGraph[MAX][MAX][MAX];
bool	bVisted[MAX][MAX][MAX];

int M, N, H;
queue< pair< pair< int, int>, int>> que;

int dir[6][3] =
{
	{1,0,0},
	{0,1,0},
	{-1,0,0},
	{0,-1,0},
	{0,0,1},
	{0,0,-1}
};



void bfs()
{

}


int main()
{
	cin >> M >> N >> H;
	int num = 0;

	for (int t = 0; t < H; ++t)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> num;
				iGraph[t][i][j] = num;

				if (num == 1)
				{
					que.push({ make_pair(i,j),t });
				}					
			}
		}

	}

	
	



}