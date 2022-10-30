#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define MAX 25

int N;
int iAprat[MAX][MAX];
int iApartTotalNum[MAX*MAX];

bool bVistied[MAX][MAX] = { false, };

int iCount = 0;

int xDir[4] = { 0,0,-1,1 };
int yDir[4] = { -1,1,0,0 };


void Dfs(int iStartY, int iStartX)
{
	if (bVistied[iStartY][iStartX])
		return;
	
	bVistied[iStartY][iStartX] = true;
	++iApartTotalNum[iCount];
	
	for (int i = 0; i < 4; ++i)
	{
		int newX = iStartX + xDir[i];
		int newY = iStartY + yDir[i];

		if (0 <= newX && N > newX &&
			0 <= newY && N > newY &&
			!bVistied[newY][newX] &&
			iAprat[newY][newX] != 0)
		{
			Dfs(newY, newX);
		}

	}




}



int main()
{
	cin >> N;

	string s;

	for (int i = 0; i < N; ++i)
	{
		cin >> s;

		for (int j = 0; j < N; ++j)
		{
			iAprat[i][j] = int(s[j] - '0');
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (iAprat[i][j] == 1 && !bVistied[i][j])
			{
				++iCount;
				Dfs(i, j);
			}
		}
	}

	sort(iApartTotalNum +1, iApartTotalNum+iCount+1);

	cout << iCount << endl;

	

	for (int i = 1; i <= iCount; ++i)
	{
		cout << iApartTotalNum[i] << endl;
	}
	
}
