#include <iostream>
#include <string>
#include<vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

#define MAX_N 12

enum OPERATOR {ADD, SUB , MUL, DIV ,END};
std::array<int, OPERATOR::END> OperArr;
std::array<int, MAX_N> arr;

int N = 0;

int iMaxResult = -100'000'0100;
int iMinResult =  100'000'0100;

void dfs(int iStartIdx, int iResult)
{
	if (iStartIdx >= N)
	{
		iMaxResult = max(iResult, iMaxResult);
		iMinResult = min(iResult, iMinResult);
		return;
	}


	for (int i = 0; i < 4; ++i)
	{
		if (OperArr[i] > 0)
		{

			--OperArr[i];
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
			{
				
					dfs(iStartIdx + 1, int(iResult / arr[iStartIdx]));
			
				
			}
			++OperArr[i];

		}
	}


}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> OperArr[i];
	}

	dfs(1, arr[0]);

	cout << iMaxResult << "\n";
	cout << iMinResult << "\n";
}