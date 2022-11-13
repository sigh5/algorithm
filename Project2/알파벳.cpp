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

#define MAX		26

int R = 0, C = 0, iResult = 0;
//
array<array<char, MAX>, MAX> arr;
//array<array<bool, MAX>, MAX> bVisted = {false, };


array<bool, MAX> bVisted;

array<int, 4> YDir = { -1,1,0,0 };
array<int, 4> XDir = { 0,0,-1,1 };

vector<char> vecAlphabet;

void dfs(int iStartY,int iStartX, int Cnt )
{
	iResult = max(iResult, Cnt);

	for (int i = 0; i < 4; ++i)
	{
		int iNewY = YDir[i] + iStartY;
		int iNewX = XDir[i] + iStartX;

		if (0 <= iNewX && iNewX < C && 0 <= iNewY && iNewY < R)
		{
			if (!bVisted[arr[iNewY][iNewX] - 'A'])
			{
				bVisted[arr[iNewY][iNewX] - 'A'] = true;
				dfs(iNewY, iNewX, Cnt + 1);
				bVisted[arr[iNewY][iNewX] - 'A'] = false;
			}
		}
	}

}



int main()
{
	
	cin >> R >> C;

	char cAlpahbet;
	vecAlphabet.reserve(26);

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> cAlpahbet;
			arr[i][j] = cAlpahbet;
		}
	}

	bVisted[arr[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << iResult;
}