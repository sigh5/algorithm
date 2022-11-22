#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <memory.h>
#include <array>

using namespace std;

#define MAX 101
#define INF 99999999

// 모든정점에서 모든정점의 최소값을 구할때? 
// 플로이드 위셜 알고리즘을 사용한다.

array<array<int, MAX>, MAX> arr;

int iCity = 0, iBus = 0;

void Solve()
{
	array<array<int, MAX>, MAX> iDist;
	iDist = arr;

	// k= 거쳐가는 정점
	for (int k = 1; k <= iCity; ++k)
	{
		for (int i = 1; i <= iCity; ++i)
		{
			for (int j = 1; j <= iCity; ++j)
			{
				if (iDist[k][j] + iDist[i][k] < iDist[i][j])
				{
					iDist[i][j] = iDist[k][j] + iDist[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= iCity; ++i)
	{
		for (int j = 1; j <= iCity; ++j)
		{
			if (INF == iDist[i][j])
				cout << 0 << " ";
			else
				cout << iDist[i][j] << " ";
		
		}
		puts("");
	}

}


int main()
{
	cin >> iCity >> iBus;

	for (int i = 1; i <= iCity; ++i)
	{
		for (int j = 1; j <= iCity; ++j)
		{
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}
	}
	int iStartCity = 0, iEndCity = 0, iWeight = 0;

	for (int i = 0; i < iBus; ++i)
	{
		cin >> iStartCity >> iEndCity >> iWeight;
		
		if(arr[iStartCity][iEndCity] < iWeight)
			continue;

		arr[iStartCity][iEndCity] = iWeight;
	}

	Solve();


}
