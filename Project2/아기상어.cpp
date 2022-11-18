#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <array>
#include <memory.h>
using namespace std;

#define MAX 21

array<array<int, MAX >, MAX >arr;
array<array<int, MAX >, MAX >iDist;


array<int, 4> XDir = { 0,0,-1,1 };
array<int, 4> YDir = { -1,1,0,0 };


int N = 0;
int iSharkScale = 2;

int iEatFish = 0;
int iSharkPosY = 0, iSharkPosX = 0;
int iCount = 0;
int bfs(int iStartY, int iStartX)
{
	
	
	while (1)
	{
		memset(&iDist, -1, sizeof(iDist));

		queue<pair<int, int>> q;
		q.push({ iSharkPosY,iSharkPosX });

		arr[iSharkPosY][iSharkPosX] = 0;
		iDist[iSharkPosY][iSharkPosX] = 0;

		vector<pair<int, int>> fishvec;

		if (iEatFish >= iSharkScale)
		{
			iEatFish -= iSharkScale;
			++iSharkScale;
		}

		while (!q.empty())
		{
			int iCurY = q.front().first;
			int iCurX = q.front().second;
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int newY = iCurY + YDir[i];
				int newX = iCurX + XDir[i];

				if (0 > newY || newY >= N || 0 > newX || newX >= N)
					continue;

				if (iDist[newY][newX] != -1) continue;;
				if (arr[newY][newX] > iSharkScale) continue;

				else if (arr[newY][newX] < iSharkScale && arr[newY][newX] >= 1)
				{
					fishvec.push_back({ newY,newX });
					
				}
				iDist[newY][newX] = iDist[iCurY][iCurX] + 1;
				q.push({ newY,newX });
			}
		}
		if (fishvec.size() == 0)
		{
			cout << iCount;
			return 0;
		}
		else if (fishvec.size() == 1)
		{
			iSharkPosY = fishvec[0].first;
			iSharkPosX = fishvec[0].second;
			arr[iSharkPosY][iSharkPosX] = 0;
			iEatFish++;
			iCount += iDist[iSharkPosY][iSharkPosX];
		}
		else
		{
			int minDist = 100000;
			for (auto &x : fishvec)
				minDist = min(minDist, iDist[x.first][x.second]);

			int mincnt = 0;
			vector<pair<int, int>> minfish;

			for (auto& x : fishvec)
			{
				if (minDist == iDist[x.first][x.second])
					minfish.push_back({ x.first,x.second });
			}

			sort(minfish.begin(), minfish.end());
			iSharkPosY = minfish[0].first;
			iSharkPosX = minfish[0].second;
			iCount += iDist[iSharkPosY][iSharkPosX];
			arr[iSharkPosY][iSharkPosX] = 0;
			++iEatFish;

		}
		

			
		
	}

	

	return iCount;

}




int main()
{
	cin >> N;

	int Num = 0;

	


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Num;
			arr[i][j] = Num;

			if (Num == 9)
			{
				iSharkPosY = i;
				iSharkPosX = j;
			}
		}
	}

	bfs(iSharkPosY, iSharkPosX);

	//cout << iCount;

}
