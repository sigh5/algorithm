#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <memory.h>
using namespace std;

#define		MAX 51

// dfs bfs �ð� ���⵵�� ������ bfs �� ������ �׷��� �̷�ã�� ���� �ִܰŸ����Ҷ� bfs �� ����.

array<int, MAX> arr[MAX] = { 0, };
array<bool, MAX> bVisted[MAX] = { false, };

array<int, 4> XDir = { 0,0,-1,1 };
array<int, 4> YDir = { -1,1,0,0};
int iWidth = 0, iHeight = 0;

void bfs(int iStartY, int iStartX)
{
	queue<pair<int, int>> q;
	q.push(make_pair(iStartY, iStartX));
	bVisted[iStartY][iStartX] = true;

	while (!q.empty())
	{
		int iCurrentY = q.front().first;
		int iCurrentX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int iNewY = iCurrentY + YDir[i];
			int iNewX = iCurrentX + XDir[i];

			if (iNewX >= 0 && iNewX <= iWidth
				&& iNewY >= 0 && iNewY <= iHeight
				&&!bVisted[iNewY][iNewX] && arr[iNewY][iNewX] == 1)
			{
				q.push({iNewY, iNewX});
				bVisted[iNewY][iNewX] = true;
			}

		}
	}
}



int main()
{
	int T,Num = 0;
	
	cin >> T;

	int iHaveCabbageY = 0, iHaveCabbageX = 0;

	for (int i = 0; i < T; ++i)
	{
		int iBugCount = 0;
		cin >> iWidth >> iHeight >> Num;
		for (int j = 0; j < Num; ++j)
		{
			cin >> iHaveCabbageX >> iHaveCabbageY;
			arr[iHaveCabbageY][iHaveCabbageX] = 1;
			
		}

		for (int q = 0; q < iHeight; ++q)
		{
			for (int k = 0; k < iWidth; ++k)
			{
				if (arr[q][k] == 1 && !bVisted[q][k])
				{
					bfs(q, k);
					++iBugCount;
				}
			}
		}
		
		cout << iBugCount << endl;
		memset(arr, 0, sizeof(arr));
		memset(bVisted, 0, sizeof(bVisted));
	}

	
	


}
