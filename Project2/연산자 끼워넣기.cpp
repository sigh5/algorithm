#include <iostream>
#include <string>
#include<vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_N 12

enum CALCULATION {ADD , SUB , MUL, DIV , END};
std::array<int, CALCULATION::END> Calnum_Arr;

int N = 0;
std::array<int, MAX_N> arr{ 0 };

int iminResult = 100'000'001;
int imaxResult = -100'000'001;

void dfs(int iStartIdx, int iResult)
{
	if (iStartIdx == N)
	{
		iminResult = min(iResult, iminResult);
		imaxResult = max(iResult, imaxResult);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (Calnum_Arr[i] > 0)
		{
			--Calnum_Arr[i];

			if (i == ADD)
			{
				dfs(iStartIdx + 1, iResult + arr[iStartIdx]);
			}
			else if (i == SUB)
			{
				dfs(iStartIdx + 1, iResult - arr[iStartIdx]);
			}
			else if (i == MUL)
			{
				dfs(iStartIdx + 1, iResult * arr[iStartIdx]);
			}
			else
				dfs(iStartIdx + 1, int(iResult / arr[iStartIdx]));

			++Calnum_Arr[i];	// 종료조건이 연산자의 개수가아니니까

		}

	}


}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	for (int i = 0; i < 4; ++i)
	{
		cin >> Calnum_Arr[i];
	}

	dfs(1, arr[0]);
	
	cout << imaxResult << "\n";
	cout << iminResult << "\n";
	return 0;
}