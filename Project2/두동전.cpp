#include <iostream>
#include <string>
#include<vector>
#include <array>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define MAX_NUM 21

// ºóÄ­ 0 µ¿ÀüÀÇ À§Ä¡ 1 º® 2
array<array<int, MAX_NUM>, MAX_NUM> iMaze{ 0 };

enum  Dir {UP,DOWN,LEFT,RIGHT, END};

array<int, 4> yDir = { -1,1,0,0 }; //»ó ÇÏ ÁÂ ¿ì
array<int, 4> XDir = { 0,0,-1,1 };

int N = 0, M = 0;
vector<pair<int, int>> CoinPos;
int iMin_Result = 11;



bool Cal_Range(int a, int b)
{
	if (a < 0 || b < 0 || a >= N || b >= M)
		return true;

	return false;
}


void dfs(int iCoin0_PosY, int iCoin0_PosX,
	int iCoin1_PosY, int iCoin1_PosX, int iCount,int dir)
{
	if (iMin_Result < iCount)
		return;

	if (iCount > 10)
	{
		iMin_Result = min(iCount, iMin_Result);
		return;
	}
	
	int iNewCoin0_Ypos = iCoin0_PosY + yDir[(dir)];
	int iNewCoin0_Xpos = iCoin0_PosX + XDir[(dir)];
	
	int iNewCoin1_Ypos = iCoin1_PosY + yDir[(dir)];
	int iNewCoin1_Xpos = iCoin1_PosX + XDir[(dir)];


	if (Cal_Range(iNewCoin0_Ypos, iNewCoin0_Xpos) &&
		Cal_Range(iNewCoin1_Ypos, iNewCoin1_Xpos))
	{
		return;
	}
	else if (Cal_Range(iNewCoin0_Ypos, iNewCoin0_Xpos) == true &&
		Cal_Range(iNewCoin1_Ypos, iNewCoin1_Xpos) == false)
	{
		iMin_Result = min(iCount, iMin_Result);
		return;
	}
	else if (Cal_Range(iNewCoin0_Ypos, iNewCoin0_Xpos) == false &&
		Cal_Range(iNewCoin1_Ypos, iNewCoin1_Xpos) == true)
	{
		iMin_Result = min(iCount, iMin_Result);
		return;
	}

	if (iMaze[iNewCoin0_Ypos][iNewCoin0_Xpos] == 2)
	{
		iNewCoin0_Ypos = iCoin0_PosY;
		iNewCoin0_Xpos = iCoin0_PosX;
	}
	
	if(iMaze[iNewCoin1_Ypos][iNewCoin1_Xpos] == 2)
	{
		iNewCoin1_Ypos = iCoin1_PosY;
		iNewCoin1_Xpos = iCoin1_PosX;

	}
	
	for (int i = 0; i < 4; ++i)
	{
		dfs(iNewCoin0_Ypos, iNewCoin0_Xpos, 
			iNewCoin1_Ypos, iNewCoin1_Xpos,
			iCount + 1, i);

	}



}


int main()
{
	cin >> N >> M;

	char szButton = ' ';

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> szButton;

			if (szButton == 'o')
			{
				CoinPos.push_back({ i,j });
			}
			else if (szButton == '#')
			{
				iMaze[i][j] = 2;
			}
			else
				continue;

		}
	}

	size_t CoinPosSize = CoinPos.size();

	if (CoinPosSize == 0)
		return 0;
	
	for (int i = 0; i < 4; ++i)
	{
		dfs(CoinPos[0].first, CoinPos[0].second,
			CoinPos[1].first, CoinPos[1].second, 1, (i));
	}
	
	
	if (iMin_Result > 10)
		cout << -1;
	else
		cout << iMin_Result;

	return 0;
}

