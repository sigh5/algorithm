      #include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <assert.h>
using namespace std;

#define MAX 100001

int iPath[MAX] = { 0, };
bool bVisted[MAX] = { false, };

int iSubin=0, iBro = 0;
enum class DIR { DIR_LEFT, DIR_RIGHT, DIR_TELEPORT, DIR_END};


int iDir(int iDir,int iStart)
{
	DIR eDir = (DIR)iDir;

	switch (eDir)
	{
	case DIR::DIR_LEFT:
		return iStart - 1;
	case DIR::DIR_RIGHT:
		return iStart + 1;
	case DIR::DIR_TELEPORT:
		return iStart * 2;
	default:
		break;
	}
	return 0;
}


void bfs(int iStart)
{
	queue<int> q;
	q.push(iStart);
	bVisted[iStart] = true;
	while (!q.empty())
	{
		int iCurrentPos = q.front();
		q.pop();


		for (int i = 0; i < 3; ++i)
		{
			int iNewPos = iDir(i, iCurrentPos);

			if (!bVisted[iNewPos] && iNewPos >= 0 && iNewPos < MAX)
			{
				bVisted[iNewPos] = true;
				q.push(iNewPos);
				iPath[iNewPos] = iPath[iCurrentPos] + 1;
			}
		}
		
	}
}


int main()
{
	cin >> iSubin >> iBro;
	bfs(iSubin);

	cout << iPath[iBro];
	return 0;
}


