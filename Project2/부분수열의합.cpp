#include <iostream>
#include <string>
#include<vector>
#include <array>

using namespace std;

#define MAX_N 21

int N = 0, S = 0, iCount=0;


array<int, MAX_N> arr;



void dfs(int iStartIdx,int iSum)
{
	if (iStartIdx == N )
		return;
	
	if(S==iSum + arr[iStartIdx])
		++iCount;

	dfs(iStartIdx + 1, iSum);
	dfs(iStartIdx + 1, iSum + arr[iStartIdx]);
}

int main()
{
	cin >> N >> S;

	// 전체 부분수열의 개수 2^n -1

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	
	dfs(0, 0);
		
	

	cout << iCount << "\n";


	return 0;
}
